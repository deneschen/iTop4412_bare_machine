#include "s3c4412_gpio.h"

typedef volatile unsigned long regtype;

#define led2_on(on) do { gpio_config(GPL2DAT, (0x1 << 0), (on << 0)); } while(0)
#define led3_on(on) do { gpio_config(GPK1DAT, (0x1 << 1), (on << 1)); } while(0)

enum key_val {
	HOME,
	BACK,
	SLEEP,
	VOLUP,
	VOLDW,
};

void gpio_config(int addr, int mask, int val)
{
	unsigned long value = 0;
	if (val & ~(mask))
		return;
	regtype *gpio = (regtype *)addr;
	value = ((*gpio & ~(mask)) | val);
	*gpio = value;
}

unsigned long gpio_getval(int addr, int mask)
{
	unsigned long value = 0;
	regtype *gpio = (regtype *)addr;
	value = *gpio & mask;
	return value;
}

void led_init(void)
{
	gpio_config(GPL2CON, (0xF << 0), (0x1 << 0));
	gpio_config(GPL2PUD, (0x3 << 0), (0x0 << 0));

	gpio_config(GPK1CON, (0xF << 4), (0x1 << 4));
	gpio_config(GPK1PUD, (0x3 << 2), (0x0 << 2));
}

void key_init(void)
{
	gpio_config(GPX1CON, (0xF << 4), (0x0 << 4));
	gpio_config(GPX1PUD, (0x3 << 2), (0x0 << 2));

	gpio_config(GPX1CON, (0xF << 8), (0x0 << 8));
	gpio_config(GPX1PUD, (0x3 << 4), (0x0 << 4));

	gpio_config(GPX3CON, (0xF << 12), (0x0 << 12));
	gpio_config(GPX3PUD, (0x3 << 6), (0x0 << 6));

	gpio_config(GPX2CON, (0xF << 0), (0x0 << 0));
	gpio_config(GPX2PUD, (0x3 << 0), (0x0 << 0));

	gpio_config(GPX2CON, (0xF << 4), (0x0 << 4));
	gpio_config(GPX2PUD, (0xF << 2), (0x0 << 2));
}

int get_key(void)
{
	if (!gpio_getval(GPX1DAT, (1 << 1)))
		return HOME;
	if (!gpio_getval(GPX1DAT, (1 << 2)))
		return BACK;
	if (!gpio_getval(GPX3DAT, (1 << 3)))
		return SLEEP;
	if (!gpio_getval(GPX2DAT, (1 << 1)))
		return VOLUP;
	if (!gpio_getval(GPX2DAT, (1 << 0)))
		return VOLDW;
	return -1;
}

void delay(int loop)
{
	volatile int k;

	for (k = 0; k < loop; ++k)
		;
}

void main(void)
{
	int i = 0;
	int key = -1;
	led_init();
	key_init();
	while(1) {
		key = get_key();
		if (key == HOME) {
			led3_on(1);
			delay(0x20000);
			led3_on(0);
		}
		if (key == BACK) {
			led2_on(1);
			delay(0x20000);
			led2_on(0);
		}
		if (key == SLEEP) {
			led2_on(1);
			led3_on(1);
			delay(0x20000);
			led2_on(0);
			led3_on(0);
		}
		if (key == VOLUP) {
			led2_on(1);
			delay(0x10000);
			led2_on(0);
			delay(0x10000);
		}
		if (key == VOLDW) {
			led3_on(1);
			delay(0x10000);
			led3_on(0);
			delay(0x10000);
		}
	}
}

