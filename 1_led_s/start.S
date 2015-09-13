.global _start

#include "s3c4412_gpio.h"

.word 0x2000
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

	ldr r0, =GPL2CON
	mov r1, #(0x01 << 0)
	str r1, [r0]

	ldr r0, =GPK1CON
	mov r1, #(0x01 << 4)
	str r1, [r0]

	ldr r0, =GPK1DAT
	mov r1, #0x2
	str r1, [r0]

	ldr r0, =GPL2DAT
	mov r1, #0x1
	str r1, [r0]

halt:
	b halt
