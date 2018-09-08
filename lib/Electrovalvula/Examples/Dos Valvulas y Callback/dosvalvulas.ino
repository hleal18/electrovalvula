#include <PCF8574.h>
#include <Electrovalvula.h>

PCF8574 pcf20(0x20);
Electrovalvula valvula1(0);
Electrovalvula valvula2(1);

void setup()
{
  Serial.begin(9600);
  pcf20.begin();
}

void loop()
{
  delay(1000);
  valvula1.abrir(pcf20);
  valvula2.cerrar(pcf20);
  delay(1000);
  valvula1.cerrar(pcf20, []() {
    Serial.println("Cerrando valvula 1 con callback");
  });
  valvula2.abrir(pcf20, []() {
    Serial.println("Abriendo valvula 2 con callback");
  });
}