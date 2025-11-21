#ifndef ESCUDOENERGIA_H
#define ESCUDOENERGIA_H
#include "Objeto.h"

class Jugador;

class EscudoEnergia : public Objeto{
    private:
       int gastoMana = 30;
       int proteccion = 125;
       std::string letraAsociada = "W";
    public:
       EscudoEnergia(std::string nombre);
       void usarObjeto(Jugador& Objetivo) const;
       std::string getLetra() const;
};

#endif