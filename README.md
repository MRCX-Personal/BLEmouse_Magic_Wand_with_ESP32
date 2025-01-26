# Bluetooth gyro mouse in the shape of Harry Potter's Magic Wand / DIY哈利波特魔杖·蓝牙体感鼠标

This project is a Bluetooth gyro mouse in the shape of Harry Potter's Magic Wand using ESP32-C3 and MPU6050.It can be used as a mouse, with all the functions of a mouse, and the top of magic wand can light up and be used as a flashlight. You can control your computer with this "mouse" by using your hand movement. <br>
本项目使用ESP32和MPU6050制作了蓝牙体感鼠标，外形为哈利波特的魔杖。其具有一个普通鼠标的所有功能，并且魔杖顶部具有一个LED，可以点亮（荧光闪烁）。你可以挥舞该魔杖以实现体感控制电脑。 <br>

This repository includes programs, circuit information, and 3D models. <br>
本仓库包含该项目的程序、电路连接指南和3D模型。 <br>
![pic1](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic1.jpg?raw=true)
![pic2](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic2.jpg?raw=true)

The video demonstration and tutorial for this project:[Bilibili]() <br>
I would greatly appreciate it if you press like or subscribe. <br>


## Features / 功能
* Bluetooth connectivity / 蓝牙连接、自动回连配对的设备
* Left key (click, long press, and drag) / 鼠标左键（点击、长按和拖动）
* Right key (click, long press, and drag) / 鼠标右键（点击、长按和拖动）
* Mouse movement / 体感控制鼠标移动（敏感度可调节）
* Scroll Up / 滚轮向上
* Scroll Down / 滚轮向下
* Glow as a flashlight(Lumos) / LED照明常亮、熄灭（荧光闪烁）
* Build in Battery / 内置锂电池和充放电保护电路、Type-C充电

![pic3](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/pic4.jpg)

## Component List / 原件列表
* ESP32C3SuperMini 
![pic4](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/esp32c3.JPG)
* MPU6050
* Arrow Button / 五向按键
![pic5](https://github.com/MRCX-Personal/BLEmouse_Magic_Wand_with_ESP32/blob/main/pic/arrowbutton.JPG)
* 5mm LED
* 3.7V battery
* Wire / 导线
* Hot Glue / 热熔胶（用于外观模拟魔杖的木纹质感）

## Circuit and connect / 模块间接线

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

## Reference documents / 参考链接
* [Document of ESP32C3SuperMini](https://www.nologo.tech/product/esp32/esp32c3SuperMini/esp32C3SuperMini.html)
* [ESP32 BLE Mouse library](https://github.com/T-vK/ESP32-BLE-Mouse)
* [How to Make a Gesture-controlled Mouse Using an Arduino Leonardo](https://maker.pro/arduino/projects/how-to-make-a-nintendo-wii-inspired-air-mouse-using-an-arduino-leonardo)
* [Head Mouse With MPU6050 and Arduino Micro](https://www.instructables.com/Head-Mouse-With-MPU6050-and-Arduino-Micro/)
