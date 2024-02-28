# Bluetooth gyro mouse in the shape of Harry Potter's Magic Wand

zh-CN/简体中文：[查看链接](https://) <br>
This project is a Bluetooth gyro mouse in the shape of Harry Potter's Magic Wand using ESP32-C3 and MPU6050.It can be used as a mouse, with all the functions of a mouse, and the top of magic wand can light up and be used as a flashlight. You can control your computer with this "mouse" by using your hand movement. <br>
This repository includes programs, circuit information, and 3D models. <br>
![pic1](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic1.jpg?raw=true)
![pic2](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic2.jpg?raw=true)

The video demonstration and tutorial for this project:[Bilibili]() <br>
I would greatly appreciate it if you press like or subscribe. <br>


## Features
* Bluetooth connectivity
* Left key (click, long press, and drag)
* Right key (click, long press, and drag)
* Scroll Up
* Scroll Down
* Glow as a flashlight(Lumos)
* Build in Battery

![pic3](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic4.jpg)

## Component List
* ESP32C3SuperMini 
![pic4](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/esp32c3.JPG)
* MPU6050
* Arrow Button
![pic5](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/arrowbutton.JPG)
* 5mm LED
* 3.7V battery
* Wire
* Hot Glue

## Circuit and connect

```
* White LED:
LED+ <-> 3V3
LED- <-> GPIO4

* MPU6050:
VCC <-> 5V
GND <-> GND
SCL <-> GPIO9
SDA <->GPIO8

* Arrow Button:
Comm <-> GND
Up <-> GPIO10
Down <-> GPIO20
Left <-> GPIO5
Right <-> GPIO7
Press <-> GPIO6
```

## Reference documents
* [Document of ESP32C3SuperMini](https://www.nologo.tech/product/esp32/esp32c3SuperMini/esp32C3SuperMini.html)
* [ESP32 BLE Mouse library](https://github.com/T-vK/ESP32-BLE-Mouse)
