## ArrowZip

This design is currently a work in progress.  The goal is to place a
[ZipCPU](http://zipcpu.com/about/zipcpu.html) onto a
[$30 Max1000 FPGA](http://zipcpu.com/blog/2017/12/16/max1k.html),
as sold by [Arrow](https://www.arrow.com) and
[Trenz Electronics](https://www.trenz-electronic.de).

If all goes well, this will include access to ...

- The on-board SDRAM.  This includes not only the
  [Verilog code](rtl/arrowzip/wbsdram.v) to access this SDRAM, but also a
  [simulation component](sim/verilated/sdramsim.cpp) for the SDRAM, as well
  as an [AutoFPGA](https://github.com/ZipCPU/autofpga)
  [script](auto-data/sdram.txt)
  to add (or remove) the SDRAM from this build.

  This capability now works.

- A dual-I/O flash, running in both XIP (Execute in Place) mode as well as
  a debug-bus configuration override.  As with the SDRAM, this will include
  not only the [Verilog code](rtl/arrowzip/dualflexpress.v), but also a
  simulation component and an [AutoFPGA](https://github.com/ZipCPU/autofpga)
  [script](auto-data/flexpress.txt)
  to add (or remove) the flash from this build.

  The [flash controller](rtl/arrowzip/dualflexpress.v) now works as well.

- The on-board MEMS motion sensor.

  This last piece remains a work in progress.

## 20190307 Update: The SDRAM is working

1. The design now builds and runs, both in simulation and on hardware, using
   the [flash controller](rtl/arrowzip/dualflexpress.v).

2. The [SDRAM controller](rtl/arrowzip/wbsdram.v) now passes a [memory
   test](sw/board/memtest.c), and should be ready to use.

3. The I/O drivers are currently Intel generated IP.  These still need to
   be replaced by references to the actual underlying drivers.  However, if you
   create the I/O drivers yourself, then you can run the design as is.

## To run this design ...

First, install Quartus, Verilator, and the
[ZipCPU toolchain](https://zipcpu.com/zipcpu/2018/01/31/cpu-build.html).

To run from simulation, build the design (make) and then cd into
the [sim/verilated](sim/verilated/).  Type "main_tb" to start the simulator.
"main_tb -d" will start creating a VCD file at the same time.  "main ../../sw/board/cputest" will load the CPU test into the [ZipCPU](https://zipcpu.com/about/zipcpu.html).  While running the simulation, you can telnet into "localhost 6956" to interact with the serial port of the design.  You can also use the [wbregs program](sw/host/wbregs.cpp) to read and set various addresses peripheral and otehrwise within the design.

For example, "wbregs stopwatch 1" will start the stopwatch capability. "wbregs timer 0x130" will start a timer counting down from one minute and thirty seconds.  "wbregs clock 0x210837" will set the RTC clock time to 9:08:37 PM.

To run the design on the device itself, build the design and then load it into
the device (see the vendor's instructions) and then run "netuart" from the
[sw/host](sw/host) directory.  You may need to give it the name of your serial
port, as in "netuart /dev/ttyUSB0".  (Both the simulator and [netuart](sw/host/netuart.cpp) use the same network port, so you'll only be able to run one of these at a time.)  You should then be able to use the [wbregs](sw/host/wbregs.cpp) program to interact with the various registers within the design.  To load the [cputest](sw/board/cputest.c), run "[zipload](sw/host/zipload.c) -r [../board/cputest](sw/board/cputest.c)" from the [sw/host](sw/host) directory.  You should then see a series of tests results posted on the serial port.

To reconfigure the design, such as to add or remove device or to adjust the amount of block RAM, you'll need to adjust the files in the [auto-data](auto-data) directory and re-run [AutoFPGA](https://github.com/ZipCPU/autofpga).
