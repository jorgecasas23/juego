#ifndef CORAZONTORMENTA_H
#define CORAZONTORMENTA_H

#include "objeto.h"
#include <string>

class Jugador;
class Entidad;

class CorazonTormenta : public Objeto {
private:
    const int danio = 210;
    const int gastoMana = 130;
    const std::string letraAsociada = "E";

public:
    CorazonTormenta(std::string nombre);
    void usarObjeto(Jugador &Objetivo, Entidad &Enemigo) const override;
    std::string getLetra() const;
};

#endif