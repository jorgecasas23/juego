//
// Created by lonix on 20/11/2025.
//

#include "Clon.h"
#include <iostream>

Clon::Clon(const std::string& nombreClonado, int v, int d, int m)
    : Jugador("Clon de " + nombreClonado, v, d, m) {
    danioBase += 20; // Mejora su danio base por ser el boss
}
Clon::~Clon() {}
void Clon::atacar() {
    usarHabilidadE();
}
void Clon::usarHabilidadE() {
    int costoE = 40;
    int danioTotal = danioBase * 2;
    if (mana >= costoE) {
        mana -= costoE;
        std::cout << nombre << " lanza la Explosion Runica. Danio total: " << danioTotal << ". Mana restante: " << mana << std::endl;
    } else {
        Jugador::Atacar(); // Si no tiene suficiente maná para E, recurre al ataque base
    }
}