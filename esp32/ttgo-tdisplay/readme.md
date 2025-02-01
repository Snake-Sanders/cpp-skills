
# ESP32 LilyGo T-Display 

## Installation

### USB to TTL seria driver for MacOS 

The required driver for this board is `CH9102F` but the driver in 
`../usb2ttl_driver/CH341SER_MAC.ZIP` also includes this chip model.

Unzip the driver and open `CH34xVCPDriver.dmg` file 
Drag and drop the file to `Application` like any other app.
It will ask to give permission, this might change from on OS version to another,
so check the PDF in the zip file.

* Source:

https://github.com/WCHSoftGroup/ch34xser_macos

* Forum refrences:

https://arduino.stackexchange.com/a/86787

## Select port

Check under `/dev/*` if the driver was installed.

```sh
lla /dev | grep usb

crw-rw-rw-   1 root   wheel      0x9000003 Dec 31 16:31 cu.usbserial-58AB0097191
crw-rw-rw-   1 root   wheel      0x9000005 Dec 31 16:31 cu.wchusbserial58AB0097191
crw-rw-rw-   1 root   wheel      0x9000002 Dec 31 16:31 tty.usbserial-58AB0097191
crw-rw-rw-   1 root   wheel      0x9000004 Dec 31 16:31 tty.wchusbserial58AB0097191
```

Try selecting `cu.wchusbserial58AB0097191` in Arduino IDE under Tools > Port.

If the device doesn’t respond, try cu.usbserial-58AB0097191.
Both should work identically.

## Board info

Once the port is detected and connected with Arduino IDE, 
try to read the board information.
Go to `Tools/Get board info`:

```
BN: LilyGo T-Display
VID: 0x1A86
PID: 0x55D4
SN: 58AB009719
```

## Project Setup

Open the Arduino IDE do the following:

1. download the `TFT_eSPI` library into your Arduino IDE 
2. select ESP32 Dev Module. 
3. go to `/Users/<USER>/Documents/Arduino/libraries/TFT_eSPI`
4. edit the `User_Setup_Select.h` file in the `TFT_eSPI` library 
5. select the Setup file for ESP32 and TTGO T-Display ST7789V SPI bus TFT 

This is a clone of the TTGO T-Display module, so select the 
setup file for ESP32 and TTGO T-Display ST7789V SPI bus TFT

```c
//...
//#include <User_Setups/Setup24_ST7789.h>            
#include <User_Setups/Setup25_TTGO_T_Display.h>    
//#include <User_Setups/Setup26_TTGO_T_Wristband.h>  
//...
```
