//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_GOLEM_H
#define JDI_GOLEM_H
#include <string>
#include "Entidad.h"

class Golem : public Entidad{
private:
    int experiencia = 20;
public:
    Golem();
    Golem(std::string n, int v, int d);
    ~Golem() override;

    void Atacar(Entidad& objetivo) override;
    int getExperiencia() const;
    Objeto* soltarLoot() const override;
};

#endif