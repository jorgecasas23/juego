//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_GOLEM_H
#define JDI_GOLEM_H
#include "Entidad.h"

class Golem : public Entidad {
private:
    double ProbabilidadAturdir;
    int TurnoAturdido;
public:
    Golem(std::string n, int v, int d, double pa, int ta);
    ~Golem() override;

    void Atacar() override;
};


#endif //JDI_GOLEM_H