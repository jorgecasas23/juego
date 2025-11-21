#include "objeto.h"
#include "pocionvida.h"
#include "pocionmana.h"
#include "proyectilarcano.h"
#include "escudofragmentado.h"
#include "explosionrunica.h"
#include "escudoenergia.h"
#include "corazontormenta.h"
#include "espadarunica.h"
#include "habitacion.h"
#include "Jugador.h"
#include "OrcoSombrio.h"
#include "DragonCorrupto.h"
#include "Clon.h"
#include "Entidad.h"
#include "Golem"

#include <vector>
#include <string>
#include <iostream>


void combate(Jugador*& jugador, std::vector<Entidad*>& enemigos, bool& flag){
	int opcion;
	while (jugador->EstaVivo() && !enemigos.empty()){
		std::cout << "Turno de " << jugador->getNombre() << ": " << std::endl;
		std::cout << "Ingresa tu opcion: " << std::endl;
		std::cout << "1. Atacar" << std::endl;
		std::cout << "2. Abrir inventario" << std::endl;
		auto& inventario = jugador->getInventario();
		std::cin >> opcion;
		if (opcion < 0 || opcion > 2){
                std::cout << "Opcion no valida. Intenta de nuevo." << std::endl;
                continue;
			if (opcion == 1){
				std::cout << "A quien vas a atacar: " << std::endl;
				int i = 1, enemigoAtacar;
				std::string letraAtaque;
				for (auto* enemigo : enemigos){
					std::cout <<  i << ") " << enemigo->getNombre() << std::endl;
					i++;
				}
				std::cin >> enemigoAtacar;
				enemigoAtacar -= 1;
				if (enemigoAtacar < 0 || enemigoAtacar >= enemigos.size()){
	                std::cout << "Objetivo no válido. Intenta de nuevo." << std::endl;
	                continue;
	            }
				std::cout << "Que habilidad vas a usar: " << std::endl;
				std::cout << "Q: " << inventario[0]->getNombre() << std::endl;
				std::cout << "W: " << inventario[1]->getNombre() << std::endl;
				std::cout << "E: " << inventario[2]->getNombre() << std::endl;
				std::cin >> letraAtaque;
				if (letraAtaque == "Q"){
					Atacar(enemigos[enemigoAtacar]);
				}
				else if(letraAtaque == "W"){
					UsarHabilidadW(enemigos[enemigoAtacar]);
				}
				else if(letraAtaque == "E"){
					UsarHabilidadE(enemigos[enemigoAtacar]);
				}

				if (!enemigos[enemigoAtacar]->EstaVivo()){
					std::cout << "Has derrotado a " << enemigos[enemigoAtacar]->getNombre() << std::endl;
					int experienciaRecibida = jugador->experiencia + enemgios[enemigoAtacar]->getExperiencia();
					jugador->setExperiencia(experienciarecibida);
					delete enemigos[enemigoAtacar];
					enemigos.erase(enemigos.begin() + enemigoAtacar);
				}
				else{
					std::cout << "Turno de los enemigos: " << std::endl;
					for (auto* enemigo : enemigos){
						if (jugador->EstaVivo()){
							enemigo->atacar(*jugador);
							std::cout << enemigo->getNombre() << "ataca al "<< jugador->getNombre() <<". " << jugador->getNombre() << " tiene " << jugador->getSalud() << "puntos de vida" << std::endl;
							if (enemigo->getEspecie = "Dragon Corrupto"){
								int danioQuemadura = jugador->getVida() - enemigo->getDanioQuemadura();
								jugador->setVida(danioQuemadura);
							}
							if (!jugador->EstaVivo()) {
	    						std::cout << jugador->getNombre() <<" ha muerto. El combate termina." << std::endl;
	    						flag = true;
	    						break;
	    					}
						}
					}
				}
			}
			else if (opcion == 2){
				int seleccionObjeto;
				std::cout << "Inventario de" << jugador->getNombre() << ": "  << std::endl;
				auto& inventario = jugador->getInventario();
				for (int i = 0; i < inventario.size(); i++){
					std::cout << i + 1 << ") " << inventario[i]->getNombre() << std::endl; 
				}
				std::cout << "Selecciona el objeto que vas a usar: " << std::endl;
				std::cin >> seleccionObjeto;
				std::cout << inventario[seleccionObjeto]->getDescripcion() << std::endl;
				if (seleccionObjeto > 3){
					int usoObjeto;
					std::cout << "Deseas usar este objeto?" << std::endl;
					std::cout << "1) Si" << std::endl;
					std::cout << "2) No" << std::endl;
					std::cin >> usoObjeto;
					if (usoObjeto == 1){
						inventario[seleccionObjeto]->usarObjeto()
					}
				}
			}
		}
		else{
			std::cout << "Opcion invalida. Intenta de nuevo" << std::endl;
		}
	}
}

void gameplay(){
	std::vector<Habitacion*> habitaciones;
	habitaciones.push_back(new Habitacion("Inicio", "hola"))
	std::string direccion;
	jugador.setHabitacion(habitaciones[0]);
	std::cout << habitaciones[0].getDescripcion() << std::endl;
	std::cin >> direccion;
	int contHabitaciones = 0;
	bool flag = false;
	while(contHabitaciones < 7 && flag == false){
		if (direccion == "A" && jugador.getHabitacion().getIzquierda() == NULL){
			Habitacion* nuevaHabitacion = new Habitacion("Habitacion2", "hola2", NULL, jugador.getHabitacion(), contHabitaciones);
			jugador.getHabitacion().setHIzquierda(nuevaHabitacion);
			habitaciones.push_back(nuevaHabitacion);
			jugador.setHabitacion(nuevaHabitacion); 
			contHabitaciones++;
		}
		else if (direccion == "D" && jugador.getHabitacion().getDerecha() == NULL){
			Habitacion* nuevaHabitacion = new Habitacion("Habitacion2", "hola2", jugador.getHabitacion(), NULL, contHabitaciones);         
			jugador.getHabitacion().setHDerecha(nuevaHabitacion);
			habitaciones.push_back(nuevaHabitacion);
			jugador.setHabitacion(nuevaHabitacion);                                   
			contHabitaciones++;
		}
		std::cout << jugador.getHabitacion().getNombre() << std::endl;
		std::cout << jugador.getHabitacion().getDescripcion() << std::endl;

		for (auto* enemigo : jugador.getHabitacion().getEnemigos()){	
			std::cout << "Te has encontrado con " << enemigo->getNombre() << ". Un " << enemigo->getEspecie() << std::endl;
		}
		combate(&jugador, jugador.getHabitacion().getEnemigos(), flag);
	}
	for (auto* habitacion : habitaciones){
		delete habitacion;
	}
	habitaciones.clear();
}



int main(){
	gameplay()

	return 0;
}