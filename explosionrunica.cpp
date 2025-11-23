//
// Created by lonix on 21/11/2025.
//
#include "explosionrunica.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

ExplosionRunica::ExplosionRunica(std::string nombre)
    : Objeto(nombre + " (E)", "Gran daño de area a un solo objetivo.") {}

std::string ExplosionRunica::getLetra() const {
    return letraAsociada;
}

void ExplosionRunica::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int danioHabilidad = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);
        Enemigo.RecibirDanio(danioHabilidad);

        std::cout << "** " << Objetivo.getNombre() << " lanza Explosion Runica ("
                  << letraAsociada << ")" << std::endl;
        std::cout << "Danio hecho: " << danioHabilidad << " al enemigo " << Enemigo.getNombre() << std::endl;
        std::cout << "Mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo.getNombre() << " no tiene suficiente mana (" << manaActual
                  << ") para lanzar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}
