#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <vector>
#include "Entidad.h"
#include "OrcoSombrio.h"
#include "Golem.h"
#include "DragonCorrupto.h"
#include "Clon.h"

class Habitacion{
private:
	std::string nombreHabitacion;
	std::string descripcionHabitacion;
	Habitacion* izquierda;
	Habitacion* derecha;
	std::vector<Entidad*> enemigos;
public:
	Habitacion(std::string nombre, std::string descripcion);
	Habitacion(std::string nombre, std::string descripcion, Habitacion* izquierda, Habitacion* derecha, int contador, const std::string& nombreJugador);
	~Habitacion();
	std::string getNombre() const;
	std::string getDescripcion() const;
	Habitacion* getIzquierda() const;
	Habitacion* getDerecha() const;
	std::vector<Entidad*>& getEnemigos();
	void setHIzquierda(Habitacion* izquierda);
	void setHDerecha(Habitacion* derecha);
};

#endif