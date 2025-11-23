//
// Created by lonix on 20/11/2025.
//

#include "Clon.h"
#include <iostream>
#include <string>

Clon::Clon(const std::string& nombreClonado, int v, int d, int m)
    : Jugador("Clon de " + nombreClonado, v + 100, d + danioExtra, m) {}

Clon::~Clon() {}

void Clon::Atacar(Entidad& objetivo) {
    usarHabilidadE(objetivo);
}

void Clon::usarHabilidadE(Entidad& objetivo) {
    int danioTotal = danioBase * 2;
    if (mana >= costoHabilidadE) {
        mana -= costoHabilidadE;
        objetivo.RecibirDanio(danioTotal);
        std::cout << nombre << " lanza la Explosion Runica. Danio total: " << danioTotal << ". Mana restante: " << mana << std::endl;
    } else {
        objetivo.RecibirDanio(danioBase);
        std::cout << nombre << " ataca debilmente. Danio: " << danioBase << std::endl;
    }
}

Objeto* Clon::soltarLoot() const {
    return nullptr;
}