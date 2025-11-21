//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_GOLEM_H
#define JDI_GOLEM_H
#include <string>
#include "Entidad.h"
class Golem : public Entidad{
    private:
        std::string nombre;
        int vida = 400;
        int danioBase = 65;
        int experiencia = 20;
    public:
        Golem();
        Golem(std::string n, int v, int d);
        ~Golem();

        void Atacar();
        void RecibirDanio(int d);
        std::string getNombre() const;
        int getDanioBase() const;
        int getExperiencia() const;
};

#endif //JDI_GOLEM_H