#include <iostream>

// Función que modifica un valor mediante una referencia
void incrementar(int& x) {
    x++;
}

// Función que devuelve una referencia (modificación de la variable original)
int& obtenerElemento(std::vector<int>& vec, int index) {
    return vec[index];
}

int main() {
    int a = 5;
    incrementar(a);  // Modifica a directamente
    std::cout << "Valor incrementado: " << a << std::endl;

    std::vector<int> vec = {1, 2, 3, 4};
    obtenerElemento(vec, 2) = 10;  // Modifica directamente el elemento en el índice 2
    std::cout << "Elemento modificado: " << vec[2] << std::endl;

    return 0;
}
