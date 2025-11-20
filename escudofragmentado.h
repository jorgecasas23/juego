#ifndef ESCUDOFRAGMENTADO_H
#define ESCUDOFRAGMENTADO_H

class EscudoFragmentado : public Object{
	private:
		int gastoMana = 55;
		int proteccion = 100;
		std::string letraAsociada = "W";
	public:
		EscudoFragmentado();
		void usarObjeto() const override;
		std::string getLetra();
};


#endif