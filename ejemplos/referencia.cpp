#include <iostream>

void incrementar(int& x) {
    x++;  // Modifica directamente el valor de x
}

int main() {
    int a = 5;
    incrementar(a);  // Pasa a través de referencia
    std::cout << "Valor de a después de incrementar: " << a << std::endl;
    return 0;
}
