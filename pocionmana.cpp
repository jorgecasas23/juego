//
// Created by lonix on 21/11/2025.
//

#include "pocionmana.h"
#include "Jugador.h"
#include <iostream>

PocionMana::PocionMana(std::string nombre)
    : Objeto(nombre, 0)
{
}

void PocionMana::usarObjeto(Jugador& Objetivo) const {
    int manaRestaurado = 150;

    int manaActual = jugador.getMana();
    int nuevoMana = manaActual + manaRestaurado;

    jugador.setMana(nuevoMana);

    std::cout << jugador.getNombre() << " recupera " << manaRestaurado << " de maná. Maná actual: " << nuevoMana << std::endl;

    Inventario.EliminarObjeto(getNombre());
}