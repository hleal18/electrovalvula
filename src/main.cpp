#include <PCF8574.h>
#include <Wire.h>

PCF8574 pcf20(0x20);

const byte onboardLed = 13;
const byte PcfButtonLedPin = 0;
const byte PcfLed0 = 0;
const byte PcfLed1 = 1;

unsigned int blinkMillis;
unsigned int buttonMillis;

void setup() {
  Serial.begin(115200);
  pcf20.begin();
}

void loop() {
  delay(1000);
  Serial.println("Alto");
  pcf20.write(PcfLed0, HIGH);
  pcf20.write(PcfLed1, LOW);
  delay(1000);
  Serial.println("Bajo");
  pcf20.write(PcfLed0, LOW);
  pcf20.write(PcfLed1, HIGH);
}