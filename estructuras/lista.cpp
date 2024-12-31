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

// Estructura para el nodo de una lista enlazada
struct Nodo {
    Data Dato;
    Nodo* siguiente;
};

// Clase para gestionar la lista enlazada
class ListaEnlazada {
private:
    Nodo* cabeza;
    Nodo* final;
    int longitud;

public:
    // Constructor
    ListaEnlazada() {
        cabeza = nullptr;
        final = nullptr;
        longitud = 0;
    }

    // Métodos para gestionar la lista
    void insertar_nodo(Data dato) {
        Nodo* nuevo_nodo = new Nodo;
        nuevo_nodo->Dato = dato;
        nuevo_nodo->siguiente = nullptr;
        
        if (cabeza == nullptr) {
            cabeza = nuevo_nodo;
            final = nuevo_nodo;
        } else {
            final->siguiente = nuevo_nodo;
            final = nuevo_nodo;
        }
        longitud++;
    }

    void eliminar_nodo(int id) {
        Nodo* nodo_anterior = nullptr;
        Nodo* nodo_actual = cabeza;
        if (cabeza == nullptr) {
            std::cout << "La lista está vacía\n";
            return;
        }

        while (nodo_actual != nullptr) {
            if (nodo_actual->Dato.i == id) {
                if (nodo_anterior == nullptr) {
                    cabeza = nodo_actual->siguiente;
                } else {
                    nodo_anterior->siguiente = nodo_actual->siguiente;
                }
                if (nodo_actual == final) {
                    final = nodo_anterior;
                }
                delete nodo_actual;
                longitud--;
                return;
            }
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->siguiente;
        }
    }

    void modificar_nodo(int id) {
        Nodo* nodo_actual = cabeza;
        if (cabeza == nullptr) {
            std::cout << "Vacio\n";
            return;
        }
        while (nodo_actual != nullptr) {
            if (nodo_actual->Dato.i == id) {
                nodo_actual->Dato.valor = int_aleatorio();
                return;
            }
            nodo_actual = nodo_actual->siguiente;
        }
    }

    Nodo* consultar_nodo(int id) {
        Nodo* nodo_actual = cabeza;
        if (cabeza == nullptr) {
            return nullptr;
        }
        while (nodo_actual != nullptr) {
            if (nodo_actual->Dato.i == id) {
                return nodo_actual;
            }
            nodo_actual = nodo_actual->siguiente;
        }
        return nullptr;
    }

    int obtener_longitud() {
        return longitud;
    }

    void imprimir_lista() {
        Nodo* nodo_actual = cabeza;
        std::cout << "Contenido de la lista enlazada:\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << "|  i  |   Valor   |     Direccion     |   Siguiente   |\n";
        std::cout << "--------------------------------------------------\n";

        while (nodo_actual != nullptr) {
            std::cout << "| " << nodo_actual->Dato.i << " | " << nodo_actual->Dato.valor 
                      << " | " << nodo_actual << " | " << nodo_actual->siguiente << " |\n";
            nodo_actual = nodo_actual->siguiente;
        }
        std::cout << "--------------------------------------------------\n";
    }

    void imprimir_nodo(Nodo* nodo) {
        if (nodo == nullptr) {
            std::cout << "El nodo es NULL. No se puede imprimir.\n";
            return;
        }
        std::cout << "Detalles del nodo:\n";
        std::cout << "ID: " << nodo->Dato.i << "\n";
        std::cout << "Valor: " << nodo->Dato.valor << "\n";
        std::cout << "Direccion: " << nodo << "\n";
        std::cout << "Siguiente: " << nodo->siguiente << "\n";
    }

public:
    int int_aleatorio() {
        return rand() % 100;
    }
};

// Funcion para la gestion de la consola
void menu_consola(ListaEnlazada& lista) {
    int interfaz = 1;
    int seleccion;
    int size;
    int i;
    while (interfaz == STATUS_CONTINUAR) {
        // Limpiar consola
        system("CLS");
        std::cout << "MENU\n\n";
        std::cout << "1. Insertar nodo a la lista\n";
        std::cout << "2. Eliminar nodo de la lista\n";
        std::cout << "3. Modificar un nodo\n";
        std::cout << "4. Consultar nodo\n";
        std::cout << "5. Consultar longitud de lista\n";
        std::cout << "0. Fin programa\n\n";
        std::cout << "> Seleccione una opcion: ";
        std::cin >> seleccion;
        system("CLS");

        switch (seleccion) {
            case 1:
                id++;
                Data dato;
                dato.i = id;
                dato.valor = lista.int_aleatorio();
                lista.insertar_nodo(dato);
                break;
            case 2:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                lista.eliminar_nodo(i);
                break;
            case 3:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                lista.modificar_nodo(i);
                break;
            case 4:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                Nodo* nodo = lista.consultar_nodo(i);
                lista.imprimir_nodo(nodo);
                break;
            case 5:
                size = lista.obtener_longitud();
                std::cout << "Tamaño de la lista enlazada: " << size << "\n";
                break;
            case 0:
                std::cout << "Fin programa ...\n";
                exit(0);
                break;
            default:
                std::cout << "Error: ingreso un valor incorrecto\n";
                break;
        }
        lista.imprimir_lista();
        system("PAUSE");
    }
}

// Hilo principal
int main() {
    ejecucion = 1;
    srand(time(NULL));
    ListaEnlazada lista;
    while (ejecucion == STATUS_CONTINUAR) {
        menu_consola(lista);
    }
    return 0;
}