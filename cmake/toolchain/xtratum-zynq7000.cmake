####
# XtratuM for Xilinx Zynq7000 
####

set(CMAKE_SYSTEM_NAME "Xtratum")

set(CMAKE_C_COMPILER "/opt/toolchain/gnu/arm/lin/bin/arm-xilinx-eabi-gcc")
set(CMAKE_CXX_COMPILER "/opt/toolchain/gnu/arm/lin/bin/arm-xilinx-eabi-g++")

set(CMAKE_LINKER "/opt/toolchain/gnu/arm/lin/bin/arm-xilinx-eabi-ld")

# Order matters here
set(CMAKE_C_LINK_EXECUTABLE
	"<CMAKE_LINKER> -o <TARGET> <OBJECTS> <LINK_LIBRARIES>   <CMAKE_C_LINK_FLAGS> <LINK_FLAGS>"
)
set(CMAKE_CXX_LINK_EXECUTABLE
	"<CMAKE_LINKER> -o <TARGET> <OBJECTS> <LINK_LIBRARIES> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS>"
)

execute_process(COMMAND
	${CMAKE_C_COMPILER} -print-libgcc-file-name -march=armv7-a -mcpu=cortex-a9 -mfpu=vfpv3 
	OUTPUT_STRIP_TRAILING_WHITESPACE
	OUTPUT_VARIABLE libgcc
)

include_directories(BEFORE
	"/opt/xm/xal/include"
	"/opt/xm/xal/include/c++"
	"/opt/xm/xm/include"
)

add_compile_options(
	"SHELL:--include xm_inc/config.h"
	"SHELL:--include xm_inc/arch/arch_types.h"
)

link_directories("/opt/xm/xal/lib" "/opt/xm/xm/lib")
add_link_options("SHELL:-u start" "SHELL:-u xmImageHdr")
add_link_options(-T/opt/xm/xal/lib/loader.lds)
add_link_options("SHELL:--start-group ${libgcc} -lxm -lxal --end-group")

# Start address of the partition
# TODO integrate with the system with xpathstart
add_link_options(-Ttext=0x10000000)

# this disables tests that check whether PartitionMain was linked
# TODO change for actual tests
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

set(FPRIME_DISABLE_DEFAULT_LOGGER TRUE)
set(FPRIME_USE_BAREMETAL TRUE)

# DO NOT EDIT: F prime searches the host for programs, not the cross
# compile toolchain
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# DO NOT EDIT: F prime searches for libs, includes, and packages in the
# toolchain when cross-compiling.
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
