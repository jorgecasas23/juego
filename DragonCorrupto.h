//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_DRAGONCORRUPTO_H
#define JDI_DRAGONCORRUPTO_H
#include <string>
#include <algorithm>
#include "Entidad.h"

class DragonCorrupto : public Entidad{
private:
    std::string nombre;
    int vida = 500;
    int danioBase = 80;
    int DanioQuemadura = 30;
    int experiencia = 40;


public:
    DragonCorrupto();
    DragonCorrupto(std::string n, int v, int d, int dq);
    ~DragonCorrupto();

    void RecibirDanio(int d);
    std::string getNombre() const;
    int getDanioBase() const;
    int getVida() const;
    int getDanioQuemadura() const;
    int getExperiencia() const;

    void atacar();
};

#endif //JDI_DRAGONCORRUPTO_H