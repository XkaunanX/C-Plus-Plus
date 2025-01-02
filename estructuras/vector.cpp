#include <iostream>
#include <vector>

#define MAX 10   // Tamano maximo del arreglo

struct Data {
    int i;
    int valor;
};

int main() {
    std::vector<Data> arreglo(MAX);  // Arreglo de tamaño MAX
    int id = 0;

    // Inicializar el arreglo
    for (int i = 0; i < MAX; i++) {
        arreglo[i].i = i;
        arreglo[i].valor = -1;  // Inicializamos con -1 (vacío)
    }

    int opcion, index, nuevo_valor;
    Data dato;

    while (true) {
        // Menu de opciones
        std::cout << "MENU\n";
        std::cout << "1. Insertar elemento\n";
        std::cout << "2. Eliminar elemento\n";
        std::cout << "3. Modificar elemento\n";
        std::cout << "4. Consultar elemento\n";
        std::cout << "5. Mostrar arreglo\n";
        std::cout << "6. Ordenar (Bubble Sort)\n";
        std::cout << "7. Ordenar (Selection Sort)\n";
        std::cout << "8. Ordenar (Insertion Sort)\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                dato.i = id;  // Usamos el id actual
                id++;  // Incrementamos el id
                std::cout << "Ingrese el valor para el nuevo elemento: ";
                std::cin >> dato.valor;
                std::cout << "Ingrese el indice (0-9): ";
                std::cin >> index;
                if (index >= 0 && index < MAX) {
                    if (arreglo[index].valor == -1) {  // Verifica si la posicion esta vacia
                        arreglo[index] = dato;
                        std::cout << "Elemento insertado correctamente en el indice " << index << "\n";
                    } else {
                        std::cout << "El indice " << index << " ya esta ocupado.\n";
                    }
                } else {
                    std::cout << "Indice fuera de rango.\n";
                }
                break;

            case 2:
                std::cout << "Ingrese el indice (0-9) para eliminar el elemento: ";
                std::cin >> index;
                if (index >= 0 && index < MAX) {
                    if (arreglo[index].valor != -1) {  // Verifica si la posicion no esta vacia
                        arreglo[index].valor = -1;
                        std::cout << "Elemento eliminado correctamente del indice " << index << "\n";
                    } else {
                        std::cout << "No hay ningun elemento en el indice " << index << " para eliminar.\n";
                    }
                } else {
                    std::cout << "Indice fuera de rango.\n";
                }
                break;

            case 3:
                std::cout << "Ingrese el indice (0-9) para modificar el elemento: ";
                std::cin >> index;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevo_valor;
                if (index >= 0 && index < MAX) {
                    if (arreglo[index].valor != -1) {  // Verifica si la posicion no esta vacia
                        arreglo[index].valor = nuevo_valor;
                        std::cout << "Elemento modificado correctamente en el indice " << index << "\n";
                    } else {
                        std::cout << "No hay ningun elemento en el indice " << index << " para modificar.\n";
                    }
                } else {
                    std::cout << "Indice fuera de rango.\n";
                }
                break;

            case 4:
                std::cout << "Ingrese el indice (0-9) para consultar el elemento: ";
                std::cin >> index;
                if (index >= 0 && index < MAX) {
                    if (arreglo[index].valor != -1) {  // Verifica si la posicion no esta vacia
                        std::cout << "Elemento en el indice " << index << ": ID=" << arreglo[index].i << ", Valor=" << arreglo[index].valor << "\n";
                    } else {
                        std::cout << "No hay ningun elemento en el indice " << index << ".\n";
                    }
                } else {
                    std::cout << "Indice fuera de rango.\n";
                }
                break;

            case 5:
                std::cout << "Contenido del arreglo:\n";
                std::cout << "-------------------------------------------------\n";
                std::cout << "| Indice |   ID   |   Valor   |\n";
                std::cout << "-------------------------------------------------\n";
                for (int i = 0; i < MAX; i++) {
                    if (arreglo[i].valor != -1) {
                        std::cout << "|   " << i << "   |   " << arreglo[i].i << "   |    " << arreglo[i].valor << "    |\n";
                    } else {
                        std::cout << "|   " << i << "   |   -    |    -     |\n";
                    }
                }
                std::cout << "-------------------------------------------------\n";
                break;

            case 6:
                // Bubble Sort
                for (int i = 0; i < MAX - 1; i++) {
                    for (int j = 0; j < MAX - 1 - i; j++) {
                        if (arreglo[j].valor > arreglo[j + 1].valor) {
                            std::swap(arreglo[j], arreglo[j + 1]);
                        }
                    }
                }
                std::cout << "Arreglo ordenado con Bubble Sort.\n";
                break;

            case 7:
                // Selection Sort
                for (int i = 0; i < MAX - 1; i++) {
                    int min_idx = i;
                    for (int j = i + 1; j < MAX; j++) {
                        if (arreglo[j].valor < arreglo[min_idx].valor) {
                            min_idx = j;
                        }
                    }
                    std::swap(arreglo[i], arreglo[min_idx]);
                }
                std::cout << "Arreglo ordenado con Selection Sort.\n";
                break;

            case 8:
                // Insertion Sort
                for (int i = 1; i < MAX; i++) {
                    int key = arreglo[i].valor;
                    int j = i - 1;
                    while (j >= 0 && arreglo[j].valor > key) {
                        arreglo[j + 1].valor = arreglo[j].valor;
                        j--;
                    }
                    arreglo[j + 1].valor = key;
                }
                std::cout << "Arreglo ordenado con Insertion Sort.\n";
                break;

            case 0:
                std::cout << "Fin del programa.\n";
                return 0;

            default:
                std::cout << "Opcion no valida.\n";
                break;
        }
    }
}
