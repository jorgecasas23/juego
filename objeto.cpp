#include "Objeto.h"

Objeto::Objeto(std::string nombre, std::string descripcionObjeto){
    this->nombre = nombre;
    this->descripcionObjeto = descripcionObjeto;
}

std::string Objeto::getNombre() const{
    return this->nombre;
}

std::string Objeto::getDescripcion() const{
    return this->descripcionObjeto;
}