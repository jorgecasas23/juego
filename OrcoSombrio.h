//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_ORCOSOMBRIO_H
#define JDI_ORCOSOMBRIO_H
#include <string>
#include "Entidad.h"

class OrcoSombrio : public Entidad{
private:
    int experiencia = 10;
public:
    OrcoSombrio();
    OrcoSombrio(std::string n, int v, int d);
    ~OrcoSombrio() override;

    void Atacar(Entidad& objetivo) override;
    int getExperiencia() const;
};

#endif