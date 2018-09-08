#include "Electrovalvula.h"

Electrovalvula::Electrovalvula(uint8_t _pin, uint8_t _estado)
    : pin(_pin), estado(_estado) {}

Electrovalvula::~Electrovalvula() {}

void Electrovalvula::abrir(PCF8574& _pcf)
{
    _pcf.write(this->pin, HIGH);
    this->estado = ACTIVADO;
}

void Electrovalvula::abrir(PCF8574& _pcf, void (*_callback)(void))
{
    this->abrir(_pcf);
    if (_callback != 0)
    {
        _callback();
    }
}

void Electrovalvula::cerrar(PCF8574& _pcf)
{
    _pcf.write(this->pin, LOW);
    this->estado = DESACTIVADO;
}

void Electrovalvula::cerrar(PCF8574& _pcf, void (*_callback)(void))
{
    this->cerrar(_pcf);
    if (_callback != 0)
    {
        _callback();
    }
}