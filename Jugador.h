//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_JUGADOR_H
#define JDI_JUGADOR_H
#include <string>
#include "Objeto.h"
#include "Entidad.h"
#include <vector>

class Jugador : public Entidad{
protected:
    std::string nombre;
    int vida = 500;
    int danioBase = 75;
    int mana = 300;
    int experiencia = 0;
private:
    std::vector<Objeto> inventario;
    std::string habitacionActual;
public:
    Jugador(std::string n, int v, int d, int m);
    ~Jugador();

    void RecibirDanio(int);
    bool EstaVivo() const;
    int getDanioBase() const;
    int getVida() const;

    void Atacar();
    void UsarHabilidadW();
    void UsarHabilidadE();
    void setVida(int nuevaVida);
    int getMana() const;
    void setMana(int nuevoMana);
    int getExperiencia();
    void setExperiencia(int experiencia);
    std::string getHabitacion() const;
};

#endif //JDI_JUGADOR_H