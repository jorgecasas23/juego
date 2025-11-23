#ifndef ESPADARUNICA_H
#define ESPADARUNICA_H

#include "objeto.h"
#include <string>

class Jugador;
class Entidad;

class EspadaRunica : public Objeto{
private:
    const int danio = 90;
    const int proteccion = 10;
    const std::string letraAsignada = "Q";
public:
    EspadaRunica(std::string nombre);
    void usarObjeto(Jugador& jugador, Entidad& enemigo) const override;
    int getProteccion() const;
    std::string getLetra() const;
};

#endif