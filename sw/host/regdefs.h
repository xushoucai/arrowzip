////////////////////////////////////////////////////////////////////////////////
//
// Filename:	./regdefs.h
//
// Project:	ArrowZip, a demonstration of the Arrow MAX1000 FPGA board
//
// DO NOT EDIT THIS FILE!
// Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
// DO NOT EDIT THIS FILE!
//
// CmdLine:	autofpga autofpga -d -o . clock.txt global.txt dlyarbiter.txt version.txt buserr.txt pic.txt pwrcount.txt spio.txt rtclight.txt hbconsole.txt bkram.txt flexpress.txt zipbones.txt mem_flash_bkram.txt mem_bkram_only.txt
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018-2019, Gisselquist Technology, LLC
//
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of  the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
#ifndef	REGDEFS_H
#define	REGDEFS_H


//
// The @REGDEFS.H.INCLUDE tag
//
// @REGDEFS.H.INCLUDE for masters
// @REGDEFS.H.INCLUDE for peripherals
// And finally any master REGDEFS.H.INCLUDE tags
// End of definitions from REGDEFS.H.INCLUDE


//
// Register address definitions, from @REGS.#d
//
// CONSOLE registers
#define	R_CONSOLE_FIFO  	0x00100004	// 00100000, wbregs names: UFIFO
#define	R_CONSOLE_UARTRX	0x00100008	// 00100000, wbregs names: RX
#define	R_CONSOLE_UARTTX	0x0010000c	// 00100000, wbregs names: TX
#define	R_BUILDTIME     	0x00200000	// 00200000, wbregs names: BUILDTIME
#define	R_BUILDTIME     	0x00200000	// 00200000, wbregs names: BUILDTIME
#define	R_BUSERR        	0x00200004	// 00200004, wbregs names: BUSERR
#define	R_BUSERR        	0x00200004	// 00200004, wbregs names: BUSERR
#define	R_PIC           	0x00200008	// 00200008, wbregs names: PIC
#define	R_PIC           	0x00200008	// 00200008, wbregs names: PIC
#define	R_FLASHCFG      	0x0020000c	// 0020000c, wbregs names: FLASHCFG
#define	R_FLASHCFG      	0x0020000c	// 0020000c, wbregs names: FLASHCFG
#define	R_PWRCOUNT      	0x00200010	// 00200010, wbregs names: PWRCOUNT
#define	R_PWRCOUNT      	0x00200010	// 00200010, wbregs names: PWRCOUNT
#define	R_SPIO          	0x00200014	// 00200014, wbregs names: SPIO
#define	R_SPIO          	0x00200014	// 00200014, wbregs names: SPIO
#define	R_VERSION       	0x00200018	// 00200018, wbregs names: VERSION
#define	R_VERSION       	0x00200018	// 00200018, wbregs names: VERSION
// The bus timer
#define	R_BUSTIMER      	0x00300000	// 00300000, wbregs names: BUSTIMER
// The bus timer
#define	R_BUSTIMER      	0x00300000	// 00300000, wbregs names: BUSTIMER
// The watchdog timer
#define	R_WATCHDOG      	0x00300020	// 00300020, wbregs names: WATCHDOG
// The watchdog timer
#define	R_WATCHDOG      	0x00300020	// 00300020, wbregs names: WATCHDOG
// RTC clock registers
#define	R_CLOCK         	0x00300040	// 00300040, wbregs names: CLOCK
#define	R_TIMER         	0x00300044	// 00300040, wbregs names: TIMER
#define	R_STOPWATCH     	0x00300048	// 00300040, wbregs names: STOPWATCH
#define	R_CKALARM       	0x0030004c	// 00300040, wbregs names: ALARM, CKALARM
// RTC clock registers
#define	R_CLOCK         	0x00300040	// 00300040, wbregs names: CLOCK
#define	R_TIMER         	0x00300044	// 00300040, wbregs names: TIMER
#define	R_STOPWATCH     	0x00300048	// 00300040, wbregs names: STOPWATCH
#define	R_CKALARM       	0x0030004c	// 00300040, wbregs names: ALARM, CKALARM
#define	R_BKRAM         	0x00400000	// 00400000, wbregs names: RAM
#define	R_FLASH         	0x00800000	// 00800000, wbregs names: FLASH


//
// The @REGDEFS.H.DEFNS tag
//
// @REGDEFS.H.DEFNS for masters
#define	CLKFREQHZ	80000000
#define	R_ZIPCTRL	0x01000000
#define	R_ZIPDATA	0x01000004
#define	RESET_ADDRESS	@$[0x%08x](RESET_ADDRESS)
#define	BAUDRATE	1000000
// @REGDEFS.H.DEFNS for peripherals
#define	BKRAMBASE	0x00400000
#define	BKRAMLEN	0x00001000
#define	FLASHBASE	0x00800000
#define	FLASHLEN	0x00800000
#define	FLASHLGLEN	23
// @REGDEFS.H.DEFNS at the top level
// End of definitions from REGDEFS.H.DEFNS
//
// The @REGDEFS.H.INSERT tag
//
// @REGDEFS.H.INSERT for masters

#define	CPU_GO		0x0000
#define	CPU_RESET	0x0040
#define	CPU_INT		0x0080
#define	CPU_STEP	0x0100
#define	CPU_STALL	0x0200
#define	CPU_HALT	0x0400
#define	CPU_CLRCACHE	0x0800
#define	CPU_sR0		0x0000
#define	CPU_sSP		0x000d
#define	CPU_sCC		0x000e
#define	CPU_sPC		0x000f
#define	CPU_uR0		0x0010
#define	CPU_uSP		0x001d
#define	CPU_uCC		0x001e
#define	CPU_uPC		0x001f


// @REGDEFS.H.INSERT for peripherals

// @REGDEFS.H.INSERT from the top level
typedef	struct {
	unsigned	m_addr;
	const char	*m_name;
} REGNAME;

extern	const	REGNAME	*bregs;
extern	const	int	NREGS;
// #define	NREGS	(sizeof(bregs)/sizeof(bregs[0]))

extern	unsigned	addrdecode(const char *v);
extern	const	char *addrname(const unsigned v);
// End of definitions from REGDEFS.H.INSERT


#endif	// REGDEFS_H
