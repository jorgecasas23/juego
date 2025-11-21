//
// Created by lonix on 20/11/2025.
//

#include "Golem.h"
#include <iostream>

Golem::Golem(){
    
}

Golem::Golem(std::string n, int v, int d)
    : nombre(n), vida(v), danioBase(d)
{}

Golem::~Golem() {}

void Golem::RecibirDanio(int d) {
    vida = std::max(0, vida - d);
    std::cout << nombre << " recibe " << d << " de danio. Vida: " << vida << std::endl;
}

void Golem::Atacar() {
    std::cout << nombre << " lanza una roca. Danio: " << danioBase;
}

int Golem::getExperiencia(){
    return experiencia;
}