qemu-system-arm -nographic -sd vexpress.img -M vexpress-a9 -m 512M -kernel zImage -dtb vexpress-v2p-ca9.dtb  -smp 4 -append "init=/linuxrc slub_debug root=/dev/mmcblk0p1 rw rootwait loglevel=8 earlyprintk console=ttyAMA0 initcall_debug" -redir tcp:1235::1235 -redir udp:5001::5001 2>/dev/null

