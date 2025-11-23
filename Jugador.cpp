//
// Created by lonix on 20/11/2025.
//

#include "Jugador.h"
#include "habitacion.h"
#include <iostream>
#include <algorithm>

Jugador::Jugador(std::string n)
    : Entidad(n, 500, 75), mana(300), experiencia(0), habitacionActual(nullptr) {}

Jugador::Jugador(std::string n, int v, int d, int m)
    : Entidad(n, v, d), mana(m), experiencia(0), habitacionActual(nullptr) {}

Jugador::~Jugador() {
    for (Objeto* objeto : inventario) {
        delete objeto;
    }
    inventario.clear();
}

void Jugador::Atacar(Entidad& objetivo) {
    objetivo.RecibirDanio(danioBase);
    std::cout << nombre << " ataca con golpe base. Danio: " << danioBase << std::endl;
}

void Jugador::agregarObjeto(Objeto* objeto) {
    inventario.push_back(objeto);
    std::cout << nombre << " obtiene " << objeto->getNombre() << std::endl;
}

void Jugador::usarObjeto(char letra, Entidad& enemigo) {
    std::string letraStr(1, letra);
    for (size_t i = 0; i < inventario.size(); ++i) {
        const Objeto* obj = inventario[i];
        if (obj->getNombre().find("(" + letraStr + ")") != std::string::npos ||
            (obj->getNombre() == "Pocion de Vida" && letra == 'V') ||
            (obj->getNombre() == "Pocion de Mana" && letra == 'M')) {
            
            obj->usarObjeto(*this, enemigo);
            
            if (obj->getNombre().find("Pocion") != std::string::npos) {
                delete inventario[i];
                inventario.erase(inventario.begin() + i);
            }
            return;
        }
    }
    std::cout << "No tienes un objeto/habilidad asignada a la tecla " << letra << "." << std::endl;
}

void Jugador::mostrarInventario() const {
    std::cout << "\n--- Inventario de " << nombre << " ---" << std::endl;
    if (inventario.empty()) {
        std::cout << "Inventario vacio." << std::endl;
        return;
    }
    for (const auto& objeto : inventario) {
        std::cout << "- " << objeto->getNombre() << ": " << objeto->getDescripcion() << std::endl;
    }
    std::cout << "---------------------------------\n" << std::endl;
}

int Jugador::getMana() const {
    return mana;
}

void Jugador::setMana(int nuevoMana) {
    mana = nuevoMana;
    std::cout << nombre << " Tu mana cambio a: " << mana << std::endl;
}

void Jugador::setVida(int nuevaVida) {
    vida = nuevaVida;
}

int Jugador::getExperiencia() const {
    return experiencia;
}

void Jugador::setExperiencia(int exp) {
    experiencia = exp;
}

Habitacion* Jugador::getHabitacion() const {
    return habitacionActual;
}

void Jugador::setHabitacion(Habitacion* nuevaHabitacion) {
    habitacionActual = nuevaHabitacion;
    std::cout << "\n*** Entras a: " << habitacionActual->getNombre() << " ***" << std::endl;
}

void Jugador::recogerObjeto(Objeto* objeto) {
    if (objeto != nullptr) {
        inventario.push_back(objeto);
        std::cout << nombre << " ha recogido: " << objeto->getNombre() << std::endl;
    }
}

Objeto* Jugador::soltarLoot() const {
    return nullptr;
}