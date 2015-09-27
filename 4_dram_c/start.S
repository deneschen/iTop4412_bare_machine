.word 0x0
.word 0x0
.word 0x0
.word 0x0
.global _start
_start:
	ldr r0, =0x1002330C
	ldr r1, [r0]
	orr r1, r1, #0x300
	str r1, [r0]

	ldr r0, =0x11000C08
	ldr r1, =0x0
	str r1, [r0]
	
	ldr sp, =0x02060000
	bl lowlevel_init
	bl mem_init
	bl copy_code_to_sdram
	ldr pc, =main
halt:
	b halt
