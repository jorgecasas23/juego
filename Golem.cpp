//
// Created by lonix on 20/11/2025.
//

#include "Golem.h"
#include <iostream>
#include <random>

Golem::Golem(std::string n, int v, int d, double pa, int ta) : Entidad(n, v, d), ProbabilidadAturdir(0.5), TurnoAturdido(1)   {}

Golem::~Golem() {}

void Golem::Atacar() {
    std::cout << nombre << " lanza una roca. Danio: " << danioBase;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0, 1);

    if (distrib(gen) < ProbabilidadAturdir) {
        std::cout << " Objetivo aturdido durante " << TurnoAturdido << " turnos." << std::endl;
    } else {
        std::cout << " No alcanzo a aturdir" << std::endl;
    }
}