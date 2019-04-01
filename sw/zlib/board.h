////////////////////////////////////////////////////////////////////////////////
//
// Filename:	./board.h
//
// Project:	ArrowZip, a demonstration of the Arrow MAX1000 FPGA board
//
// DO NOT EDIT THIS FILE!
// Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
// DO NOT EDIT THIS FILE!
//
// CmdLine:	autofpga autofpga -d -o . clock.txt global.txt dlyarbiter.txt version.txt buserr.txt pic.txt pwrcount.txt spio.txt rtclight.txt hbconsole.txt bkram.txt flexpress.txt sdram.txt zipbones.txt mem_all.txt mem_flash_bkram.txt mem_bkram_only.txt mem_sdram_bkram.txt
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
#ifndef	BOARD_H
#define	BOARD_H

// And, so that we can know what is and isn't defined
// from within our main.v file, let's include:
#include <design.h>

#include <design.h>
#include <cpudefs.h>

#define	_HAVE_ZIPBONES

#ifdef	INCLUDE_ZIPCPU
#ifdef INCLUDE_DMA_CONTROLLER
#define	_HAVE_ZIPSYS_DMA
#endif	// INCLUDE_DMA_CONTROLLER
#ifdef INCLUDE_ACCOUNTING_COUNTERS
#define	_HAVE_ZIPSYS_PERFORMANCE_COUNTERS
#endif	// INCLUDE_ACCOUNTING_COUNTERS
#endif // INCLUDE_ZIPCPU


typedef struct  CONSOLE_S {
	unsigned	u_setup;
	unsigned	u_fifo;
	unsigned	u_rx, u_tx;
} CONSOLE;



typedef	struct	RTCLIGHT_S	{
	unsigned	r_clock, r_stopwatch, r_timer, r_alarm;
} RTCLIGHT;


#define	SPIO_BTN_LEFT	0x00100
#define	SPIO_BTN_RIGHT	0x00100


#define	CLKFREQHZ	80000000


#define BUSPIC(X) (1<<X)


#ifdef	BUSCONSOLE_ACCESS
#define	_BOARD_HAS_BUSCONSOLE
static volatile CONSOLE *const _uart = ((CONSOLE *)0x00400000);
#endif	// BUSCONSOLE_ACCESS
#ifdef	BKRAM_ACCESS
#define	_BOARD_HAS_BKRAM
extern char	_bkram[0x00008000];
#endif	// BKRAM_ACCESS
#ifdef	RTC_ACCESS
#define	_BOARD_HAS_RTC
static volatile RTCLIGHT *const _rtc = ((RTCLIGHT *)0x00800040);
#endif	// RTC_ACCESS
#ifdef	SPIO_ACCESS
#define	_BOARD_HAS_SPIO
static volatile unsigned *const _spio = ((unsigned *)0x00600010);
#endif	// SPIO_ACCESS
#ifdef	PWRCOUNT_ACCESS
#define	_BOARD_HAS_PWRCOUNT
static volatile unsigned *const _pwrcount = ((unsigned *)0x0060000c);
#endif	// PWRCOUNT_ACCESS
#ifdef	SDRAM_ACCESS
#define	_BOARD_HAS_SDRAM
extern char	_sdram[0x00800000];
#endif	// SDRAM_ACCESS
#define	_BOARD_HAS_BUSERR
static volatile unsigned *const _buserr = ((unsigned *)6291460);
#ifdef	FLASH_ACCESS
#define	_BOARD_HAS_FLASH
extern char _flash[0x00800000];
#endif	// FLASH_ACCESS
#define	_BOARD_HAS_BUILDTIME
#ifdef	BUSPIC_ACCESS
#define	_BOARD_HAS_BUSPIC
static volatile unsigned *const _buspic = ((unsigned *)0x00600008);
#endif	// BUSPIC_ACCESS
#ifdef	BUSTIMER_ACCESS
#define	_BOARD_HAS_BUSTIMER
static volatile unsigned *const _bustimer = ((unsigned *)0x00800000);
#endif	// BUSTIMER_ACCESS
#ifdef	FLASHCFG_ACCESS
#define	_BOARD_HAS_FLASHCFG
static volatile unsigned * const _flashcfg = ((unsigned *)(0x00200000));
#endif	// FLASHCFG_ACCESS
#define	_BOARD_HAS_VERSION
//
// Interrupt assignments (1 PICs)
//
// PIC: buspic
#define	BUSPIC_UARTTXF	BUSPIC(0)
#define	BUSPIC_UARTRXF	BUSPIC(1)
#define	BUSPIC_UARTTX	BUSPIC(2)
#define	BUSPIC_UARTRX	BUSPIC(3)
#define	BUSPIC_RTC	BUSPIC(4)
#define	BUSPIC_SPIO	BUSPIC(5)
#define	BUSPIC_BUSTIMER	BUSPIC(6)
#endif	// BOARD_H
