CFLAGS := -nostdlib -O0
TARGET := uart.bin
$(TARGET) : start.o lowlevel_init.o mem_init.o main.o link.lds
	$(CROSS_COMPILE)ld -T link.lds -o xxx.elf $^
	$(CROSS_COMPILE)objcopy -O binary xxx.elf $@
	$(CROSS_COMPILE)objdump -D xxx.elf > xxx.dis
	$(CROSS_COMPILE)objdump -b binary -D -m arm $@ > b.dis

%.o : %.S
	$(CROSS_COMPILE)gcc -o $@ $< -c

%.o : %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -o $@ $< -c

%.lds: %.lds.S
	$(CROSS_COMPILE)gcc -E -P $< -o $@
.PHONY:clean flash putty
clean:
	rm -rf *.o *.elf *.bin *.dis

flash:
	mk4412 $(TARGET)
#	sudo mkfs.vfat -F 32 -I /dev/sdc
	sudo dd if=/dev/zero of=/dev/sdc bs=512 seek=1 iflag=dsync oflag=dsync count=2048
	sudo dd if=./$(TARGET) of=/dev/sdc bs=512 seek=1 iflag=dsync oflag=dsync

putty:
	sudo putty &
