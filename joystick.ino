
/*
 * Program Name : Joystick Arduino 
 * Date Created : December 2011
 * Created By: Mohan Gopal Tripathi
 * Description : Interfacing 2 axis joystick with Arduino Uno, it operates UP, DOWN, LEFT and RIGHT. 
 * 
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include<SPI.h>
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA,U8X8_PIN_NONE);   // library for display 0.96" I2C OLED




int sw = 3;                // digital swith of joystick module
int xaxis = A0;            // x-axis of joystick module
int yaxis = A1;            // y-axis of joystick module
int valuex,valuey;
int value1,value2;
int ledpin1 = 9;
int ledpin2 = 10;
int ledpin3 = 11;
int ledpin4 = 12;


void setup() {

  pinMode(sw, INPUT);          // declaring sw(switch) as input
  Serial.begin(9600);
  u8g2.begin();
  
  
 }

void loop() {

  valuex = analogRead(xaxis);
  value1 = map(valuex, 0, 1023, 0, 100);       // mapping of up direction
  Serial.print("X Axis :    ");
  Serial.println(value1);

  valuey = analogRead(yaxis);
  value2 = map(valuey, 0, 1023, 0, 100);          // mapping of down direction
  Serial.print("Y Axis :     ");
  Serial.println(value2);
  Serial.print("switch :  ");
  Serial.println();

  u8g2.clearBuffer();                        // clear the internal menory
  u8g2.setFont(u8g2_font_ncenB08_tr);        // choose a suitable font
  enum {BufSize=9}; 
  char buf[BufSize];
  snprintf (buf, BufSize, "%d", value1);
  u8g2.drawStr(10, 10,"X : ");
  u8g2.drawStr(35, 10,buf);

  char buf1[BufSize];
  snprintf (buf1, BufSize, "%d", value2);
  u8g2.drawStr(10, 40,"Y : ");
  u8g2.drawStr(35, 40,buf1);
  
  u8g2.sendBuffer();
  

  delay(200);
  
}

 
    



