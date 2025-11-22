#include "proyectil.h"


ProyectilArcano::ProyectilArcano(){

}

void ProyectilArcano::usarObjeto(Jugador& jugador, Entidad& enemigo) const{
	const int costoMana = gastoMana;
    const int daniohacer = danio;

    int manaActual = Objetivo.getMana();

    if (manaActual >= costoMana) {
        int nuevoMana = manaActual - costoMana;
        Objetivo.setMana(nuevoMana);

        Enemigo.recibirDanio(daniohacer);

        std::cout << "" << Objetivo << " usa Proyectil arcano (" << letraAsociada << ") " << std::endl;
        std::cout << "Hace " << daniohacer << " puntos de daño al enemigo" << Enemigo.getNombre() << std::endl;
        std::cout << "mana restante: " << nuevoMana << std::endl;
    } else {
        std::cout << Objetivo << " no tiene suficiente mana (" << manaActual
                  << ") para usar " << getNombre() << " (Costo: " << costoMana << ")." << std::endl;
    }
}


int ProyectilArcano::getProteccion(){
	return proteccion;
}

std::string ProyectilArcano::getLetra(){
	return letraAsociada;
}
