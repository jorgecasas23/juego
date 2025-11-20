#ifndef OBJETO_H
#define OBJETO_H


class Objeto{
	protected:
		std::string nombre;
		std::string descripcionObjeto;
	public:	
		Objeto(std::string nombre, std::string descripcionObjeto);
		virtual ~Objeto() = default;
		virtual void usarObjeto() = 0;
		std::string getNombre() const;
		std::string getDescripcion() const;
};

#endif