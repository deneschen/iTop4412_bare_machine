#ifndef S3C4412_UART_H
#define S3C4412_UART_H

#define ulcon_offset 	(0x0000)
#define ucon_offset 	(0x0004)
#define ufcon_offset 	(0x0008)
#define umcon_offset 	(0x000C)
#define utrstat_offset 	(0x0010)
#define uerstat_offset 	(0x0014)
#define ufstat_offset 	(0x0018)
#define umstat_offset 	(0x001C)
#define utxh_offset 	(0x0020)
#define urxh_offset 	(0x0024)
#define ubrdiv_offset 	(0x0028)
#define ufracval_offset (0x002C)
#define uintp_offset 	(0x0030)
#define uintsp_offset 	(0x0034)
#define uintm_offset 	(0x0038)

#define ULCON2 		(0x13820000)
#define UCON2 		(ULCON2 + ucon_offset)
#define UFCON2 		(ULCON2 + ufcon_offset)
#define UMCON2 		(ULCON2 + umcon_offset)
#define UTRSTAT2 	(ULCON2 + utrstat_offset)
#define UERSTAT2 	(ULCON2 + uerstat_offset)
#define UFSTAT2 	(ULCON2 + ufstat_offset)
#define UMSTAT2 	(ULCON2 + umstat_offset)
#define UTXH2 		(ULCON2 + utxh_offset)
#define URXH2 		(ULCON2 + urxh_offset)
#define UBRDIV2 	(ULCON2 + ubrdiv_offset)
#define UFRACVAL2 	(ULCON2 + ufracval_offset)
#define UINTP2 		(ULCON2 + uintp_offset)
#define UINTSP2 	(ULCON2 + uintsp_offset)
#define UINTM2 		(ULCON2 + uintm_offset)


#endif
