//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_DRAGONCORRUPTO_H
#define JDI_DRAGONCORRUPTO_H
#include <string>
#include "Entidad.h"

class DragonCorrupto : public Entidad{
private:
    int DanioQuemadura = 30;
    int experiencia = 40;
public:
    DragonCorrupto();
    DragonCorrupto(std::string n, int v, int d, int dq);
    ~DragonCorrupto() override;

    void Atacar(Entidad& objetivo) override;
    int getDanioQuemadura() const;
    int getExperiencia() const;
    Objeto* soltarLoot() const override;
};

#endif