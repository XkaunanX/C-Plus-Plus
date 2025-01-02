#include <iostream>
#include <cstdarg>

// Función variadic para sumar un número variable de argumentos
int sumar(int numArgs, ...) {
    va_list args;
    va_start(args, numArgs);

    int suma = 0;
    for (int i = 0; i < numArgs; ++i) {
        suma += va_arg(args, int);
    }

    va_end(args);
    return suma;
}

int main() {
    std::cout << "La suma es: " << sumar(4, 1, 2, 3, 4) << std::endl;
    return 0;
}
