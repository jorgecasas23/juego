//
// Created by lonix on 20/11/2025.
//

#include "DragonCorrupto.h"
#include <iostream>

DragonCorrupto::DragonCorrupto(std::string n, int v, int d, int dq, int tq) : Entidad(n, v, d), DanioQuemadura(dq), TurnosQuemadura(2) {}

DragonCorrupto::~DragonCorrupto() {}

void DragonCorrupto::atacar() {
    std::cout << nombre << " (Zharion) escupe Fuego. Danio: " << danioBase
              << ". Danio de quemadura: " << DanioQuemadura << " por " << TurnosQuemadura
              << " turnos." << std::endl;
}