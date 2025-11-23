//
// Created by lonix on 20/11/2025.
//

#include "Entidad.h"
#include <iostream>
#include <algorithm>

Entidad::Entidad(std::string n, int v, int d) : nombre(n), vida(v), danioBase(d) {}

Entidad::~Entidad() {}

void Entidad::RecibirDanio(int d) {
    vida = std::max(0, vida - d);
    std::cout << nombre << " recibe " << d << " de danio. Vida restante: " << vida << std::endl;
}

bool Entidad::EstaVivo() const {
    return vida > 0;
}

std::string Entidad::getNombre() const {
    return nombre;
}

int Entidad::getDanioBase() const {
    return this->danioBase;
}

int Entidad::getVida() const {
    return vida;
}

void Entidad::setVida(int nuevaVida) {
    vida = nuevaVida;
}
