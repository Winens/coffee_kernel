=begin
    This tool helps you to make coffee distrobutions.
    Steps :
    #1 => Build Kernel.
    #2 => Run distrobution tool with "--init" command.  # Creates d_root/ directory. It's root of disk image. 
    #3 => Build hdd disk image with "--fs FILESYSTEM --confirm".    # FILESYSTEM (ext2/3/4, echfs, fat32)
    
    NOTE => There will not be filesystem until version 2 kernel.
    DO NOT COPY BOOTLOADER FILES OR KERNEL TO D_ROOT!
=end
require 'optparse'
require 'open-uri'

def ret_err(text)
    return "Could Not Found : "+text
end

image_name="coffee_distrobution"    # Change
options = {}
OptionParser.new do |opt|
    opt.on('--init') do
        if not Dir.exists? "d_root"
            dr_path = Dir.mkdir "d_root"
            Dir.mkdir "d_root/etc"
            Dir.mkdir "d_root/usr"
            Dir.mkdir "d_root/bin"
            puts "'d_root' Directory Created!"
            @d_hostname = "coffee"  # Change
            @d_sys = "Coffee OS - Workstation X86_64"   # Change
        else
            puts "'d_root' Directory is Already Exist!"
        end
    end
    opt.on('--run') do
        puts `qemu-system-x86_64 -d int -machine q35 -smp 4 -hda #{image_name}.hdd -debugcon stdio -m 2G -enable-kvm`
    end
    opt.on('--build') do
        if (File.exist? 'limine/limine.sys') && (File.exist? 'limine.cfg')
            if File.exist? 'coffee.elf'
                puts `sudo rm -rf build_root/ #{image_name}.hdd
                      mkdir -p build_root/`
                if Dir.exist? 'd_root'
                    puts `cp -r d_root/* build_root/`
                end
                puts `dd if=/dev/zero of=#{image_name}.hdd bs=4M count=128
                        parted -s #{image_name}.hdd mklabel msdos
                        parted -s #{image_name}.hdd mkpart primary 2048s 100%
                        sudo mkfs.ext2 #{image_name}.hdd
                        sudo mount #{image_name} build_root
                        sudo mkdir build_root/boot
                        sudo cp -rv limine/limine.sys build_root/boot/
                        sudo cp -rv coffee.elf build_root/boot/
                        sudo cp -rv limine.cfg build_root/
                        sudo umount build_root
                        sudo rm -rf build_root
                        limine/limine-install #{image_name}.hdd`
            else
                puts ret_err 'Kernel Build'
            end
        else
            puts ret_err 'Bootloader Files'
        end
    end
end.parse!
