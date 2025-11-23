#ifndef POCIONMANA_H
#define POCIONMANA_H
#include "objeto.h"

class Jugador;
class Entidad;

class PocionMana : public Objeto{
public:
    PocionMana(std::string nombre);
    void usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const override;
};

#endif