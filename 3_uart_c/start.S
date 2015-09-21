.word 0x0
.word 0x0
.word 0x0
.word 0x0
_start:
	ldr r0, =0x1002330C
	ldr r1, [r0]
	orr r1, r1, #0x300
	str r1, [r0]

	ldr r0, =0x11000C08
	ldr r1, =0x0
	str r1, [r0]
	
	bl lowlevel_init
	ldr sp, =0x02060000
	bl main
halt:
	b halt
