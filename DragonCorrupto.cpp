//
// Created by lonix on 20/11/2025.
//

#include "DragonCorrupto.h"
#include <iostream>
#include <algorithm>

DragonCorrupto::DragonCorrupto(std::string n, int v, int d, int dq)
    : nombre(n), vida(v), danioBase(d), DanioQuemadura(dq)
{}

DragonCorrupto::~DragonCorrupto() {}

void DragonCorrupto::RecibirDanio(int d) {
    vida = std::max(0, vida - d);
    std::cout << nombre << " recibe " << d << " de danio. Vida: " << vida << std::endl;
}

void DragonCorrupto::atacar() {
    std::cout << nombre << " (Zharion) escupe Fuego. Danio: " << danioBase
              << ". Danio de quemadura: " << DanioQuemadura << std::endl;
}