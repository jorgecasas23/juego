//
// Created by lonix on 21/11/2025.
//
#include "PocionVida.h"
#include "Jugador.h"
#include <iostream>

PocionVida::PocionVida(std::string nombre)
    : Objeto(nombre, 0)
{
}

void usarObjeto(Jugador& objetivo) {
    int VidaRestaurada = 200;

    int vidaActual = jugador.getVida();
    int nuevaVida = vidaActual + VidaRestaurada;

    jugador.setVida(nuevaVida);

    std::cout << jugador << " recupera " << VidaRestaurada << " de vida al usar la pocion de vida" << std::endl;

    Inventario.EliminarObjeto(getNombre());
}