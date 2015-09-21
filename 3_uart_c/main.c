#include "s3c4412_gpio.h"
#include "s3c4412_uart.h"
#include "s3c4412_cmu.h"

typedef volatile unsigned long regtype;

#define led2_on(on) do { gpio_config(GPL2DAT, (0x1 << 0), (on << 0)); } while(0)
#define led3_on(on) do { gpio_config(GPK1DAT, (0x1 << 1), (on << 1)); } while(0)

void gpio_config(int addr, int mask, int val)
{
	unsigned long value = 0;
	if (val & ~(mask))
		return;
	regtype *gpio = (regtype *)addr;
	value = ((*gpio & ~(mask)) | val);
	*gpio = value;
}

void led_init(void)
{
	gpio_config(GPL2CON, (0xF << 0), (0x1 << 0));
	gpio_config(GPL2PUD, (0x3 << 0), (0x0 << 0));

	gpio_config(GPK1CON, (0xF << 4), (0x1 << 4));
	gpio_config(GPK1PUD, (0x3 << 2), (0x0 << 2));
}

void delay(int loop)
{
	volatile int k;

	for (k = 0; k < loop; ++k)
		;
}

void uart_init(void)
{
	/* clock for uart init */
	gpio_config(CLK_SRC_PERIL0, (0xF << 8), (0x6 << 8));
	gpio_config(CLK_SRC_MASK_PERIL0, (0x1 << 8), (0x1 << 8));
	gpio_config(CLK_DIV_PERIL0, (0xF << 8), (13 << 8));
	
	/* wait for div uart 2 stable */
	while(*(volatile int *)CLK_DIV_STAT_PERIL0 & (0x1 << 8)) ;

	/* gpio and cfg uart init */
	gpio_config(GPA1CON, (0xF << 0), (0x2 << 0));
	gpio_config(GPA1CON, (0xF << 4), (0x2 << 4));
	
	gpio_config(ULCON2, 0xFFFFFFFF, 0x3);
	gpio_config(UCON2,  0xFFFFFFFF, 0x5);
	gpio_config(UFCON2, 0xFFFFFFFF, 0x0);

	gpio_config(UBRDIV2, 0xFF, 30);
	gpio_config(UFRACVAL2, 0xF, 0);

}

void putch(char ch)
{
	volatile unsigned int *state = (volatile unsigned int *)UTRSTAT2;
	volatile unsigned int *utxh  = (volatile unsigned int *)UTXH2;

	while (!(*state & (1 << 2))) ;
	*utxh = ch;
}

char getc(void)
{
	volatile unsigned int *state = (volatile unsigned int *)UTRSTAT2;
	volatile unsigned int *urxh  = (volatile unsigned int *)URXH2;

	while (!(*state & (1 << 0))) ;
	return *urxh;
}

void main(void)
{
	int i = 0;
	char c = 0;
	led_init();
	uart_init();
	while(1) {
		c = getc();
		putch(c);
		if (c == '0')
			led2_on(0);
		if (c == '1')
			led3_on(0);
		if (c == '2')
			led2_on(1);
		if (c == '3')
			led3_on(1);
		if (c == '\r') {
			putch('\n');
		}
	}
}

