#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

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

// Funcion para imprimir la pila
void imprimir_pila(std::stack<Data>& pila) {
    std::stack<Data> pila_temp = pila;
    std::cout << "Contenido de la pila:\n";
    std::cout << "------------------------------------------\n";
    std::cout << "|  i  |   Valor   |\n";
    std::cout << "------------------------------------------\n";
    while (!pila_temp.empty()) {
        Data dato = pila_temp.top();
        std::cout << "| " << dato.i << " | " << dato.valor << " |\n";
        pila_temp.pop();
    }
    std::cout << "------------------------------------------\n";
}

// Funcion para la gestion de la consola
void menu_consola(std::stack<Data>& pila) {
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
                dato.valor = int_aleatorio();
                pila.push(dato);
                std::cout << "Elemento insertado: ID = " << dato.i << ", Valor = " << dato.valor << "\n";
                break;
            case 2:
                if (pila.empty()) {
                    std::cout << "La pila esta vacia. No se puede eliminar.\n";
                } else {
                    Data dato = pila.top();
                    pila.pop();
                    std::cout << "Elemento eliminado: ID = " << dato.i << ", Valor = " << dato.valor << "\n";
                }
                break;
            case 3:
                if (pila.empty()) {
                    std::cout << "La pila esta vacia.\n";
                } else {
                    Data dato = pila.top();
                    std::cout << "Elemento superior: ID = " << dato.i << ", Valor = " << dato.valor << "\n";
                }
                break;
            case 4:
                imprimir_pila(pila);
                break;
            case 5:
                std::cout << "Tamano de la pila: " << pila.size() << "\n";
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

// Funcion principal
int main() {
    ejecucion = 1;
    srand(time(NULL));
    std::stack<Data> pila;
    menu_consola(pila);
    return 0;
}
