//
// Created by lonix on 20/11/2025.
//

#include "Golem.h"
#include <iostream>

Golem::Golem()
    : Entidad("Golem de Obsidiana", 400, 65) {}

Golem::Golem(std::string n, int v, int d)
    : Entidad(n, v, d) {}

Golem::~Golem() {}

void Golem::Atacar(Entidad& objetivo) {
    objetivo.RecibirDanio(danioBase);
    std::cout << nombre << " lanza una roca. Danio: " << danioBase << std::endl;
}

int Golem::getExperiencia() const {
    return experiencia;
}