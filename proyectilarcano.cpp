#include "proyectilarcano.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

ProyectilArcano::ProyectilArcano(std::string nombre)
    : Objeto(nombre + " (Q)", "Ataque magico de bajo coste y daño moderado.") {}

std::string ProyectilArcano::getLetra() const {
    return letraAsociada;
}

void ProyectilArcano::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int costoMana = gastoMana;
    const int daniohacer = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        Enemigo.RecibirDanio(daniohacer);

        std::cout << Objetivo.getNombre() << " usa Proyectil Arcano (" << letraAsociada << ")" << std::endl;
        std::cout << "Hace " << daniohacer << " puntos de daño al enemigo " << Enemigo.getNombre() << std::endl;
        std::cout << "Mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo.getNombre() << " no tiene suficiente mana (" << manaActual
                  << ") para usar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}

int ProyectilArcano::getProteccion() const {
    return proteccion;
}
