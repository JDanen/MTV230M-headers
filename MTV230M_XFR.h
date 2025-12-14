#pragma once
#include <stdint.h>

// Read/write permissions
#define read
#define write
#define both

#define sdcc 

// Macro for defining XFRs
#if defined(sdcc)
#define read const
#define XFR_8(name, addr, access) __xdata __at(addr) access volatile uint8_t name
#define XFR_16(name, addr, access) __xdata __at(addr) access volatile uint16_t name
#define XFR_32(name, addr, access) __xdata __at(addr) access volatile uint32_t name
#else
#error "Figure out your own XFR definitions!" 
#endif

/*         -name-    -address-  -access-       -function-                                              */
XFR_32(   PADMOD,       0x0F2B,	  write	);	/** Pad mode control register. (All are "0" in Chip Reset) */
XFR_8(    OPTION,	    0x0F2F,	  write	);	/** Chip option configuration (All are "0" in Chip Reset) */

XFR_8(    PORT4[8],     0x0F30,	  both	);	/** Port 4 base register and pin P4.0 control */
XFR_8(    PORT5[8],     0x0F38,	  both	);	/** Port 5 base register and pin P5.0 control */
XFR_8(    PORT6[3],     0x0F28,	  write	);	/** Port 6 base register and pin P6.0 control */

XFR_8(    DA0,	        0x0F20,	  both	);	/** 8-bit PWM value (0x80 after power-on) */
XFR_8(    DA1,	        0x0F21,	  both	);	/** 8-bit PWM value (0x80 after power-on) */
XFR_8(    DA2,	        0x0F22,	  both	);	/** 8-bit PWM value (0x80 after power-on) */
XFR_8(    DA3,	        0x0F23,	  both	);	/** 8-bit PWM value (0x80 after power-on) */

XFR_8(    HVSTUS,	    0x0F40,	  read	);	/** The status of polarity, present and static level for HSYNC and VSYNC */
XFR_8(    HCNTH,	    0x0F41,	  read	);	/** High byte of hor. frequency counter */
XFR_8(    HCNTL,	    0x0F42,	  read	);	/** Low byte of hor. frequency counter */
XFR_8(    VCNTH,	    0x0F43,	  read	);	/** High byte of vert. frequency counter */
XFR_8(    VCNTL,	    0x0F44,	  read	);	/** Low byte of vert. frequency counter */
XFR_8(    HVCTR0,	    0x0F40,	  write	);	/** H/V sync processor control register 0 */
XFR_8(    HVCTR3,	    0x0F43,	  write	);	/** HSYNC clamp pulse control register */
XFR_8(    HVINTFLG,	    0x0F48,	  both	);	/** Interrupt flag register. Interrupts set the flag bits, writing 1 to a bit will clear it. */
XFR_8(    HVINTEN,	    0x0F49,	  write	);	/** Interrupt enable register */

XFR_8(    IICCTR,	    0x0F00,	  both	);	/** IIC interface control register */
XFR_16(   IICSTUS,  	0x0F01,	  read	);	/** IIC interface status register */
XFR_8(    IICINTFLG,	0x0F03,	  both	);	/** Interrupt flag register. Interrupts set the flag bits, writing 1 to a bit will clear it. */
XFR_8(    IICINTEN,	    0x0F04,	  write	);	/** Interrupt enable register */
XFR_8(    MBUF,	        0x0F05,	  both	);	/** Master IIC receive/transmit buffer */
XFR_8(    RCABUF,	    0x0F06,	  read	);	/** Slave A IIC receive buffer */
XFR_8(    TXABUF,	    0x0F06,	  write	);	/** Slave A IIC transmit buffer */
XFR_8(    SLVAADR,	    0x0F07,	  write	);	/** Slave A IIC address */
XFR_8(    RCBBUF,	    0x0F08,	  read	);	/** Slave B IIC receive buffer */
XFR_8(    TXBBUF,	    0x0F08,	  write	);	/** Slave B IIC transmit buffer */
XFR_8(    SLVBADR,      0x0F09,	  write	);	/** Slave B IIC address */

XFR_8(    ADCCTRL,      0x0F10,	  write	);	/** ADC control register. */
XFR_8(    ADCCONV,      0x0F10,	  read	);	/** ADC conversion result */

XFR_8(    WDT,	        0x0F18,	  write	);	/** Watchdog timer control register */

XFR_8(    ISPSLV,	    0x0F0B,	  write	);	/** ISP slave address */
XFR_8(    ISPEN,	    0x0F0C,	  write	);	/** Write 0x93 here to enable ISP mode */

XFR_8(    OSDRA,	    0x0FA0,	  write	);	/**  */
XFR_8(    OSDCA,	    0x0FA1,	  write	);	/** This is the column address of the display RAM that next 9-bit data should be written into */
XFR_8(    OSDDT0,	    0x0FA2,	  write	);	/** Form a 9-bit value – (0 << 8) || OSDDT0 and write into current display RAM address */
XFR_8(    OSDDT1,	    0x0FA3,	  write	);	/** Form a 9-bit value – (1 << 8) || OSDDT1 and write into current display RAM address */
XFR_8(    W1ROW,	    0x0FC0,	  write	);	/**  */
XFR_16(   W1COL,        0x0FC1,	  write	);	/**  */
XFR_8(    W2ROW,	    0x0FC3,	  write	);	/**  */
XFR_16(   W2COL,        0x0FC4,	  write	);	/**  */
XFR_8(    W3ROW,	    0x0FC6,	  write	);	/**  */
XFR_16(   W3COL,        0x0FC7,	  write	);	/**  */
XFR_8(    W4ROW,	    0x0FC9,	  write	);	/**  */
XFR_16(   W4COL,        0x0FCA,	  write	);	/**  */
XFR_8(    VERTD,	    0x0FCC,	  write	);	/** Starting position for vert. display. Starts at line 4*VERTD + 1. Power-up value: 4 */
XFR_8(    HORD,	        0x0FCD,	  write	);	/** Starting position for hor. display. Starts at dot 6*HORD + 49. Power-up value: 15 */
XFR_8(    CH,	        0x0FCE,	  write	);	/** Character height */
XFR_8(    RSPACE,	    0x0FD0,	  write	);	/** Row to row spacing */
XFR_16(   OSDCON,       0x0FD1,	  both	);	/** OSD control register     */
XFR_8(    CHSC,	        0x0FD3,	  write	);	/** Character shadow colour */
XFR_8(    FSSTP,	    0x0FD4,	  write	);	/** Full screen self-test pattern control register */
XFR_8(    WINSW,	    0x0FD5,	  write	);	/** Window shadow width control register */
XFR_8(    WINSH,	    0x0FD6,	  write	);	/** Window shadows height control register */
XFR_16(   WINSC,        0x0FD7,	  write	);	/** Window shadow colour register */
XFR_8(    XDEL,	        0x0FD9,	  write	);	/** Rout, Gout, Bout, FBKG and INT outputs delay reference to pin XIN input falling edge control register */

// clean up macro namespace
#undef XFR_8
#undef XFR_16
#undef XFR_32
#undef read
#undef write
#undef both
