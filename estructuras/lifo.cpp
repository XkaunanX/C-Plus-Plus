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

// Nodo de la pila
struct Nodo {
    Data Dato;
    Nodo* siguiente;
};

// Clase para gestionar la pila
class Pila {
private:
    Nodo* tope;       // Nodo superior de la pila
    int longitud;     // Número de nodos en la pila

public:
    // Constructor
    Pila() {
        tope = nullptr;
        longitud = 0;
    }

    // Métodos para gestionar la pila
    void push(Data dato) {
        Nodo* nuevo_nodo = new Nodo;
        nuevo_nodo->Dato = dato;
        nuevo_nodo->siguiente = tope;
        tope = nuevo_nodo;
        longitud++;
        std::cout << "Elemento insertado: ID = " << dato.i << ", Valor = " << dato.valor << "\n";
    }

    void pop() {
        if (pila_vacia()) {
            std::cout << "La pila está vacía. No se puede eliminar.\n";
            return;
        }
        Nodo* nodo_a_eliminar = tope;
        tope = tope->siguiente;
        std::cout << "Elemento eliminado: ID = " << nodo_a_eliminar->Dato.i << ", Valor = " << nodo_a_eliminar->Dato.valor << "\n";
        delete nodo_a_eliminar;
        longitud--;
    }

    Nodo* peek() {
        if (pila_vacia()) {
            std::cout << "La pila está vacía.\n";
            return nullptr;
        }
        return tope;
    }

    bool pila_vacia() {
        return tope == nullptr;
    }

    int obtener_longitud() {
        return longitud;
    }

    // Función para generar número aleatorio
    static int int_aleatorio() {
        return rand() % 100;
    }

    // Función para imprimir la pila
    void imprimir_pila() {
        Nodo* nodo_actual = tope;
        std::cout << "Contenido de la pila:\n";
        std::cout << "------------------------------------------\n";
        std::cout << "|  i  |   Valor   |     Direccion     |\n";
        std::cout << "------------------------------------------\n";
        while (nodo_actual != nullptr) {
            std::cout << "| " << nodo_actual->Dato.i << " | " << nodo_actual->Dato.valor
                      << " | " << nodo_actual << " |\n";
            nodo_actual = nodo_actual->siguiente;
        }
        std::cout << "------------------------------------------\n";
    }

    // Función para imprimir el nodo superior
    void imprimir_nodo(Nodo* nodo) {
        if (nodo == nullptr) {
            std::cout << "El nodo es NULL. No se puede imprimir.\n";
            return;
        }
        std::cout << "Detalles del nodo superior:\n";
        std::cout << "ID: " << nodo->Dato.i << "\n";
        std::cout << "Valor: " << nodo->Dato.valor << "\n";
        std::cout << "Direccion: " << nodo << "\n";
    }
};

// Función para la gestión de la consola
void menu_consola(Pila& pila) {
    int interfaz = 1;
    int seleccion;
    while (interfaz == STATUS_CONTINUAR) {
        system("CLS");
        std::cout << "MENU\n\n";
        std::cout << "1. Insertar elemento (push)\n";
        std::cout << "2. Eliminar elemento (pop)\n";
        std::cout << "3. Consultar elemento superior (peek)\n";
        std::cout << "4. Imprimir pila\n";
        std::cout << "5. Consultar longitud de la pila\n";
        std::cout << "0. Fin programa\n\n";
        std::cout << "> Seleccione una opcion: ";
        std::cin >> seleccion;
        system("CLS");

        switch (seleccion) {
            case 1:
                id++;
                Data dato;
                dato.i = id;
                dato.valor = Pila::int_aleatorio();
                pila.push(dato);
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                pila.imprimir_nodo(pila.peek());
                break;
            case 4:
                pila.imprimir_pila();
                break;
            case 5:
                std::cout << "Tamaño de la pila: " << pila.obtener_longitud() << "\n";
                break;
            case 0:
                std::cout << "Fin programa ...\n";
                exit(0);
                break;
            default:
                std::cout << "Error: ingreso un valor incorrecto\n";
                break;
        }
        system("PAUSE");
    }
}

// Función principal
int main() {
    ejecucion = 1;
    srand(time(NULL));
    Pila pila;
    menu_consola(pila);
    return 0;
}