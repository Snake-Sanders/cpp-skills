cmake_minimum_required(VERSION 3.13)

# path to pico-sdk
set(PICO_SDK_PATH "/Users/mac/src/github/pico-sdk")
include(pico_sdk_import.cmake)
project(blink_project C CXX ASM)

# This is important for Neovim!
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(blink
  blink.c
)
pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 1)
pico_add_extra_outputs(blink)
target_link_libraries(blink pico_stdlib)
