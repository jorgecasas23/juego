//
// Created by lonix on 20/11/2025.
//

#include "Golem.h"
#include <iostream>
#include "espadarunica.h"

Golem::Golem()
    : Entidad("Golem", 400, 65) {}

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

Objeto* Golem::soltarLoot() const {
    std::cout << "¡El Golem ha soltado la Espada Runica!" << std::endl;
    return new EspadaRunica("Espada Runica");
}