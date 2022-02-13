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

def init_droot
    puts "qwqww"
end

image_name="coffee_distrobution"
options = {}
OptionParser.new do |opt|
    opt.on('--init') do
        if not Dir.exists? "d_root"
            dr_path = Dir.mkdir "d_root"
            puts "'d_root' Directory Created!"
        else
            puts "'d_root' Directory is Already Exist!"
        end
    end
    opt.on('--ss LASTNAME') { |o| options[:last_name] = o }
end.parse!
