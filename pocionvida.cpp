//
// Created by lonix on 21/11/2025.
//
#include "pocionvida.h"
#include "Jugador.h"
#include "Entidad.h"
#include <iostream>

PocionVida::PocionVida(std::string nombre)
    : Objeto(nombre, "Restaura una cantidad de vida.") {}

void PocionVida::usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const {
    const int VidaRestaurada = 200;

    int vidaActual = Objetivo.getVida();
    int nuevaVida = vidaActual + VidaRestaurada;

    Objetivo.setVida(nuevaVida);

    std::cout << Objetivo.getNombre() << " recupera " << VidaRestaurada << " de vida al usar la pocion de vida. Vida actual: " << nuevaVida << std::endl;
}