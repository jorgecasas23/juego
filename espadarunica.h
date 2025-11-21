#ifndef ESPADARUNICA_H
#define ESPADARUNICA_H
#include "Objeto.h"

class Jugador;

class EspadaRunica : public Objeto{
private:
	int danio = 90;
	int gastoMana = 0;
	int proteccion = 10;
	std::string letraAsignada = "Q";
public:
	EspadaRunica(std::string nombre);
	void usarObjeto(Jugador& Objetivo) const;
	int getProteccion() const;
	std::string getLetra() const;
};

#endif