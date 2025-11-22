#ifndef ESPADARUNICA_H
#define ESPADARUNICA_H

#include "objeto.h"

class EspadaRunica : public Objeto{
	private:
		int danio = 90;
		int gastoMana = 0;
		int proteccion = 10;
		std::string letraAsignada = "Q";
	public:
		EspadaRunica();
		void usarObjeto(Jugador& jugador, Entidad& enemigo) const override;
		int getProteccion();
		std::string getLetra();


};


#endif