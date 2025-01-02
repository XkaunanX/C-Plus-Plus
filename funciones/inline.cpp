#include <iostream>

// Declaración de función inline
inline int sumar(int a, int b) {
    return a + b;
}

int main() {
    int resultado = sumar(10, 5);  // No hay llamada a la funcion real, solo se inserta el código
    std::cout << "La suma es: " << resultado << std::endl;

    return 0;
}
