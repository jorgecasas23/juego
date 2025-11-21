//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_JUGADOR_H
#define JDI_JUGADOR_H
#include "Entidad.h"
#include "Objeto.h"
#include <vector>

class Jugador : public Entidad {
protected:
    int mana;
private:
    std::vector<Objeto> inventario;
    std::string habitacionActual; // Atributo de la habitacion
public:
    Jugador(std::string n, int v, int d, int m);
    ~Jugador() override;

    void Atacar();
    void UsarHabilidadW();
    void UsarHabilidadE();

    int getMana() const;
    std::string getHabitacion() const; // Getter para la habitacion
    void setHabitacion(std::string nuevaHabitacion);// Setter para la habitacion
    

};


#endif //JDI_JUGADOR_H
