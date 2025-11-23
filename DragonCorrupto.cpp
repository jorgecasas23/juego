//
// Created by lonix on 20/11/2025.
//

#include "DragonCorrupto.h"
#include <iostream>
#include <algorithm>

DragonCorrupto::DragonCorrupto()
    : Entidad("Zharion", 500, 80) {}

DragonCorrupto::DragonCorrupto(std::string n, int v, int d, int dq)
    : Entidad(n, v, d), DanioQuemadura(dq) {}

DragonCorrupto::~DragonCorrupto() {}

void DragonCorrupto::Atacar(Entidad& objetivo) {
    int danioTotal = danioBase + DanioQuemadura;
    objetivo.RecibirDanio(danioTotal);
    std::cout << nombre << " (Zharion) escupe Fuego. Danio: " << danioTotal << " (Base: " << danioBase
              << " + Quemadura: " << DanioQuemadura << ")" << std::endl;
}

int DragonCorrupto::getDanioQuemadura() const {
    return DanioQuemadura;
}

int DragonCorrupto::getExperiencia() const {
    return experiencia;
}

Objeto* DragonCorrupto::soltarLoot() const {
    return nullptr;
}