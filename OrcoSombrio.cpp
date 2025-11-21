//
// Created by lonix on 20/11/2025.
//

#include "OrcoSombrio.h"
#include <iostream>
#include <algorithm>

OrcoSombrio::OrcoSombrio(std::string n, int v, int d, int f)
    : nombre(n), vida(v), danioBase(d) {}

OrcoSombrio::~OrcoSombrio() {}

void OrcoSombrio::RecibirDanio(int d) {
    vida = std::max(0, vida - d);
    std::cout << nombre << " recibe " << d << " de danio. Vida: " << vida << std::endl;
}

void OrcoSombrio::atacar() {
    int danioTotal = danioBase;
    std::cout << nombre << " Gruk’Thar ataca con fuerza bruta. Danio total: " << danioTotal << " (ignora parte del escudo)." << std::endl;
}

std::string OrcoSombrio::getNombre() const{
    return nombre;
}

int OrcoSombrio::getDanioBase() const{
    return danioBase;
}

int OrcoSombrio::getExperiencia() const{
    return experiencia;
}