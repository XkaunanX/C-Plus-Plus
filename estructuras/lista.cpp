#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

#define STATUS_CONTINUAR 1

int ejecucion;
int id = 0;

// Estructura para almacenar los datos de cada nodo
struct Data {
    int i;
    int valor;
};

// Funcion para generar numero aleatorio
static int int_aleatorio() {
    return rand() % 100;
}

// Funcion para imprimir la lista
void imprimir_lista(std::list<Data>& lista) {
    std::cout << "Contenido de la lista enlazada:\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "|  i  |   Valor   |\n";
    std::cout << "--------------------------------------------------\n";

    for (auto& nodo : lista) {
        std::cout << "| " << nodo.i << " | " << nodo.valor << " |\n";
    }
    std::cout << "--------------------------------------------------\n";
}

// Funcion para la gestion de la consola
void menu_consola(std::list<Data>& lista) {
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
                dato.valor = int_aleatorio();
                lista.push_back(dato);
                break;
            case 2:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                lista.remove_if([i](const Data& dato) { return dato.i == i; });
                break;
            case 3:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                for (auto& nodo : lista) {
                    if (nodo.i == i) {
                        nodo.valor = int_aleatorio();
                        break;
                    }
                }
                break;
            case 4:
                std::cout << "> Ingrese un id: ";
                std::cin >> i;
                for (const auto& nodo : lista) {
                    if (nodo.i == i) {
                        std::cout << "ID: " << nodo.i << "\n";
                        std::cout << "Valor: " << nodo.valor << "\n";
                        break;
                    }
                }
                break;
            case 5:
                size = lista.size();
                std::cout << "Tamano de la lista enlazada: " << size << "\n";
                break;
            case 0:
                std::cout << "Fin programa ...\n";
                exit(0);
                break;
            default:
                std::cout << "Error: ingreso un valor incorrecto\n";
                break;
        }
        imprimir_lista(lista);
        system("PAUSE");
    }
}

// Hilo principal
int main() {
    ejecucion = 1;
    srand(time(NULL));
    std::list<Data> lista;
    while (ejecucion == STATUS_CONTINUAR) {
        menu_consola(lista);
    }
    return 0;
}
