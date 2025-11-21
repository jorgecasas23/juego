//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_ORCOSOMBRIO_H
#define JDI_ORCOSOMBRIO_H
#include "Entidad.h"

class OrcoSombrio : public Entidad {
private:
    int Furia;
public:
    OrcoSombrio(std::string n, int v, int d, int f);
    ~OrcoSombrio() override;
    void atacar();
};

#endif //JDI_ORCOSOMBRIO_H