//
// Created by lonix on 21/11/2025.
//

#include "pocionmana.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

PocionMana::PocionMana(std::string nombre)
    : Objeto(nombre, "Restaura una cantidad de mana.") {}

void PocionMana::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int manaRestaurado = 150;

    int manaActual = Objetivo.getMana();
    int nuevoMana = manaActual + manaRestaurado;

    Objetivo.setMana(nuevoMana);

    std::cout << Objetivo.getNombre() << " recupera " << manaRestaurado << " de mana. Mana actual: " << nuevoMana << std::endl;
}