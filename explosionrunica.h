#ifndef EXPLOSIONRUNICA_H
#define EXPLOSIONRUNICA_H

class ExplosionRunica : public Object{
	private:
		int danio = 160;
		int gastoMana = 100;
		std::string letraAsociada = "E";
	public:
		ExplosionRunica();
		void usarObjeto() const override;
		std::string getLetra();
};


#endif