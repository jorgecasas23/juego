#include "habitacion.h"


Habitacion::Habitacion(std::string nombre, std::descripcion){
	this->nombre = nombre;
	this->descripcion = descripcion;
	izquierda = NULL;
	derecha = NULL;
}

Habitacion::Habitacion(std::string nombre, std::descripcion, Habitacion* izquierda, Habitacion* derecha){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->izquierda = izquierda;
	this->derecha = derecha;
}

std::string Habitacion::getNombre() const{
	return this->nombreHabitacion;
}

std::string Habitacion::getDescripcion() const{
	return this->descripcionHabitacion;
}

void Habitacion::setIzquierda(Habitacion* izquierda){
	this->izquierda = izquierda;
}

void Habitacion::setDerecha(Habitacion* derecha){
	this->derecha = derecha;
}
