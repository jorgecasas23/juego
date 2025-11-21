//
// Created by lonix on 21/11/2025.
//

#include "EscudoEnergia.h"
#include "Jugador.h"
#include <iostream>

EscudoEnergia::EscudoEnergia(std::string nombre)
    : Objeto(nombre, 0)
{
}

void EscudoEnergia::usarObjeto(Jugador& Objetivo) const {
    const int costoMana = gastoMana;
    const int valorProteccion = proteccion;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        std::cout << "" << Objetivo << " activa  (Habilidad "<< letraAsociada << ") " << std::endl;
        std::cout << "Gana una barrera de " << valorProteccion << " puntos de protección temporal." << std::endl;
        std::cout << "Maná restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo << " no tiene suficiente maná (" << manaActual
                  << ") para activar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}

std::string EscudoEnergia::getLetra() const {
    return letraAsociada;
}