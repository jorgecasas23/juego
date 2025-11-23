#ifndef OBJETO_H
#define OBJETO_H
#include <string>

class Jugador;
class Entidad;

class Objeto{
protected:
    std::string nombre;
    std::string descripcionObjeto;
public:	
    Objeto(std::string nombre, std::string descripcionObjeto);
    virtual ~Objeto() = default;
    virtual void usarObjeto(Jugador& objetivo, Entidad& enemigo) const = 0;

    std::string getNombre() const;
    std::string getDescripcion() const;
};

#endif