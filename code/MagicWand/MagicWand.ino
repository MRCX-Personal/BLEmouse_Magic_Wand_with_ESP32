#include <Wire.h>
#include <BleMouse.h>

#define LED 4
#define LED_KEY 5
#define LEFT_KEY 6
#define RIGHT_KEY 7
#define UP_KEY 10
#define DOWN_KEY 20
//接线详情看README

BleMouse bleMouse("Magic Wand", " ", 100);//可以修改设备名称以及生产厂家
int Sensitivity = 500;//鼠标移动的灵敏度
int val = 0;
int o_val = 0;
int state = 0;
uint8_t data[6];
int16_t gyroX, gyroZ;
uint32_t timer;
uint8_t i2cData[14];
const uint8_t IMUAddress = 0x68;//MPU6050的I2C地址
const uint16_t I2C_TIMEOUT = 1000;

uint8_t i2cWrite(uint8_t registerAddress, uint8_t* data, uint8_t length, bool sendStop) {
  Wire.beginTransmission(IMUAddress);
  Wire.write(registerAddress);
  Wire.write(data, length);
  return Wire.endTransmission(sendStop);
}

uint8_t i2cWrite2(uint8_t registerAddress, uint8_t data, bool sendStop) {
  return i2cWrite(registerAddress, &data, 1, sendStop);
}

uint8_t i2cRead(uint8_t registerAddress, uint8_t* data, uint8_t nbytes) {
  uint32_t timeout;
  Wire.beginTransmission(IMUAddress);
  Wire.write(registerAddress);
  if (Wire.endTransmission(false))
    return 1;
  Wire.requestFrom(IMUAddress, nbytes, (uint8_t)true);
  for (uint8_t i = 0; i < nbytes; i++) {
    if (Wire.available())
      data[i] = Wire.read();
    else {
      timeout = micros();
      while (((micros() - timeout) < I2C_TIMEOUT) && !Wire.available());
      
      if (Wire.available())
        data[i] = Wire.read();
      else
        return 2;
    }
  }
  return 0;
}

void setup() {
  pinMode(LEFT_KEY, INPUT_PULLUP);
  pinMode(RIGHT_KEY, INPUT_PULLUP);
  pinMode(UP_KEY, INPUT_PULLUP);
  pinMode(DOWN_KEY, INPUT_PULLUP);
  pinMode(LED_KEY, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);//上电默认LED熄灭
  Wire.begin();

  i2cData[0] = 7;
  i2cData[1] = 0x00;
  i2cData[3] = 0x00;

  while (i2cWrite(0x19, i2cData, 4, false));
  while (i2cWrite2(0x6B, 0x01, true));
  while (i2cRead(0x75, i2cData, 1));
  delay(50);
  while (i2cRead(0x3B, i2cData, 6));

  timer = micros();
  bleMouse.begin();
  delay(100);
}

void loop() {
  while (i2cRead(0x3B, i2cData, 14));
  gyroX = ((i2cData[8] << 8) | i2cData[9]);
  gyroZ = ((i2cData[12] << 8) | i2cData[13]);
  gyroX = gyroX / Sensitivity / 1.1  * -1;
  gyroZ = gyroZ / Sensitivity  * -1;

  val = digitalRead(LED_KEY);
  if (val == HIGH && o_val == LOW) {
    state = 1 - state;
    delay(10);
  }
  o_val = val;
  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  if (bleMouse.isConnected()) {
    bleMouse.move(gyroZ, -gyroX);
    if (digitalRead(LEFT_KEY) == LOW) {
      bleMouse.press(MOUSE_LEFT);
      delay(5);
    }
    if (digitalRead(LEFT_KEY) == HIGH) {
      bleMouse.release(MOUSE_LEFT);
      delay(5);
    }
    if (digitalRead(RIGHT_KEY) == LOW) {
      bleMouse.press(MOUSE_RIGHT);
      delay(5);
    }
    if (digitalRead(RIGHT_KEY) == HIGH) {
      bleMouse.release(MOUSE_RIGHT);
      delay(5);
    }
    if (digitalRead(UP_KEY) == LOW) {
      bleMouse.move(0, 0, 1);//默认滚轮滚1行，可以自行修改
      delay(100);
    }
    if (digitalRead(DOWN_KEY) == LOW) {
      bleMouse.move(0, 0, -1);//默认滚轮滚1行，可以自行修改
      delay(100);
    }

  }
  delay(1);//扫描频率，在流畅度和功耗之间做平衡
}
