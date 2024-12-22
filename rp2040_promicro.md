# RP2040 Pro-micro 

## Getting started 

Follow the manual installation chapter 

https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

short guide:

https://wellys.com/posts/rp2040_c_macos/

## Install the package

Note: **do not install** this with brew arm-none-eabi-gcc, 

Download the package from ARM:

https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads

then choose for Apply M3: 

    macOS (Apple silicon) hosted cross toolchains
    - AArch32 bare-metal target (arm-none-eabi)

> Key Tools Included in the Toolchain:
>
> arm-none-eabi-gcc – ARM C/C++ compiler.
 arm-none-eabi-ld – ARM linker.
 arm-none-eabi-nm – Symbol listing tool, like nm, but for ARM targets.
 arm-none-eabi-objcopy – For converting between different binary formats (e.g., ELF to binary).
 arm-none-eabi-as – Assembler.
 arm-none-eabi-gdb – Debugger for ARM.

rp2040 is arm 32 bit architecture.

https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-darwin-arm64-arm-none-eabi.pkg

you will need to reference this path later on your project

    /Applications/ArmGNUToolchain/14.2.rel1/arm-none-eabi/bin

Ensure you have the other modules

    cmake --version
    make --version
    clang --version

```
git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
cd ..
git clone -b master https://github.com/raspberrypi/pico-examples.git
```
This creates two dirs:

- pico-sdk
- pico-examples

Create an `.env` in `pico-examples` to export the sdk path 

Don't forget to replace **{USER}**

file `.env`:

    export PICO_SDK_PATH=/Users/{USER}/src/github/pico-sdk
    export PICO_TOOLCHAIN_PATH=/Applications/ArmGNUToolchain/14.2.rel1/arm-none-eabi/bin

the load the path as `source .env`

Neovim does not find the imports, fix it by changing 
CMakeLists.txt

```cmake
set(PICO_SDK_PATH "/Users/{USER}/src/github/pico-sdk")
# this creates compile_commands.json needed by neovim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  
```

update the example pin LED. I am using a clone mini version of 
`sparkfun_promicro`

modify the file 
`pico-sdk/src/boards/include/boards
/sparkfun_promicro.h`

uncomment the following code and replace 25 with 17.

```c
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN   17
#endif
```

then back to `pico-examples`

mkdir build
cd build
# tell to compile the examples for the sparkfun promicro
cmake .. -DPICO_BOARD=sparkfun_promicro
cd blink
make -j4
# plugin Pico with BOOTSEL pressed down to get RPI-RP2
cp blink.uf2 /Volumes/RPI-RP2


