//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_JUGADOR_H
#define JDI_JUGADOR_H
#include <string>
#include <vector>
#include "Entidad.h"
#include "objeto.h"

class Habitacion;

class Jugador : public Entidad{
protected:
    int mana;
    int experiencia;
private:
    std::vector<Objeto*> inventario;
    Habitacion* habitacionActual;
public:
    Jugador(std::string n);
    Jugador(std::string n, int v, int d, int m);
    ~Jugador() override;

    void Atacar(Entidad& objetivo) override;
    void agregarObjeto(Objeto* objeto);
    void usarObjeto(char letra, Entidad& enemigo);

    int getMana() const;
    void setMana(int nuevoMana);
    void setVida(int nuevaVida);
    int getExperiencia() const;
    void setExperiencia(int experiencia);
    Habitacion* getHabitacion() const;
    void setHabitacion(Habitacion* nuevaHabitacion);

    void mostrarInventario() const;
    void recogerObjeto(Objeto* objeto);
    Objeto* soltarLoot() const override;
};

#endif