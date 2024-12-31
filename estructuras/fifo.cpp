#include <iostream>
#include <cstdlib>
#include <ctime>

#define STATUS_CONTINUAR 1

int ejecucion;
int id = 0;

// Estructura para almacenar los datos de cada nodo
struct Data {
    int i;
    int valor;
};

// Nodo de la cola
struct Nodo {
    Data Dato;
    Nodo* siguiente;
};

// Clase para gestionar la cola
class Cola {
private:
    Nodo* frente;  // Primer nodo (frente) de la cola
    Nodo* final;   // Último nodo (final) de la cola
    int longitud;  // Número de elementos en la cola

public:
    // Constructor
    Cola() {
        frente = nullptr;
        final = nullptr;
        longitud = 0;
    }

    // Métodos para gestionar la cola
    void encolar(Data dato) {
        Nodo* nuevo_nodo = new Nodo;
        nuevo_nodo->Dato = dato;
        nuevo_nodo->siguiente = nullptr;

        if (final == nullptr) {
            frente = nuevo_nodo;
            final = nuevo_nodo;
        } else {
            final->siguiente = nuevo_nodo;
            final = nuevo_nodo;
        }

        longitud++;
    }

    void desencolar() {
        if (frente == nullptr) {
            std::cout << "La cola está vacía\n";
            return;
        }

        Nodo* nodo_a_eliminar = frente;
        frente = frente->siguiente;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete nodo_a_eliminar;
        longitud--;
    }

    Nodo* consultar_frente() {
        return frente;
    }

    bool cola_vacia() {
        return frente == nullptr;
    }

    int obtener_longitud() {
        return longitud;
    }

    // Función para generar número aleatorio
    static int int_aleatorio() {
        return rand() % 100;
    }

    // Función para imprimir la cola
    void imprimir_cola() {
        Nodo* nodo_actual = frente;

        std::cout << "Contenido de la cola:\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << "|  i  |   Valor   |     Dirección     |   Siguiente   |\n";
        std::cout << "--------------------------------------------------\n";

        while (nodo_actual != nullptr) {
            std::cout << "| " << nodo_actual->Dato.i << " | " << nodo_actual->Dato.valor
                      << " | " << nodo_actual << " | " << nodo_actual->siguiente << " |\n";
            nodo_actual = nodo_actual->siguiente;
        }

        std::cout << "--------------------------------------------------\n";
    }

    // Función para imprimir un nodo
    void imprimir_nodo(Nodo* nodo) {
        if (nodo == nullptr) {
            std::cout << "El nodo es NULL. No se puede imprimir.\n";
            return;
        }

        std::cout << "Detalles del nodo:\n";
        std::cout << "ID: " << nodo->Dato.i << "\n";
        std::cout << "Valor: " << nodo->Dato.valor << "\n";
        std::cout << "Dirección: " << nodo << "\n";
        std::cout << "Siguiente: " << nodo->siguiente << "\n";
    }
};

// Función para la gestión de la consola
void menu_consola(Cola& cola) {
    int interfaz = 1;
    int seleccion;

    while (interfaz == STATUS_CONTINUAR) {
        system("CLS");
        std::cout << "MENU COLA SIMPLE\n\n";
        std::cout << "1. Encolar (Agregar a la cola)\n";
        std::cout << "2. Desencolar (Eliminar del frente de la cola)\n";
        std::cout << "3. Consultar frente de la cola\n";
        std::cout << "4. Consultar longitud de la cola\n";
        std::cout << "0. Fin programa\n\n";
        std::cout << "> Seleccione una opción: ";
        std::cin >> seleccion;
        system("CLS");

        switch (seleccion) {
            case 1:
                id++;
                Data dato;
                dato.i = id;
                dato.valor = Cola::int_aleatorio();
                cola.encolar(dato);
                break;
            case 2:
                cola.desencolar();
                break;
            case 3: {
                Nodo* nodo = cola.consultar_frente();
                cola.imprimir_nodo(nodo);
                break;
            }
            case 4:
                std::cout << "Longitud de la cola: " << cola.obtener_longitud() << "\n";
                break;
            case 0:
                std::cout << "Fin programa...\n";
                exit(0);
            default:
                std::cout << "Error: ingresó un valor incorrecto\n";
                break;
        }
        cola.imprimir_cola();
        system("PAUSE");
    }
}

// Función principal
int main() {
    ejecucion = 1;
    srand(time(NULL));

    Cola cola;

    while (ejecucion == STATUS_CONTINUAR) {
        menu_consola(cola);
    }

    return 0;
}