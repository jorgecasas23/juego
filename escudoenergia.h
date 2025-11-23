#ifndef ESCUDOENERGIA_H
#define ESCUDOENERGIA_H
#include "objeto.h"

class Jugador;
class Entidad;

class EscudoEnergia : public Objeto{
private:
    int gastoMana = 30;
    int proteccion = 125;
    std::string letraAsociada = "W";
public:
    EscudoEnergia(std::string nombre);
    void usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const override;
    std::string getLetra() const;
};

#endif