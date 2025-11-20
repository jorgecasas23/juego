#ifndef POCIONVIDA_H
#define POCIONVIDA_H


class PocionVida : public Objeto{
	private:
		int vidaRestaurada = 300;
	public:
		PocionVida(std::string nombre);
		void usarObjeto() const override;
};

#endif