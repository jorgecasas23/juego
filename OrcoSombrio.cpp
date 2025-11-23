//
// Created by lonix on 20/11/2025.
//

#include "OrcoSombrio.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "pocionvida.h"
#include "pocionmana.h"

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

Objeto* OrcoSombrio::soltarLoot() const {
    int chance = rand() % 100;

    if (chance < 30) {
        int itemType = rand() % 2;
        
        if (itemType == 0) {
            std::cout << "¡El Orco Sombrio ha soltado una Pocion de Vida!" << std::endl;
            return new PocionVida("Pocion de Vida");
        } else {
            std::cout << "¡El Orco Sombrio ha soltado una Pocion de Mana!" << std::endl;
            return new PocionMana("Pocion de Mana");
        }
    }
    
    return nullptr;
}