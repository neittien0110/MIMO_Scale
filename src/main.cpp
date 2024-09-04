#include <Arduino.h>
#include "weight.h"

/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On ESP32-C3 supermini 8(SDA), 9(SCL),...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OLED_SCK_PIN 9
#define OLED_SDA_PIN 8

void setup() {
  Serial.begin(115200);
  Wire.begin(OLED_SDA_PIN, OLED_SCK_PIN );

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Xóa màn hình
  display.clearDisplay();
  display.display();
  delay(100);

  // Thiết lập  màu, 1 lần duy nhất
  display.setTextColor(SSD1306_WHITE);

  // Chào mừng
  display.setTextSize(2);             // Draw 2X-scale text
  display.display();
  delay(100);
  
  // Hiện dòng chữ chào mừng2
  display.print("MIMO Scale");
  display.display();

  display.setTextSize(1);             // Draw 2X-scale text

  // Thiết lập 
  setup_hx711();
  
  delay(1000);
}

void loop() {
  loop_hx711();
  // Hiện dòng chữ chào mừng2
  display.clearDisplay();
  display.display();

  display.setCursor(2,0);
  display.print(loadcell_values[0]);
  display.print(",");
  display.print(loadcell_values[1]);
  display.print(",");
  display.print(loadcell_values[2]);
  display.print(",");
  display.print(loadcell_values[3]);
  display.println();
  display.display();
  delay(1000);  
}