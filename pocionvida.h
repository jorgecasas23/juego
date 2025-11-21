#ifndef POCIONVIDA_H
#define POCIONVIDA_H
#include "Jugador.h"
#include "Objeto.h"


class PocionVida : public Objeto{
	private:
		int vidaRestaurada = 200;
	public:
		PocionVida(std::string nombre);
		void usarObjeto() const;
	    void usarObjeto(Jugador& objetivo);
};

#endif