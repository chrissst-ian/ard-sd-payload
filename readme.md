# ard-sd-payload

HID emulator that reads a txt file payload from an SD card module and sends out keystrokes as if it were from an HID device (keyboard).

# Hardware Requirements
- Arduino Leonardo (ATmega32u4)
- Push button tactile switch
- SPI micro SD card module
- Micro SD card

# Usage Guide

1. Upload a `payload.txt` file that contains the text to be typed to the micro SD card
2. Connect the pins (see Pin Connections below)
3. Connect the Arduino to a computer via USB cable
4. Press the tactile button to start typing

# Pin Connections

|                   | Arduino Pin |
|-------------------|-------------|
| Push button       | DIGITAL 2   |
| Push button (GND) | GND         |
| Reader 3V3        | 3V3         |
| Reader CS         | DIGITAL 10  |
| Reader MOSI       | ICSP MOSI   |
| Reader CLK        | ICSP SCK    |
| Reader MISO       | ICSP MISO   |
| Reader GND        | GND         |

# ICSP Headers pinout
| 1    | 2    |
|------|------|
| MISO | VCC  |
| SCK  | MOSI |
| RST  | GND  |
