#define EPLL_LOCK (0x10030000 + 0xC010)
#define VPLL_LOCK (0x10030000 + 0xC020)
#define MPLL_LOCK (0x10040000 + 0x0008)
#define APLL_LOCK (0x10040000 + 0x4000)

#define APLL_CON0 (0x10040000 + 0x4100)
#define MPLL_CON0 (0x10040000 + 0x0108)
#define EPLL_CON0 (0x10030000 + 0xC110)
#define VPLL_CON0 (0x10030000 + 0xC120)

#define CLK_SRC_CPU (0x10040000 + 0x4200)
#define CLK_SRC_DMC (0x10040000 + 0x0200)
#define CLK_SRC_TOP0 (0x10030000 + 0xC210)
#define CLK_SRC_TOP1 (0x10030000 + 0xC214)
#define CLK_SRC_LEFTBUS (0x10030000 + 0x4200)
#define CLK_SRC_RIGHTBUS (0x10030000 + 0x8200)

#define CLK_DIV_CPU0 (0x10040000 + 0x4500)
#define CLK_DIV_CPU1 (0x10040000 + 0x4504)
#define CLK_DIV_DMC0 (0x10040000 + 0x0500)
#define CLK_DIV_DMC1 (0x10040000 + 0x0504)
#define CLK_DIV_TOP  (0x10030000 + 0xC510)
#define CLK_DIV_LEFTBUS (0x10030000 + 0x4500)
#define CLK_DIV_RIGHTBUS (0x10030000 + 0x8500)

.global lowlevel_init
lowlevel_init:
	ldr r0, =(APLL_LOCK)
	ldr r1, =0x00000FFF
	str r1, [r0]

	ldr r0, =(MPLL_LOCK)
	ldr r1, =0x00000FFF
	str r1, [r0]

	ldr r0, =(EPLL_LOCK)
	ldr r1, =0x00000FFF
	str r1, [r0]

	ldr r0, =(VPLL_LOCK)
	ldr r1, =0x00000FFF
	str r1, [r0]

	ldr r0, =(APLL_CON0)
	ldr r1, =0x807D0300
	str r1, [r0]

	ldr r0, =(MPLL_CON0)
	ldr r1, =0x80640300
	str r1, [r0]

	ldr r0, =(EPLL_CON0)
	ldr r1, =0x80640301
	str r1, [r0]

	ldr r0, =(VPLL_CON0)
	ldr r1, =0x80640303
	str r1, [r0]

	ldr r0, =(CLK_SRC_CPU)
	ldr r1, =0x01000001
	str r1, [r0]

	ldr r0, =(CLK_SRC_DMC)
	ldr r1, =0x00011000
	str r1, [r0]

	ldr r0, =(CLK_SRC_TOP0)
	ldr r1, =0x00000110
	str r1, [r0]

	ldr r0, =(CLK_SRC_TOP1)
	ldr r1, =0x00011000
	str r1, [r0]

	ldr r0, =(CLK_SRC_LEFTBUS)
	ldr r1, =0x00000010
	str r1, [r0]

	ldr r0, =(CLK_SRC_RIGHTBUS)
	ldr r1, =0x00000010
	str r1, [r0]

	ldr r0, =(CLK_DIV_CPU0)
	ldr r1, =0x01143730
	str r1, [r0]

	ldr r0, =(CLK_DIV_CPU1)
	ldr r1, =0x00000004
	str r1, [r0]

	ldr r0, =(CLK_DIV_DMC0)
	ldr r1, =0x00111113
	str r1, [r0]

	ldr r0, =(CLK_DIV_DMC1)
	ldr r1, =0x01011113
	str r1, [r0]

	ldr r0, =(CLK_DIV_TOP)
	ldr r1, =0x01205473
	str r1, [r0]

	ldr r0, =(CLK_DIV_LEFTBUS)
	ldr r1, =0x00000013
	str r1, [r0]

	ldr r0, =(CLK_DIV_RIGHTBUS)
	ldr r1, =0x00000013
	str r1, [r0]

	mov pc, lr
