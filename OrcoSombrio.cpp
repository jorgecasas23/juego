//
// Created by lonix on 20/11/2025.
//

#include "OrcoSombrio.h"
#include <iostream>

OrcoSombrio::OrcoSombrio(std::string n, int v, int d, int f) : Entidad(n, v, d), Furia(f) {}
OrcoSombrio::~OrcoSombrio() {}

void OrcoSombrio::atacar() {
    int danioTotal = danioBase + Furia;
    std::cout << nombre << " Gruk’Thar ataca con fuerza bruta. Danio total: " << danioTotal << " (ignora parte del escudo)." << std::endl;
}