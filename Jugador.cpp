//
// Created by lonix on 20/11/2025.
//

#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string n, int v, int d, int m)
    : Entidad(n, v, d),
      mana(m),
      habitacionActual("Ruinas del Nexo")
{
    inventario.push_back(Objeto("Pocion de Vida", 50));
}

Jugador::~Jugador() {}
void Jugador::Atacar() {
    int costoQ = 10;
    if (mana >= costoQ) {
        mana -= costoQ;
        std::cout << nombre << " Lanza el Proyectil Arcano (Q). Danio moderado: " << danioBase << ". Mana restante: " << mana << std::endl;
    } else {
        std::cout << nombre << " No tiene suficiente mana para Proyectil Arcano (Q)." << std::endl;
    }
}

void Jugador::UsarHabilidadW() {
    int costoW = 15;
    if (mana >= costoW) {
        mana -= costoW;
        std::cout << nombre << " Activa Escudo fragmentado (W), reduciendo danio. Mana restante: " << mana << std::endl;
    } else {
        std::cout << nombre << " No puede usar el Escudo fragmentado (W)." << std::endl;
    }
}

void Jugador::UsarHabilidadE() {
    int costoE = 40;
    int danioE = danioBase * 2;
    if (mana >= costoE) {
        mana -= costoE;
        std::cout << nombre << " Lanza la Explosion Rúnica (E). Gran Danio: " << danioE << ". Mana restante: " << mana << std::endl;
    } else {
        std::cout << nombre << " No tiene suficiente mana para Explosion Rúnica (E)." << std::endl;
    }
}
void Jugador::setMana(int nuevoMana) {
    mana = nuevoMana;
    std::cout << nombre << " Tu mana cambio a: " << mana << std::endl;
}
void Jugador::setVida(int nuevaVida) {
    vida = nuevaVida;
    std::cout << nombre << "Tu vida cambio a: " << vida << std::endl;
}
int Jugador::getMana() const {
    return mana;
}

std::string Jugador::getHabitacion() const {
    return habitacionActual;
}