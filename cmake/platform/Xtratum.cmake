####
# XtratuM platform
###

add_definitions(-DTGT_OS_TYPE_XTRATUM)

# Disable everything. Based on XAL examples
set(CMAKE_C_FLAGS
  "${CMAKE_C_FLAGS}   -Wall -O2 -nostdlib -nostdinc -ffreestanding -Darm -fno-strict-aliasing -fomit-frame-pointer -fno-builtin -march=armv7-a -mcpu=cortex-a9 -mfpu=vfpv3"
)
# Disable everything AND exceptions and RTTI
set(CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} -Wall -O2 -nostdlib -nostdinc -ffreestanding -Darm -fno-strict-aliasing -fomit-frame-pointer -fno-builtin -march=armv7-a -mcpu=cortex-a9 -mfpu=vfpv3 -fno-exceptions -fno-rtti"
)

include_directories(SYSTEM "${FPRIME_FRAMEWORK_PATH}/Fw/Types/Xilinx")
