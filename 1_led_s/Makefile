led.bin : start.o
	$(CROSS_COMPILE)ld -T link.lds -o led.elf $^
	$(CROSS_COMPILE)objcopy -O binary led.elf led.bin
	$(CROSS_COMPILE)objdump -D led.elf > led.dis

%.o : %.S
	$(CROSS_COMPILE)gcc -o $@ $< -c

%.o : %.c
	$(CROSS_COMPILE)gcc -o $@ $< -c

.PHONY:clean
clean:
	rm -rf *.o *.elf *.bin *.dis
