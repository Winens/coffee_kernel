EXPORT=disk.hdd
QEMU_FLAGS=-d int -machine q35 -smp 4 -hda $(EXPORT) -debugcon stdio -m 2G -enable-kvm

.PHONY: all
all: $(EXPORT)

limine:
	git clone https://github.com/limine-bootloader/limine.git --branch=v2.0-branch-binary --depth=1
	make -C limine

.PHONY: run
run: $(EXPORT)
	qemu-system-x86_64 $(QEMU_FLAGS)

.PHONY: kernel
kernel:
	$(MAKE) -C kernel

$(EXPORT): limine kernel
	rm -rf build_root/
	mkdir build_root
	dd if=/dev/zero of=$(EXPORT) bs=4M count=128
	parted -s $(EXPORT) mklabel msdos
	parted -s $(EXPORT) mkpart primary 2048s 100%
	sudo losetup -Pf --show $(EXPORT) > loopback_dev
	sudo partprobe `cat loopback_dev`
	sudo mkfs.ext2 `cat loopback_dev`p1
	sudo mount `cat loopback_dev`p1 build_root
	sudo mkdir build_root/boot
	sudo cp -rv limine/limine.sys build_root/boot/
	sudo cp -rv kernel/coffee.elf build_root/boot/
	sudo cp -rv limine.cfg build_root/
	sync
	sudo umount build_root/
	sudo losetup -d `cat loopback_dev`
	rm -rf build_root loopback_dev
	limine/limine-install $(EXPORT)

.PHONY: clean
clean:
	rm -rf *.o *.elf *.d $(EXPORT) build_root/
	clear
