#ifndef PROYECTILARCANO_H
#define PROYECTILARCANO_H

class ProyectilArcano : public Object{
	private:
		int danio = 75;
		int gastoMana = 45;
		int proteccion = 25;
		std::string letraAsociada = "Q";
	public:
		ProyectilArcano();
		void usarObjeto() const override;
		int getProteccion();
		std::string getLetra();
};


#endif