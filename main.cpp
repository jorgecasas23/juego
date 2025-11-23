#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <cctype>

#include "habitacion.h"
#include "Jugador.h"
#include "Entidad.h"
#include "objeto.h"
#include "pocionvida.h"
#include "pocionmana.h"
#include "proyectilarcano.h"
#include "escudofragmentado.h"
#include "explosionrunica.h"
#include "escudoenergia.h"
#include "corazontormenta.h"
#include "espadarunica.h"

std::vector<std::string> titulos = {
    "Ruinas del Nexo",
    "Bosque Sombrio",
    "Cueva de Cristal",
    "Volcan de Lava",
    "Fuerte Abandonado",
    "Pantano Venenoso",
    "El Nexo Final"
};

std::vector<std::string> descripciones = {
    "Despiertas en el Nexo corrupto. Controles: I/D para moverte. V para volver. Mucha suerte.",
    "La luz no entra, es ideal para ir en silencio.",
    "Un paisaje hermoso pero los enemigos no tanto.",
    "No vengas con saco, hace un poco de calor.",
    "Esto parece viejo, cuidado al pisar",
    "Mucho barro que te vuelve lento.",
    "El Nexo Final. El jefe esta aqui."
};

int desordenarHabitaciones() {
    return rand() % titulos.size();
}

void combate(Jugador* jugador, std::vector<Entidad*>& enemigos, bool& flag) {
    if (enemigos.empty()) {
        std::cout << "\nLa habitacion esta despejada." << std::endl;
        return;
    }

    std::cout << "\n--- COMIENZA EL COMBATE ---" << std::endl;
    while (jugador->EstaVivo() && !enemigos.empty()) {
        std::cout << "\n--- Tu Turno: " << jugador->getNombre() << " (Vida: " << jugador->getVida() << ", Mana: " << jugador->getMana() << ") ---" << std::endl;
        std::cout << "Enemigo actual: " << enemigos[0]->getNombre() << " (Vida: " << enemigos[0]->getVida() << ")" << std::endl;
        std::cout << "Opciones: A) Ataque Base | I) Inventario | Q/W/E para Habilidades/Objetos | M/V para Pociones" << std::endl;
        std::cout << "Ingresa accion: ";

        char accion;
        std::cin >> accion;
        accion = toupper(accion);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Intenta de nuevo." << std::endl;
            continue;
        }

        Entidad& enemigoActual = *enemigos[0];

        if (accion == 'A') {
            jugador->Atacar(enemigoActual);
        } else if (accion == 'I') {
            jugador->mostrarInventario();
            continue;
        } else if (accion == 'Q' || accion == 'W' || accion == 'E' || accion == 'V' || accion == 'M') {
            jugador->usarObjeto(accion, enemigoActual);
        } else {
            std::cout << "Accion no reconocida. Pierdes tu turno." << std::endl;
        }

        if (!enemigoActual.EstaVivo()) {
            std::cout << "\n*** " << enemigoActual.getNombre() << " ha sido derrotado! ***" << std::endl;
            
            // LÓGICA DE FIN DE JUEGO: Si derrotas al Clon
            if (enemigoActual.getNombre().find("Clon") != std::string::npos) {
                std::cout << "\n==============================================" << std::endl;
                std::cout << "!!! HAS DERROTADO AL CLON. FELICIDADES, HAS GANADO EL JUEGO !!!" << std::endl;
                std::cout << "==============================================" << std::endl;
                flag = false; // Establece la bandera de fin de juego
            }

            Objeto* loot = enemigos[0]->soltarLoot();
            if (loot != nullptr) {
                jugador->recogerObjeto(loot);
            }
            
            delete enemigos[0];
            enemigos.erase(enemigos.begin());
            
            // Si la bandera es falsa (victoria), terminamos la funcion combate
            if (!flag) return; 

            if (enemigos.empty()) {
                std::cout << "La habitacion esta despejada." << std::endl;
                break;
            }
        }
        
        if (!enemigos.empty() && jugador->EstaVivo()) {
            std::cout << "\n--- Turno del Enemigo: " << enemigos[0]->getNombre() << " ---" << std::endl;
            enemigos[0]->Atacar(*jugador);
        }
    }

    if (!jugador->EstaVivo()) {
        std::cout << "\n!!! HAS MUERTO EN COMBATE !!!" << std::endl;
        flag = false;
    }
}

void juego(Jugador& jugador) {
    bool flag = true;
    int contHabitaciones = 1;
    std::vector<Habitacion*> habitaciones;

    srand(time(0));

    int numAl = desordenarHabitaciones();
    Habitacion* habitacionInicio = new Habitacion(titulos[numAl], descripciones[numAl]);
    jugador.setHabitacion(habitacionInicio);
    habitaciones.push_back(habitacionInicio);

    jugador.agregarObjeto(new ProyectilArcano("Proyectil Arcano"));
    jugador.agregarObjeto(new EscudoEnergia("Escudo de Energia"));
    jugador.agregarObjeto(new ExplosionRunica("Explosion Runica"));
    jugador.agregarObjeto(new PocionVida("Pocion de Vida"));
    jugador.agregarObjeto(new PocionMana("Pocion de Mana"));

    if (!jugador.getHabitacion()->getEnemigos().empty()) {
        combate(&jugador, jugador.getHabitacion()->getEnemigos(), flag);
    }
    
    while (flag) {
        Habitacion* actual = jugador.getHabitacion();

        if (actual->getEnemigos().empty()) {
            std::cout << "\n-----------------------------------------------------" << std::endl;
            std::cout << "Te encuentras en: " << actual->getNombre() << std::endl;
            std::cout << actual->getDescripcion() << std::endl;
            std::cout << "Opciones de Movimiento:";
            std::cout << " [I]zquierda";
            std::cout << " [D]erecha";
            if (actual->getAnterior() != nullptr) {
                 std::cout << " [V]olver";
            }
            std::cout << " [O]bjetos [S]alir" << std::endl;
            std::cout << "Ingresa direccion: ";

            std::string direccion;
            std::cin >> direccion;
            std::transform(direccion.begin(), direccion.end(), direccion.begin(), ::toupper);

            Habitacion* siguienteHabitacion = nullptr;

            if (direccion == "O") {
                jugador.mostrarInventario();
                continue;
            } else if (direccion == "S") {
                std::cout << "Saliendo del juego." << std::endl;
                flag = false;
                break;
            }
            
            if (direccion == "V") {
                siguienteHabitacion = actual->getAnterior();
                if (siguienteHabitacion == nullptr) {
                    std::cout << "No puedes volver. Esta es la primera habitacion." << std::endl;
                    continue;
                }
            } else if (direccion == "I") {
                if (actual->getIzquierda() != nullptr) {
                    siguienteHabitacion = actual->getIzquierda();
                } else {
                    contHabitaciones++;
                    numAl = desordenarHabitaciones();
                    siguienteHabitacion = new Habitacion(titulos[numAl], descripciones[numAl], nullptr, actual, actual, contHabitaciones);
                    actual->setHIzquierda(siguienteHabitacion);
                    habitaciones.push_back(siguienteHabitacion);
                }
            } else if (direccion == "D") {
                if (actual->getDerecha() != nullptr) {
                    siguienteHabitacion = actual->getDerecha();
                } else {
                    contHabitaciones++;
                    numAl = desordenarHabitaciones();
                    siguienteHabitacion = new Habitacion(titulos[numAl], descripciones[numAl], actual, nullptr, actual, contHabitaciones);
                    actual->setHDerecha(siguienteHabitacion);
                    habitaciones.push_back(siguienteHabitacion);
                }
            }

            if (siguienteHabitacion != nullptr) {
                jugador.setHabitacion(siguienteHabitacion);
                if (!jugador.getHabitacion()->getEnemigos().empty()) {
                    std::cout << "\n¡CUIDADO! Un enemigo te espera." << std::endl;
                    combate(&jugador, jugador.getHabitacion()->getEnemigos(), flag);
                } else {
                    std::cout << "La habitacion esta despejada." << std::endl;
                }
            } else {
                std::cout << "Opcion de movimiento no valida." << std::endl;
            }
        }
        else {
            combate(&jugador, jugador.getHabitacion()->getEnemigos(), flag);
            if (!flag) break; 
        }
    }
    
    for (auto* habitacion : habitaciones) {
        delete habitacion;
    }
    habitaciones.clear();
}

int main() {
    std::string nombre;
    std::cout << "Bienvenido a Ecos del Nexo" << std::endl;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    Jugador jugador(nombre, 500, 75, 300);

    juego(jugador);
    
    std::cout << "\nFin del juego." << std::endl;

    return 0;

}
