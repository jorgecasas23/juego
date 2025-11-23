//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_CLON_H
#define JDI_CLON_H
#include "Jugador.h"

class Clon : public Jugador {
private:
    int danioExtra = 20;
    int costoHabilidadE = 40;
public:
    Clon(const std::string& nombreClonado, int v, int d, int m);
    ~Clon() override;
    void Atacar(Entidad& objetivo) override;
    void usarHabilidadE(Entidad& objetivo);
};

#endif