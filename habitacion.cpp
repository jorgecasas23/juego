#include "habitacion.h"


Habitacion::Habitacion(std::string nombre, std::descripcion){
	this->nombreHabitacion = nombre;
	this->descripcionHabitacion = descripcion;
	izquierda = NULL;
	derecha = NULL;
}

Habitacion::Habitacion(std::string nombre, std::descripcion, Habitacion* izquierda, Habitacion* derecha, int contador){
	this->nombreHabitacion = nombre;
	this->descripcionHabitacion = descripcion;
	this->izquierda = izquierda;
	this->derecha = derecha;
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
		enemigos.push_back(new Clon());
	}

}

Habitacion::~Habitacion(){
	for(auto* enemigo : enemigos){
		delete enemigo;
	}
	enemigos.clear();
}

std::string Habitacion::getNombre() const{
	return this->nombreHabitacion;
}

std::string Habitacion::getDescripcion() const{
	return this->descripcionHabitacion;
}

Habitacion* Habitacion::getIzquierda() const{
	return this->izquierda;
}

Habitacion* Habitacion::getDerecha() const{
	return this->derecha;
}

void Habitacion::setHIzquierda(Habitacion* izquierda){
	this->izquierda = izquierda;
}

void Habitacion::setHDerecha(Habitacion* derecha){
	this->derecha = derecha;
}
