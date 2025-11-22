#ifndef CORAZONTORMENTA_H
#define CORAZONTORMENTA_H

#include "Objeto.h"
#include "Jugador.h"
#include "Entidad.h"
#include <string>

class CorazonTormenta : public Objeto {
private:
	const int danio = 210;
	const int gastoMana = 130;
	const std::string letraAsociada = "E";

public:
	CorazonTormenta(std::string nombre);
	void usarObjeto(Jugador &Objetivo, Entidad &Enemigo) const override;
	std::string getLetra() const;
};

#endif // CORAZONTORMENTA_H
