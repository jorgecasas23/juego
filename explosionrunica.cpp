//
// Created by lonix on 21/11/2025.
//
#include "ExplosionRunica.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

ExplosionRunica::ExplosionRunica(std::string nombre)
    : Objeto(nombre, 0)
{
}

void ExplosionRunica::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int danioHabilidad = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);
        Enemigo.recibirDanio(daniohacer);

        
        std::cout << "** " << Objetivo() << " lanza Explosion Runica ("
                  << letraAsociada << ")" << std::endl;
        std::cout << "Danio hecho: " << daniohacer << "al enemigo"<< Enemigo.getNombre() << std::endl;
        std::cout << "Mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo() << " no tiene suficiente mana (" << manaActual
                  << ") para lanzar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}

std::string ExplosionRunica::getLetra() const {
    return letraAsociada;

}
