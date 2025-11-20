#ifndef ESCUDOENERGIA_H
#define ESCUDOENERGIA_H

class EscudoEnergia : public Object{
	private:
		int gastoMana = 30;
		int proteccion = 125;
		std::string letraAsociada = "W";
	public:
		EscudoEnergia();
		void usarObjeto() const override;
		std::string getLetra();
};


#endif