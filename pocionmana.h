#ifndef POCIONMANA_H
#define POCIONMANA_H
#include "Objeto.h"

class Jugador;

class PocionMana : public Objeto{
private:
	int manaRestaurado = 150;
public:
	PocionMana(std::string nombre);
	void usarObjeto(Jugador& Objetivo) const;
};

#endif