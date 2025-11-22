#ifndef EXPLOSIONRUNICA_H
#define EXPLOSIONRUNICA_H
#include "Objeto.h"
#include "Entidad.h"

class Jugador;

class ExplosionRunica : public Objeto {
private:
	int danio = 160;
	int gastoMana = 100;
	std::string letraAsociada = "E";
public:
	ExplosionRunica(std::string nombre);
	void usarObjeto(Jugador& jugador, Entidad& Enemigo) const;
	std::string getLetra() const;
};

#endif
