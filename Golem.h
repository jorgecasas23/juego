//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_GOLEM_H
#define JDI_GOLEM_H
#include <string>

class Golem {
private:
    std::string nombre;
    int vida = 400;
    int danioBase = 65;
public:
    Golem(std::string n, int v, int d);
    ~Golem();

    void Atacar();
    void RecibirDanio(int d);
    bool EstaVivo() const;
    std::string getNombre() const;
    int getDanioBase() const;
};

#endif //JDI_GOLEM_H