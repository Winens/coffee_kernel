distro_file_name="coffee_os"
tname=">==  Coffee_OS Distro Builder  <=="
if [ $1 == "--confirm" ];then
  echo $tname
  if [ -f "coffee.elf" ]; then
    if [ -f "limine.cfg" ]; then
      if [ -f "limine/limine.sys" ]; then
        rm -rf build_root/ $distro_file_name.hdd
        mkdir -p build_root/
        if [ -d "distro_root" ]; then
          cp -rp distro_root/* build_root/
        fi
        dd if=/dev/zero of=$distro_file_name.hdd bs=4M count=128
        parted -s $distro_file_name.hdd mklabel msdos
        parted -s $distro_file_name.hdd mkpart primary 2048s 100%
        sudo losetup -Pf --show $distro_file_name.hdd > loopback_dev
        sudo partprobe `cat loopback_dev`
        sudo mkfs.ext2 `cat loopback_dev`p1
        sudo mount `cat loopback_dev`p1 build_root
        sudo mkdir build_root/boot
        sudo cp -rv limine/limine.sys build_root/boot/
        sudo cp -rv coffee.elf build_root/boot/
        sudo cp -rv limine.cfg build_root/
        sync
        sudo umount build_root/
        sudo losetup -d `cat loopback_dev`
        rm -rf build_root loopback_dev
        limine/limine-install $distro_file_name.hdd
        if [ $2 ]; then
            qemu-system-x86_64 -d int -machine q35 -smp 4 -hda $distro_file_name.hdd -debugcon stdio -m 2G -enable-kvm
        fi
      else
        echo "Bootloader could not found! EXITED."
      fi
    else
      echo "Bootloader-config file could not found! EXITED."
    fi
  else
    echo "Kernel file could not found! EXITED."
  fi
elif [ $1 == "--root" ]; then
  mkdir -p distro_root/
  echo "DO NOT COPY KERNEL OR BOOTLOADER INTO THIS FOLDER 'distro_root/'"

elif [ $1 == "--run" ]; then
  qemu-system-x86_64 -d int -machine q35 -smp 4 -hda $distro_file_name.hdd -debugcon stdio -m 2G -enable-kvm
else
  echo "Use --confirm"
fi