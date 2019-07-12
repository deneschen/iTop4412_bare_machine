.global _start

.word 0x2000
.word 0x0
.word 0x0
.word 0x0

_start:
	/* set PSHOLD output */
	ldr r0, =0x1002330C
	ldr r1, [r0]
	orr r1, r1, #0x300
	str r1, [r0]

	ldr r0, =0x11000C08
	ldr r1, =0x0
	str r1, [r0]

halt:
	b halt
