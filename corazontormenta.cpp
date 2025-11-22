//
// Created by lonix on 22/11/2025.
//

#include "corazontormenta.h"
#include "Jugador.h"
#include <iostream>
#include <string>
#include "Entidad.h"

CorazonTormenta::CorazonTormenta(std::string nombre)
    : Object(nombre, 0)
{
}

void CorazonTormenta::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int daniohacer = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        Enemigo.recibirDanio(daniohacer);

        std::cout << "" << Objetivo << " usa Corazon de la tormenta (" << letraAsociada << ") " << std::endl;
        std::cout << "Hace " << daniohacer << " puntos de daño al enemigo" << Enemigo.getNombre() << std::endl;
        std::cout << "mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo << " no tiene suficiente mana (" << manaActual
                  << ") para usar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}

std::string CorazonTormenta::getLetra() const {
    return letraAsociada;
}