//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_DRAGONCORRUPTO_H
#define JDI_DRAGONCORRUPTO_H
#include "Entidad.h"

class DragonCorrupto : public Entidad {
private:
    int DanioQuemadura;
    int TurnosQuemadura;
public:
    DragonCorrupto(std::string n, int v, int d, int dq, int tq);
    ~DragonCorrupto() override;

    void atacar();
};

#endif //JDI_DRAGONCORRUPTO_H