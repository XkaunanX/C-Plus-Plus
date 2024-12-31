#include <iostream>
#include <cstdlib>

#define MAX 10   // Tamaño máximo del arreglo

class Vector {
public:
    struct Data {
        int i;
        int valor;
    };

private:
    Data arreglo[MAX];
    int id;

public:
    // Constructor
    Vector() {
        id = 0;
        inicializar_arreglo();
    }

    // Inicializa el arreglo
    void inicializar_arreglo() {
        for (int i = 0; i < MAX; i++) {
            arreglo[i].i = i;
            arreglo[i].valor = -1;  // Inicializamos con -1 (vacío)
        }
    }

    // Función para insertar un elemento en el arreglo
    void insertar_elemento(Data dato, int index) {
        if (index >= 0 && index < MAX) {
            if (arreglo[index].valor == -1) {  // Verifica si la posición está vacía
                arreglo[index] = dato;
                std::cout << "Elemento insertado correctamente en el índice " << index << "\n";
            } else {
                std::cout << "El índice " << index << " ya está ocupado.\n";
            }
        } else {
            std::cout << "Índice fuera de rango.\n";
        }
    }

    // Función para eliminar un elemento en el arreglo
    void eliminar_elemento(int index) {
        if (index >= 0 && index < MAX) {
            if (arreglo[index].valor != -1) {  // Verifica si la posición no está vacía
                arreglo[index].valor = -1;
                std::cout << "Elemento eliminado correctamente del índice " << index << "\n";
            } else {
                std::cout << "No hay ningún elemento en el índice " << index << " para eliminar.\n";
            }
        } else {
            std::cout << "Índice fuera de rango.\n";
        }
    }

    // Función para modificar un elemento en el arreglo
    void modificar_elemento(int index, int nuevo_valor) {
        if (index >= 0 && index < MAX) {
            if (arreglo[index].valor != -1) {  // Verifica si la posición no está vacía
                arreglo[index].valor = nuevo_valor;
                std::cout << "Elemento modificado correctamente en el índice " << index << "\n";
            } else {
                std::cout << "No hay ningún elemento en el índice " << index << " para modificar.\n";
            }
        } else {
            std::cout << "Índice fuera de rango.\n";
        }
    }

    // Función para consultar un elemento en el arreglo
    void consultar_elemento(int index) {
        if (index >= 0 && index < MAX) {
            if (arreglo[index].valor != -1) {  // Verifica si la posición no está vacía
                std::cout << "Elemento en el índice " << index << ": ID=" << arreglo[index].i << ", Valor=" << arreglo[index].valor << "\n";
            } else {
                std::cout << "No hay ningún elemento en el índice " << index << ".\n";
            }
        } else {
            std::cout << "Índice fuera de rango.\n";
        }
    }

    // Función para imprimir el arreglo
    void imprimir_arreglo() {
        std::cout << "Contenido del arreglo:\n";
        std::cout << "-------------------------------------------------\n";
        std::cout << "| Índice |   ID   |   Valor   |\n";
        std::cout << "-------------------------------------------------\n";

        for (int i = 0; i < MAX; i++) {
            if (arreglo[i].valor != -1) {
                std::cout << "|   " << i << "   |   " << arreglo[i].i << "   |    " << arreglo[i].valor << "    |\n";
            } else {
                std::cout << "|   " << i << "   |   -    |    -     |\n";
            }
        }
        std::cout << "-------------------------------------------------\n";
    }

    // Métodos de ordenamiento
    void bubble_sort() {
        int temp;
        for (int i = 0; i < MAX - 1; i++) {
            for (int j = 0; j < MAX - 1 - i; j++) {
                if (arreglo[j].valor > arreglo[j + 1].valor) {
                    temp = arreglo[j].valor;
                    arreglo[j].valor = arreglo[j + 1].valor;
                    arreglo[j + 1].valor = temp;
                }
            }
        }
    }

    void selection_sort() {
        int min_idx, temp;
        for (int i = 0; i < MAX - 1; i++) {
            min_idx = i;
            for (int j = i + 1; j < MAX; j++) {
                if (arreglo[j].valor < arreglo[min_idx].valor) {
                    min_idx = j;
                }
            }
            temp = arreglo[i].valor;
            arreglo[i].valor = arreglo[min_idx].valor;
            arreglo[min_idx].valor = temp;
        }
    }

    void insertion_sort() {
        int key, j;
        for (int i = 1; i < MAX; i++) {
            key = arreglo[i].valor;
            j = i - 1;
            while (j >= 0 && arreglo[j].valor > key) {
                arreglo[j + 1].valor = arreglo[j].valor;
                j--;
            }
            arreglo[j + 1].valor = key;
        }
    }

    // Método para acceder a la propiedad `id`
    int get_id() {
        return id;
    }

    // Método para incrementar el `id`
    void incrementar_id() {
        id++;
    }

    // Método para obtener el arreglo
    Data* obtener_arreglo() {
        return arreglo;
    }
};

int main() {
    Vector v;  // Crear el objeto de la clase Vector

    int opcion, index, nuevo_valor;
    Vector::Data dato;
    while (true) {
        // Menú de opciones
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
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                dato.i = v.get_id();  // Usamos el id actual
                v.incrementar_id();  // Incrementamos el id
                std::cout << "Ingrese el valor para el nuevo elemento: ";
                std::cin >> dato.valor;
                std::cout << "Ingrese el índice (0-9): ";
                std::cin >> index;
                v.insertar_elemento(dato, index);
                break;
            case 2:
                std::cout << "Ingrese el índice (0-9) para eliminar el elemento: ";
                std::cin >> index;
                v.eliminar_elemento(index);
                break;
            case 3:
                std::cout << "Ingrese el índice (0-9) para modificar el elemento: ";
                std::cin >> index;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevo_valor;
                v.modificar_elemento(index, nuevo_valor);
                break;
            case 4:
                std::cout << "Ingrese el índice (0-9) para consultar el elemento: ";
                std::cin >> index;
                v.consultar_elemento(index);
                break;
            case 5:
                v.imprimir_arreglo();
                break;
            case 6:
                v.bubble_sort();
                std::cout << "Arreglo ordenado con Bubble Sort.\n";
                break;
            case 7:
                v.selection_sort();
                std::cout << "Arreglo ordenado con Selection Sort.\n";
                break;
            case 8:
                v.insertion_sort();
                std::cout << "Arreglo ordenado con Insertion Sort.\n";
                break;
            case 0:
                std::cout << "Fin del programa.\n";
                return 0;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    }
}