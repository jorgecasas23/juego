//
// Created by lonix on 22/11/2025.
//

#include "corazontormenta.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>
#include <string>

CorazonTormenta::CorazonTormenta(std::string nombre)
    : Objeto(nombre + " (E)", "Gran daño de area y restauracion de vida si es necesario.") {}

std::string CorazonTormenta::getLetra() const {
    return letraAsociada;
}

void CorazonTormenta::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int daniohacer = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        Enemigo.RecibirDanio(daniohacer);

        std::cout << Objetivo.getNombre() << " usa Corazon de la tormenta (" << letraAsociada << ")" << std::endl;
        std::cout << "Hace " << daniohacer << " puntos de daño al enemigo " << Enemigo.getNombre() << std::endl;
        std::cout << "Mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo.getNombre() << " no tiene suficiente mana (" << manaActual
                  << ") para usar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}