#ifndef POCIONMANA_H
#define POCIONMANA_H

class PocionMana : public Objeto{
	private:
		int manaRestaurado = 150;
	public:
		PocionMana(std::string nombre);
		void usarObjeto() const override;
};

#endif