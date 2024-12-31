#include <iostream>
#include <vector>
#include <cstdlib>

#define STATUS_CONTINUAR 1
#define FILAS 100
#define COLUMNAS 100

class Matriz {
private:
    std::vector<std::vector<int>> matriz;

public:
    Matriz() {
        matriz.resize(FILAS, std::vector<int>(COLUMNAS));
        inicializar_matriz();
    }

    // Inicializa la matriz con números aleatorios
    void inicializar_matriz() {
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                matriz[i][j] = rand() % 1000;  // Números aleatorios entre 0 y 999
            }
        }
    }

    // Muestra la matriz en consola
    void mostrar_matriz() const {
        std::cout << "Matriz actual:\n";
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                std::cout << matriz[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    // Aplana la matriz en un vector unidimensional
    void aplanar_matriz(std::vector<int>& arr) const {
        int index = 0;
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                arr[index++] = matriz[i][j];
            }
        }
    }

    // Reconstruye la matriz desde un vector unidimensional
    void reconstruir_matriz(const std::vector<int>& arr) {
        int index = 0;
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                matriz[i][j] = arr[index++];
            }
        }
    }

    // Métodos de ordenamiento
    void burbuja();
    void seleccion();
    void insercion();
    void quicksort(std::vector<int>& arr, int low, int high);
    int particionar(std::vector<int>& arr, int low, int high);
    void heapSort(std::vector<int>& arr, int n);
    void heapify(std::vector<int>& arr, int n, int i);
};

// Método de ordenamiento Burbuja
void Matriz::burbuja() {
    std::vector<int> arr(FILAS * COLUMNAS);
    aplanar_matriz(arr);

    for (int i = 0; i < FILAS * COLUMNAS - 1; i++) {
        for (int j = 0; j < FILAS * COLUMNAS - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    reconstruir_matriz(arr);
}

// Método de ordenamiento por Selección
void Matriz::seleccion() {
    std::vector<int> arr(FILAS * COLUMNAS);
    aplanar_matriz(arr);

    for (int i = 0; i < FILAS * COLUMNAS - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < FILAS * COLUMNAS; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }

    reconstruir_matriz(arr);
}

// Método de ordenamiento por Inserción
void Matriz::insercion() {
    std::vector<int> arr(FILAS * COLUMNAS);
    aplanar_matriz(arr);

    for (int i = 1; i < FILAS * COLUMNAS; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    reconstruir_matriz(arr);
}

// Función de partición para QuickSort
int Matriz::particionar(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Función QuickSort
void Matriz::quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Método de ordenamiento HeapSort
void Matriz::heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Matriz::heapSort(std::vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void ordenar_matriz(Matriz& matriz_obj, int metodo) {
    std::vector<int> arr(FILAS * COLUMNAS);
    matriz_obj.aplanar_matriz(arr);

    switch (metodo) {
    case 1:
        matriz_obj.burbuja();
        break;
    case 2:
        matriz_obj.seleccion();
        break;
    case 3:
        matriz_obj.insercion();
        break;
    case 4:
        matriz_obj.quicksort(arr, 0, FILAS * COLUMNAS - 1);
        matriz_obj.reconstruir_matriz(arr);
        break;
    case 5:
        matriz_obj.heapSort(arr, FILAS * COLUMNAS);
        matriz_obj.reconstruir_matriz(arr);
        break;
    default:
        std::cout << "Método no válido.\n";
    }
}

void menu_consola(Matriz& matriz_obj) {
    int seleccion;
    while (STATUS_CONTINUAR) {
        system("CLS");
        std::cout << "MENU\n\n";
        std::cout << "1. Mostrar matriz\n";
        std::cout << "2. Ordenar matriz con Burbuja\n";
        std::cout << "3. Ordenar matriz con Selección\n";
        std::cout << "4. Ordenar matriz con Inserción\n";
        std::cout << "5. Ordenar matriz con QuickSort\n";
        std::cout << "6. Ordenar matriz con HeapSort\n";
        std::cout << "0. Fin programa\n\n";
        std::cout << "> Seleccione una opcion: ";
        std::cin >> seleccion;
        system("CLS");

        switch (seleccion) {
        case 1:
            matriz_obj.mostrar_matriz();
            break;
        case 2:
            ordenar_matriz(matriz_obj, 1);  // Burbuja
            break;
        case 3:
            ordenar_matriz(matriz_obj, 2);  // Selección
            break;
        case 4:
            ordenar_matriz(matriz_obj, 3);  // Inserción
            break;
        case 5:
            ordenar_matriz(matriz_obj, 4);  // QuickSort
            break;
        case 6:
            ordenar_matriz(matriz_obj, 5);  // HeapSort
            break;
        case 0:
            std::cout << "Fin programa...\n";
            exit(0);
            break;
        default:
            std::cout << "Error: ingreso un valor incorrecto\n";
            break;
        }
        system("PAUSE");
    }
}

int main() {
    Matriz matriz_obj;
    menu_consola(matriz_obj);
    return 0;
}