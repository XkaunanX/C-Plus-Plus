#include <iostream>
#include <cstdlib>
#include <ctime>

#define X 4   // Tamaño en la dimensión X
#define Y 3   // Tamaño en la dimensión Y
#define Z 5   // Tamaño en la dimensión Z

class Tensor3D {
private:
    int ***tensor;
public:
    // Constructor para inicializar el tensor
    Tensor3D() {
        tensor = new int**[X];
        for (int i = 0; i < X; i++) {
            tensor[i] = new int*[Y];
            for (int j = 0; j < Y; j++) {
                tensor[i][j] = new int[Z];
            }
        }
    }

    // Destructor para liberar la memoria
    ~Tensor3D() {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                delete[] tensor[i][j];
            }
            delete[] tensor[i];
        }
        delete[] tensor;
    }

    // Inicializar el tensor con valores aleatorios
    void inicializar_con_valores_aleatorios() {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                for (int k = 0; k < Z; k++) {
                    tensor[i][j][k] = rand() % 100;  // Asignar valores aleatorios entre 0 y 99
                }
            }
        }
    }

    // Modificar un elemento del tensor
    void modificar_elemento(int x, int y, int z, int valor) {
        if (x >= 0 && x < X && y >= 0 && y < Y && z >= 0 && z < Z) {
            tensor[x][y][z] = valor;
        } else {
            std::cout << "Índices fuera de rango.\n";
        }
    }

    // Consultar un elemento del tensor
    int consultar_elemento(int x, int y, int z) {
        if (x >= 0 && x < X && y >= 0 && y < Y && z >= 0 && z < Z) {
            return tensor[x][y][z];
        } else {
            std::cout << "Índices fuera de rango.\n";
            return -1;  // Valor de error
        }
    }

    // Imprimir el tensor completo
    void imprimir_tensor() {
        for (int i = 0; i < X; i++) {
            std::cout << "Capa " << i << ":\n";
            for (int j = 0; j < Y; j++) {
                for (int k = 0; k < Z; k++) {
                    std::cout << tensor[i][j][k] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
    }
};

void menu(Tensor3D &tensor) {
    int opcion, x, y, z, valor;
    while (true) {
        system("CLS");
        std::cout << "MENU DE OPERACIONES SOBRE EL TENSOR 3D\n";
        std::cout << "1. Inicializar tensor con valores aleatorios\n";
        std::cout << "2. Modificar un elemento del tensor\n";
        std::cout << "3. Consultar un elemento del tensor\n";
        std::cout << "4. Imprimir tensor completo\n";
        std::cout << "5. Salir\n";
        std::cout << "\n> Elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                tensor.inicializar_con_valores_aleatorios();
                std::cout << "Tensor inicializado con valores aleatorios.\n";
                break;
            case 2:
                std::cout << "> Ingrese las coordenadas (x, y, z) del elemento a modificar: ";
                std::cin >> x >> y >> z;
                std::cout << "> Ingrese el nuevo valor: ";
                std::cin >> valor;
                tensor.modificar_elemento(x, y, z, valor);
                std::cout << "Elemento [" << x << "][" << y << "][" << z << "] modificado a " << valor << ".\n";
                break;
            case 3:
                std::cout << "> Ingrese las coordenadas (x, y, z) del elemento a consultar: ";
                std::cin >> x >> y >> z;
                valor = tensor.consultar_elemento(x, y, z);
                std::cout << "Valor en [" << x << "][" << y << "][" << z << "]: " << valor << "\n";
                break;
            case 4:
                tensor.imprimir_tensor();
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
        std::cout << "\n";
        system("PAUSE");
    }
}

int main() {
    srand(time(NULL));
    Tensor3D tensor;  // Crear una instancia del tensor 3D
    menu(tensor);  // Mostrar el menú y permitir la interacción
    return 0;
}