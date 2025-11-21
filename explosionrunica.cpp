//
// Created by lonix on 21/11/2025.
//
#include "ExplosionRunica.h"
#include "Jugador.h"
#include <iostream>

ExplosionRunica::ExplosionRunica(std::string nombre)
    : Objeto(nombre, 0)
{
}

void ExplosionRunica::usarObjeto(Jugador& Objetivo) const {
    const int costoMana = gastoMana;
    const int danioHabilidad = danio;

    int manaActual = jugador.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        int danioTotal = jugador.getDanioBase() + danioHabilidad;

        jugador.setMana(nuevoMana);

        std::cout << "** " << jugador() << " lanza " << getNombre() << " (Habilidad "
                  << letraAsociada << ")! **" << std::endl;
        std::cout << "Danio masivo infligido: " << danioTotal << "." << std::endl;
        std::cout << "Maná restante: " << nuevoMana << std::endl;
    } else {
        std::cout << jugador() << " no tiene suficiente maná (" << manaActual
                  << ") para lanzar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}

std::string ExplosionRunica::getLetra() const {
    return letraAsociada;
}