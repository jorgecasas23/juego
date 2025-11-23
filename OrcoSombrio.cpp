//
// Created by lonix on 20/11/2025.
//

#include "OrcoSombrio.h"
#include <iostream>
#include <algorithm>

OrcoSombrio::OrcoSombrio()
    : Entidad("Gruk’Thar", 250, 50) {}

OrcoSombrio::OrcoSombrio(std::string n, int v, int d)
    : Entidad(n, v, d) {}

OrcoSombrio::~OrcoSombrio() {}

void OrcoSombrio::Atacar(Entidad& objetivo) {
    int danioTotal = danioBase;
    objetivo.RecibirDanio(danioTotal);
    std::cout << nombre << " ataca con fuerza bruta. Danio total: " << danioTotal << std::endl;
}

int OrcoSombrio::getExperiencia() const {
    return experiencia;
}