#include <iostream>

// Sobrecarga de funciones
int operar(int a, int b) {
    return a + b;
}

double operar(double a, double b) {
    return a * b;
}

// Plantilla de función para manejar diferentes tipos de datos
template <typename T>
T operar(T a, T b) {
    return a - b;  // Resta por defecto
}

int main() {
    // Sobrecarga de funciones
    std::cout << "Suma (int): " << operar(5, 3) << std::endl;  // Llama a la version int
    std::cout << "Multiplicacion (double): " << operar(5.5, 2.0) << std::endl;  // Llama a la version double
    std::cout << "Resta (template): " << operar(10, 4) << std::endl;  // Llama a la version template

    return 0;
}
