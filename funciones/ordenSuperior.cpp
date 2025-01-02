#include <iostream>
#include <vector>
#include <algorithm>

// Función que acepta otra función como argumento
void aplicarFuncion(const std::vector<int>& vec, void (*func)(int)) {
    for (int n : vec) {
        func(n);  // Llama a la función pasada como argumento
    }
}

// Función de ejemplo para ser pasada como argumento
void mostrar(int x) {
    std::cout << x << " ";
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    
    std::cout << "Mostrando numeros: ";
    aplicarFuncion(numeros, mostrar);  // Se pasa la funcion 'mostrar' como argumento

    return 0;
}
