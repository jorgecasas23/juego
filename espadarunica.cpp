//
// Created by lonix on 21/11/2025.
//
#include "EspadaRunica.h"
#include "Jugador.h"
#include <iostream>

EspadaRunica::EspadaRunica(std::string nombre)
    : Objeto(nombre, 0)
{
}

void EspadaRunica::usarObjeto(Jugador& Objetivo) const {
    const int danioExtra = danio;

    int danioTotal = Objetivo.getDanioBase() + danioExtra;

    std::cout << "" << Objetivo() << " ataca con " << getNombre() << " (Habilidad "
              << letraAsignada << ")" << std::endl;
    std::cout << "Danio infligido: " << danioTotal << " (Base: " << Objetivo.getDanioBase()
              << " + Arma: " << danioExtra << ")." << std::endl;
    std::cout << "El arma proporciona " << proteccion << " puntos extra de defensa." << std::endl;
}

int EspadaRunica::getProteccion() const {
    return proteccion;
}

std::string EspadaRunica::getLetra() const {
    return letraAsignada;
}