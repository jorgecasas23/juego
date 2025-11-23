#include "habitacion.h"
#include "Entidad.h"
#include <iostream>

Habitacion::Habitacion(std::string nombre, std::string descripcion){
    this->nombreHabitacion = nombre;
    this->descripcionHabitacion = descripcion;
    izquierda = nullptr;
    derecha = nullptr;
}

Habitacion::Habitacion(std::string nombre, std::string descripcion, Habitacion* izquierda, Habitacion* derecha, int contador, const std::string& nombreJugador){
    this->nombreHabitacion = nombre;
    this->descripcionHabitacion = descripcion;
    this->izquierda = izquierda;
    this->derecha = derecha;

    // Logica de poblacion de enemigos
    if (contador == 1){
        enemigos.push_back(new OrcoSombrio());
    }
    else if (contador == 2){
        enemigos.push_back(new OrcoSombrio());
        enemigos.push_back(new OrcoSombrio());
    }
    else if (contador == 3){
        enemigos.push_back(new OrcoSombrio());
        enemigos.push_back(new Golem());
    }
    else if (contador == 4){
        enemigos.push_back(new Golem());
        enemigos.push_back(new Golem());
    }
    else if (contador == 5){
        enemigos.push_back(new DragonCorrupto());
        enemigos.push_back(new OrcoSombrio());
    }
    else if (contador == 6){
        enemigos.push_back(new DragonCorrupto());
        enemigos.push_back(new Golem());
    }
    else if (contador == 7){
        enemigos.push_back(new Clon(nombreJugador, 500, 75, 300));
    }
}

Habitacion::~Habitacion(){
    for(auto* enemigo : enemigos){
        delete enemigo;
    }
    enemigos.clear();
}

std::string Habitacion::getNombre() const{
    return nombreHabitacion;
}

std::string Habitacion::getDescripcion() const{
    return descripcionHabitacion;
}

Habitacion* Habitacion::getIzquierda() const{
    return izquierda;
}

Habitacion* Habitacion::getDerecha() const{
    return derecha;
}

std::vector<Entidad*>& Habitacion::getEnemigos(){
    return enemigos;
}

void Habitacion::setHIzquierda(Habitacion* izquierda){
    this->izquierda = izquierda;
}

void Habitacion::setHDerecha(Habitacion* derecha){
    this->derecha = derecha;
}
