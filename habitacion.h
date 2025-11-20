#ifndef HABITACION_H
#define HABITACION_H


#include <string>

class Habitacion{
	private:
		std::string nombreHabitacion;
		std::string descripcionHabitacion;
		Habitacion* izquierda;
		Habitacion* derecha;
		
	public:
		Habitacion(std::string nombre, std::string descripcion);
		Habitacion(std::string nombre, std::string descripcion, Habitacion* izquierda, Habitacion* derecha);
		std::string getNombre() const;
		std::string getDescripcion() const;
		void setHIzquierda(Habitacion* izquierda);
		void setHDerecha(Habitacion* derecha);


};

#endif