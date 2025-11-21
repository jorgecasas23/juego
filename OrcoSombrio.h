//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_ORCOSOMBRIO_H
#define JDI_ORCOSOMBRIO_H
#include <string>
#include "Entidad.h"

class OrcoSombrio : public Entidad{
    private:
        std::string nombre = orcosombrio;
        int vida =  250;
        int danioBase 50;
    public:
        OrcoSombrio(std::string n, int v, int d, int f);
        ~OrcoSombrio();

        void RecibirDanio(int d);
        bool EstaVivo() const;
        std::string getNombre() const;
        int getDanioBase() const;
        int getExperiencia() const;
        void atacar();
};

#endif //JDI_ORCOSOMBRIO_H