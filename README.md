
## Prerequisites

	TOOL		|	Version

riscv32-unknown-elf-gcc |	12.2.0
riscv32-unknown-elf-gdb |	12.1
	GNU Make	|	4.3
	Vivado		| 	v2023.2
	
	
## Setup

	# Setup Freedom SDK
		Clone repository 
			https://github.com/sifive/freedom.git
			
		Edit file "src/main/scala/subsystem/Configs.scala" 
			In class "With1TinyCore"
				add "useUser = true," to the core parameters
				
					class With1TinyCore extends Config((site, here, up) => {
					  case XLen => 32
					  case RocketTilesKey => List(RocketTileParams(
					      core = RocketCoreParams(
						useVM = false,
				=========>	useUser = true,
						fpu = None,
						nBreakpoints = 10,
						mulDiv = Some(MulDivParams(mulUnroll = 8))),
		
		Edit file "/bootrom/xip/Makefile" 
			Change C_FLAGS -march to rv32imac_zicsr
			
		Follow the repo readme to install the dependencies
		
		Run the following commands
			make -f Makefile.e300artydevkit verilog
			make -f Makefile.e300artydevkit mcs
			
		In vivado
			after plugin the arty and the olimex debugger, open hardware manager and connect to the board
			On the left side of the default window, right click on xc7a35t nad select add configuration memory device
				Select part name mt25ql128-spi-x1_X2_X4 and press ok, press ok again when a prompt to program appears
					On the next prompt select the configuration file /builds/e300artydevkit/obj/E300ArtyDevKitFPGAChip.mcs and press ok
			Once programming finishes press the burron PROG in the arty board
				
						
	# Setup Freedom E SDK
		Clone repository 
			https://github.com/sifive/freedom-e-sdk.git
			
		Edit RISCV_ARCH to rv32imac_zicsr in /bsp/freedom-e310-arty/setings.mk
		
		
	# Sanity Check
		With the board and debugger connected, open a uart terminal with BAUDRATE 57600
		In the Freedom E SDK dir run 
			make PROGRAM=sifive-welcome TARGET=freedom-e310-arty upload
		A Sifive HelloWorld message should be printed in the terminal
				

## Build & Compile

	First run
		make worlds
			to build the worlds
	Then run 
		make
			to build uTango
	
## Uploading to the board	
		
	In the Freedom E SDK dir run 
		scripts/upload --elf (PATH_TO_UTANGO)/utango-riscv/bin/test_board/utango-riscv.elf --openocd openocd --gdb riscv32-unknown-elf-gdb --openocd-config bsp/freedom-e310-arty/openocd.cfg
			to upload utango to the arty
	
	
## Debugging

	In the utango dir run 
		riscv32-unkown-elf-gdb -x script_arty.gdb
			to start the debugging session
	
## References
1.  Daniel Oliveira and Sandro Pinto. "May the Trust be with You: Empowering TrustZone-M with Multiple Trusted Environments.", in Black Hat Asia, Singapore, 2020.t






































