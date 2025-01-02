#include <iostream>
#include <functional>

// Puntero a funcion para manipular el comportamiento de operaciones
using operacion_t = std::function<int(int, int)>;

// Funcion que utiliza un puntero a funcion
void aplicarOperacion(int a, int b, operacion_t operacion) {
    std::cout << "Resultado de la operacion: " << operacion(a, b) << std::endl;
}

int sumar(int a, int b) {
    return a + b;
}

int main() {
    // Uso de puntero a funcion con std::function
    operacion_t suma = std::bind(sumar, std::placeholders::_1, std::placeholders::_2);
    aplicarOperacion(10, 5, suma);

    return 0;
}
