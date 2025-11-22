#ifndef PROYECTILARCANO_H
#define PROYECTILARCANO_H
#include "objeto"

class ProyectilArcano : public objeto{
	private:
		int danio = 75;
		int gastoMana = 45;
		int proteccion = 25;
		std::string letraAsociada = "Q";
	public:
		ProyectilArcano();
		void usarObjeto(Jugador& jugador, Entidad& enemigo) const override;
		int getProteccion();
		std::string getLetra();
};



#endif
