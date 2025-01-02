#include <iostream>
#include <vector>
#include <functional>

void imprimir(int n, int m) {
    std::cout << n << " " << m << "\n";
}

int main() {
    auto funcion = std::bind(imprimir, std::placeholders::_1, 10);
    funcion(5);  // Imprime "5 10"
    return 0;
}
