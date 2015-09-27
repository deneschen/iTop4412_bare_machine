#include "s3c4412_dram.h"
SECTIONS {
	. = CONFIG_SYS_BASE;
	image_start = .;
	.text 		ALIGN(4) : { *(.text) }
	.rodata 	ALIGN(4) : { *(.rodata*) } 
	.data 		ALIGN(4) : { *(.data*) } 
	image_end = .;
	.bss 		ALIGN(4) : { *(.bss) *(COMMON) }
}
