//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_ENTIDAD_H
#define JDI_ENTIDAD_H
#include <string>

class Entidad {
protected:
    std::string nombre;
    int vida;
    int danioBase;
public:
    Entidad(std::string n, int v, int d);
    virtual ~Entidad();

    virtual void Atacar() = 0;
    virtual void RecibirDanio(int d);

    bool EstaVivo() const;
    std::string getNombre() const;
    [[nodiscard]] int getDanioBase() const;
};

#endif //JDI_ENTIDAD_H