#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>  // Incluyendo la biblioteca queue

#define STATUS_CONTINUAR 1

int ejecucion;
int id = 0;

// Estructura para almacenar los datos de cada nodo
struct Data {
    int i;
    int valor;
};

// Funcion para generar numero aleatorio
int int_aleatorio() {
    return rand() % 100;
}

// Funcion para la gestion de la consola
void menu_consola(std::queue<Data>& cola) {
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
        std::cout << "> Seleccione una opcion: ";
        std::cin >> seleccion;
        system("CLS");

        switch (seleccion) {
            case 1:
                id++;
                Data dato;
                dato.i = id;
                dato.valor = int_aleatorio();
                cola.push(dato);  // Usamos push para encolar
                break;
            case 2:
                if (!cola.empty()) {
                    cola.pop();  // Usamos pop para desencolar
                } else {
                    std::cout << "La cola esta vacia\n";
                }
                break;
            case 3:
                if (!cola.empty()) {
                    Data frente = cola.front();  // Consultamos el frente de la cola
                    std::cout << "Frente de la cola:\n";
                    std::cout << "ID: " << frente.i << "\n";
                    std::cout << "Valor: " << frente.valor << "\n";
                } else {
                    std::cout << "La cola esta vacia\n";
                }
                break;
            case 4:
                std::cout << "Longitud de la cola: " << cola.size() << "\n";
                break;
            case 0:
                std::cout << "Fin programa...\n";
                exit(0);
            default:
                std::cout << "Error: ingreso un valor incorrecto\n";
                break;
        }

        // Imprimir los elementos de la cola
        if (!cola.empty()) {
            std::cout << "Contenido de la cola:\n";
            std::cout << "--------------------------------------------------\n";
            std::cout << "|  i  |   Valor   |\n";
            std::cout << "--------------------------------------------------\n";

            std::queue<Data> copia = cola;  // Copia de la cola para no modificarla mientras se imprime
            while (!copia.empty()) {
                Data dato = copia.front();
                std::cout << "| " << dato.i << " | " << dato.valor << " |\n";
                copia.pop();
            }

            std::cout << "--------------------------------------------------\n";
        }

        system("PAUSE");
    }
}

// Funcion principal
int main() {
    ejecucion = 1;
    srand(time(NULL));

    std::queue<Data> cola;  // Usamos queue de la libreria estandar

    while (ejecucion == STATUS_CONTINUAR) {
        menu_consola(cola);
    }

    return 0;
}
