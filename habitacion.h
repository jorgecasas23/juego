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
    Habitacion* anterior;
    std::vector<Entidad*> enemigos;
public:
    Habitacion(std::string nombre, std::string descripcion);
    Habitacion(std::string nombre, std::string descripcion, Habitacion* izquierda, Habitacion* derecha, Habitacion* anterior, int contador);
    ~Habitacion();
    std::string getNombre() const;
    std::string getDescripcion() const;
    Habitacion* getIzquierda() const;
    Habitacion* getDerecha() const;
    Habitacion* getAnterior() const;
    std::vector<Entidad*>& getEnemigos();
    void setHIzquierda(Habitacion* izquierda);
    void setHDerecha(Habitacion* derecha);
    void setAnterior(Habitacion* anterior);
};

#endif