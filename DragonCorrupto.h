//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_DRAGONCORRUPTO_H
#define JDI_DRAGONCORRUPTO_H
#include <string>
#include <algorithm>

class DragonCorrupto {
private:
    std::string nombre;
    int vida = 500;
    int danioBase = 80;
    int DanioQuemadura;

public:
    DragonCorrupto(std::string n, int v, int d, int dq);
    ~DragonCorrupto();

    void RecibirDanio(int d);
    bool EstaVivo() const;
    std::string getNombre() const;
    int getDanioBase() const;
    int getVida() const;
    int getDanioQuemadura() const;

    void atacar();
};

#endif //JDI_DRAGONCORRUPTO_H