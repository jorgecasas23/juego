//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_CLON_H
#define JDI_CLON_H
#include "Jugador.h"

class Clon : public Jugador {
public:
    Clon(const std::string& nombreClonado, int v, int d, int m);
    ~Clon() override;
    void atacar();
    void usarHabilidadE();
};

#endif //JDI_CLON_H