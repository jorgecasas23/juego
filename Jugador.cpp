//
// Created by lonix on 20/11/2025.
//

#include "Jugador.h"
#include <iostream>
#include <algorithm>

Jugador::Jugador(std::string n, int v, int d, int m)
    : nombre(n), vida(v), danioBase(d),
      mana(m),
      habitacionActual("Ruinas del Nexo")
{
}
Jugador::~Jugador() {}

void Jugador::RecibirDanio(int d) {
    vida = std::max(0, vida - d);
    std::cout << nombre << " recibe " << d << " de danio. Vida: " << vida << std::endl;
}

void Jugador::Atacar() {
    int costoQ = 20;
    if (mana >= costoQ) {
        mana -= costoQ;
        std::cout << nombre << " Lanza el Proyectil Arcano (Q). Danio moderado: " << danioBase << ". Mana restante: " << mana << std::endl;
    } else {
        std::cout << nombre << " No tiene suficiente mana para Proyectil Arcano (Q)." << std::endl;
    }
}

void Jugador::UsarHabilidadW() {
    int costoW = 30;
    if (mana >= costoW) {
        mana -= costoW;
        std::cout << nombre << " Activa Escudo fragmentado (W), reduciendo danio. Mana restante: " << mana << std::endl;
    } else {
        std::cout << nombre << " No puede usar el Escudo fragmentado (W)." << std::endl;
    }
}

void Jugador::UsarHabilidadE() {
    int costoE = 100;
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

int Jugador::getExperiencia() const{
    return experiencia;
}

void Jugador::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

std::string Jugador::getHabitacion() const {
    return habitacionActual;
}