# DeskDash

## Introduction

A simple personal dashboard made using M5Tab5 on Arduino IDE.

## Technologies Used

- C++
- Arduino IDE
- FreeRTOS
- LVGL

## Hardware Used

- M5Stack M5Tab5

## Features

- Automatically syncs and displays time and date in 24-hour format.
- Automatically fetches amd displays current weather data every 3 hours.
- Coming Soon...

## Getting Started

### Installation

- Install Arduino IDE from the [Arduino website](https://www.arduino.cc/en/software/#ide).
- Go to File -> Preferences -> Settings and add the following line to the additional boards manager URLs
```
https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json
```
- Install the M5Stack board library from boards manager. (The code has been tested on v3.2.6)
- Install the following libraries from the library manager:
    - `M5Unified` by M5Stack - v0.2.17
    - `M5GFX` by M5Stack - v0.2.22
    - `lvgl` by kisvegabor - v9.3.0
    - `FreeRTOS` by Richard Barry - v11.1.0-3
    - `ArduinoJson` by Benoit Blanchon - v7.4.3
- Install the Little filesystem uploader plugin. Refer to [this](https://github.com/earlephilhower/arduino-littlefs-upload).

### Preparing the configuration data

- Create a folder named `data` in the sketch folder. Make a copy of the `config_sample.json` file in that folder and rename it to `config.json`.
- Fill the data in the JSON file.
    - `gmtOffset` is the GMT offset in seconds
    - `dlOffset` is dayligt offset in seconds
    - `latitude` and `longitude` are floating point numbers (do not use `N` and `S`)
    - For `latitude` use negative numbers if on the southern hemisphere.
    - For `longitude` use negative numbers if on the western hemishpere.

### Uploading the program

- In the Arduino IDE, select the board as M5Tab5 and change partition scheme to `Custom`.
- Run the LittleFS uploader to copy the `config.json` file into the SPIFFS partition of the flash memory. (If the plugin fails, restart Arduino IDE and ensure no program is accessing the serial port of M5Tab5)
- Compile and uplaod the program as usual.

### Watch it come to life!!

## License

This repository is licensed under the [MIT License](./LICENSE)