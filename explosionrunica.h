#ifndef EXPLOSIONRUNICA_H
#define EXPLOSIONRUNICA_H
#include "objeto.h"

class Jugador;
class Entidad;

class ExplosionRunica : public Objeto {
private:
    const int danio = 160;
    const int gastoMana = 100;
    const std::string letraAsociada = "E";
public:
    ExplosionRunica(std::string nombre);
    void usarObjeto(Jugador& jugador, Entidad& Enemigo) const override;
    std::string getLetra() const;
};

#endif