//
// Created by lonix on 21/11/2025.
//

#include "escudoenergia.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

EscudoEnergia::EscudoEnergia(std::string nombre)
    : Objeto(nombre + " (W)", "Otorga una barrera de proteccion.") {}

std::string EscudoEnergia::getLetra() const {
    return letraAsociada;
}

void EscudoEnergia::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int valorProteccion = proteccion;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        std::cout << Objetivo.getNombre() << " activa Escudo de Energia (Habilidad "<< letraAsociada << ")" << std::endl;
        std::cout << "Gana una barrera de " << valorProteccion << " puntos de proteccion temporal." << std::endl;
        std::cout << "Mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo.getNombre() << " no tiene suficiente mana (" << manaActual
                  << ") para activar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}