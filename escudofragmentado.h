#ifndef ESCUDOFRAGMENTADO_H
#define ESCUDOFRAGMENTADO_H
#include "objeto.h"

class Jugador;
class Entidad;

class EscudoFragmentado : public Objeto{
private:
    int gastoMana = 55;
    int proteccion = 100;
    std::string letraAsociada = "W";
public:
    EscudoFragmentado(std::string nombre);
    void usarObjeto(Jugador& Objetivo, Entidad& Enemigo) const override;
    std::string getLetra() const;
};

#endif