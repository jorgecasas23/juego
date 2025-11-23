//
// Created by lonix on 21/11/2025.
//
#include "espadarunica.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

EspadaRunica::EspadaRunica(std::string nombre)
    : Objeto(nombre + " (Q)", "Ataque cuerpo a cuerpo. Proporciona defensa extra.") {}

std::string EspadaRunica::getLetra() const {
    return letraAsignada;
}

void EspadaRunica::usarObjeto(Jugador& jugador, Entidad& enemigo) const {
    const int danioExtra = danio;

    int danioTotal = jugador.getDanioBase() + danioExtra;
    enemigo.RecibirDanio(danioTotal);

    std::cout << jugador.getNombre() << " ataca con " << getNombre() << " (Habilidad "
              << letraAsignada << ")" << std::endl;
    std::cout << "Danio infligido: " << danioTotal << " (Base: " << jugador.getDanioBase()
              << " + Arma: " << danioExtra << ")." << std::endl;
    std::cout << "El arma proporciona " << proteccion << " puntos extra de defensa (no implementado en esta version)." << std::endl;
}

int EspadaRunica::getProteccion() const {
    return proteccion;
}