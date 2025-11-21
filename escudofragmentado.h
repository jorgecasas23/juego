#ifndef ESCUDOFRAGMENTADO_H
#define ESCUDOFRAGMENTADO_H
#include "Objeto.h"

class Jugador;

class EscudoFragmentado : public Objeto{
private:
	int gastoMana = 55;
	int proteccion = 100;
	std::string letraAsociada = "W";
public:
	EscudoFragmentado(std::string nombre);
	void usarObjeto(Jugador& Objetivo) const override;
	std::string getLetra() const;
};

#endif