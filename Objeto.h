//
// Created by lonix on 20/11/2025.
//

#ifndef JDI_OBJETO_H
#define JDI_OBJETO_H
#include <string>

class Objeto {
private:
    std::string nombre;
    int valor;
public:
    Objeto(std::string n, int v);
    std::string getNombre() const;
};

#endif //JDI_OBJETO_H