//
// Created by lonix on 20/11/2025.
//

#include "Objeto.h"

Objeto::Objeto(std::string n, int v) : nombre(n), valor(v) {}

std::string Objeto::getNombre() const {
    return nombre;
}