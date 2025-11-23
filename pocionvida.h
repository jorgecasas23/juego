#ifndef POCIONVIDA_H
#define POCIONVIDA_H
#include "objeto.h"

class Jugador;
class Entidad;

class PocionVida : public Objeto{
public:
    PocionVida(std::string nombre);
    void usarObjeto(Jugador& objetivo, Entidad& enemigo) const override;
};

#endif