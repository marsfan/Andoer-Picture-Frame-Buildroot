# Andoer Picture Frame Buildroot

[![CI](https://github.com/marsfan/andoer-picture-frame-buildroot/actions/workflows/main.yml/badge.svg)](https://github.com/marsfan/andoer-picture-frame-buildroot/actions/workflows/main.yml)

This is a modified version of [George Hilliard's Linux-Powered Business Card](https://github.com/thirtythreeforty/businesscard-linux) that is meant to run on an 
[Andoer 10" Digital Picture Frame](https://www.andoer.com/p-d3932b-eu.html) that
I found at a thrift store. 

The Picture Frame uses the F1C200s, which is identical the F1C100s in the 
business card, but has 64MB of RAM instead of 32MB. 


## Patched Linux and U-Boot

George lightly patched the Linux kernel and U-Boot to get all the hardware peripherals working.
You can find his forks here:

- [Linux][linux-f1c100s] v5.0.2 (patched to enable USB gadget mode)
- [U-Boot][uboot-f1c100s] (patched to support the F1C100s)

## Build

Make sure submodules are initialized:

	git submodule update --init

Change to the top-level Buildroot directory:

	cd buildroot

Initialize the configuration, including the defconfig and this external directory:

	make BR2_EXTERNAL=$PWD/../ thirtythreeforty_businesscard_defconfig

And compile:

	make

This may take a couple hours to do from scratch, depending on the speed of your machine.

## Installation

Make sure the board is in FEL mode using `dmesg` or similar, then flash it with 
the following command

	output/host/bin/sunxi-fel -p spiflash-write 0 output/images/flash.bin

You can erase the memory after it boots by simply logging in (as `root`) and erasing the flash manually:

	dd if=/dev/zero of=/dev/mtd0

Don't erase it unless you're prepared to burn a new image!

## License

Subject to the below exceptions, code is released under the GNU General Public License, version 2 or (at your option) any later version.
See also the [Buildroot license notice][buildroot-license] for more nuances about the meaning of this license.

Patches are not covered by this license. Instead, they are covered by the license of the software to which the patches are applied.

Finally, files in the `businesscard-flashdrive` package, including its README, my resume, and my photography, remain proprietary and are not released under the GPL.
If you would like to build your own firmware based on this, simply remove those files, or deselect the package during build.

[George's blog-post]: https://www.thirtythreeforty.net/posts/2019/12/my-business-card-runs-linux/
[linux-f1c100s]: https://github.com/thirtythreeforty/linux.git
[uboot-f1c100s]: https://github.com/thirtythreeforty/u-boot.git
[lichee-nano]: https://www.seeedstudio.com/Sipeed-Lichee-Nano-Linux-Development-Board-16M-Flash-WiFi-Version-p-2893.html
[buildroot-license]: https://buildroot.org/downloads/manual/manual.html#legal-info-buildroot
