#ifndef ELECTROVALVULA_H

#define ELECTROVALVULA_H

#include <PCF8574.h>
#include <Arduino.h>

class Electrovalvula
{
private:
  uint8_t estado;
  uint8_t pin;

public:
  const static uint8_t ACTIVADO = 1;
  const static uint8_t DESACTIVADO = 0;

  Electrovalvula(uint8_t _pin, uint8_t _estado = DESACTIVADO);
  ~Electrovalvula();

  void abrir(PCF8574 _pcf);
  void abrir(PCF8574 _pcf, void (*_callback)(void));

  void cerrar(PCF8574 _pcf);
  void cerrar(PCF8574 _pcf, void (*_callback)(void));

  inline uint8_t getEstado() { return this->estado; }
  inline void setEstado(uint8_t _estado)
  {
    if (estado == this->ACTIVADO || estado == this->DESACTIVADO)
    {
      this->estado = _estado;
    }
  }

  inline uint8_t getPin() { return this->pin; }
  inline void setPin(uint8_t _pin) { this->pin = pin; }
};

#endif