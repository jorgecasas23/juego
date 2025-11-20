#ifndef CORAZONTORMENTA_H
#define CORAZONTORMENTA_H

class CorazonTormenta : public Object{
	private:
		int danio = 210;
		int gastoMana = 130;
		int turnosPerdidos = 1;
		std::string letraAsociada = "E";
	public:
		CorazonTormenta();
		void usarObjeto() const override;
		std::string getLetra();

};

#endif