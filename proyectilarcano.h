#ifndef PROYECTILARCANO_H
#define PROYECTILARCANO_H
#include "objeto.h"

class Jugador;
class Entidad;

class ProyectilArcano : public Objeto{
private:
    const int danio = 75;
    const int gastoMana = 45;
    const int proteccion = 25;
    const std::string letraAsociada = "Q";
public:
    ProyectilArcano(std::string nombre);
    void usarObjeto(Jugador& jugador, Entidad& enemigo) const override;
    int getProteccion() const;
    std::string getLetra() const;
};

#endif
