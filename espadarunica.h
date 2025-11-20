#ifndef ESPADARUNICA_H
#define ESPADARUNICA_H

class EspadaRunica : public Object{
	private:
		int danio = 90;
		int gastoMana = 0;
		int proteccion = 10;
		std::string letraAsignada = "Q";
	public:
		EspadaRunica();
		void usarObjeto() const override;
		int getProteccion();
		std::string getLetra();


};


#endif