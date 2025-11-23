//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_ENTIDAD_H
#define JDI_ENTIDAD_H
#include <string>
#include "objeto.h"

class Entidad {
protected:
    std::string nombre;
    int vida;
    int danioBase;
public:
    Entidad(std::string n, int v, int d);
    virtual ~Entidad();

    virtual void Atacar(Entidad& objetivo) = 0;
    virtual void RecibirDanio(int d);
    virtual Objeto* soltarLoot() const = 0;

    bool EstaVivo() const;
    std::string getNombre() const;
    int getDanioBase() const;
    int getVida() const;
    void setVida(int nuevaVida);
};

#endif