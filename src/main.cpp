#include <PCF8574.h>
#include <Electrovalvula.h>

// A4 - SDA
// A5 - SCL
PCF8574 pcf20(0x20);
Electrovalvula valvula1(0);
Electrovalvula valvula2(1);

void setup() {
  Serial.begin(9600);
  pcf20.begin();
}

void loop() {
  delay(1000);
  valvula1.abrir(pcf20);
  Serial.println("Valvula 1 abierta");
  Serial.print("Estado: ");
  Serial.println(valvula1.getEstado());
  Serial.print("Pin: ");
  Serial.println(valvula1.getPin());
  delay(1000);
  valvula2.abrir(pcf20);
  Serial.println("Valvula 2 abierta");
  Serial.print("Estado: ");
  Serial.println(valvula2.getEstado());
  Serial.print("Pin: ");
  Serial.println(valvula2.getPin());
  delay(1000);
  valvula1.cerrar(pcf20);
  Serial.println("Valvula 1 cerrada");
  Serial.print("Estado: ");
  Serial.println(valvula1.getEstado());
  Serial.print("Pin: ");
  Serial.println(valvula1.getPin());
  delay(1000);
  valvula2.cerrar(pcf20);
  Serial.println("Valvula 2 cerrada");
  Serial.print("Estado: ");
  Serial.println(valvula2.getEstado());
  Serial.print("Pin: ");
  Serial.println(valvula2.getPin());
  delay(1000);
}