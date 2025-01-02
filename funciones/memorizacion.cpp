#include <iostream>
#include <unordered_map>

// Memorizacion utilizando un mapa
std::unordered_map<int, long long> memo;

// Función recursiva para calcular el factorial con memorización
long long factorial(int n) {
    if (n <= 1) return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];  // Retorna el valor memorizado
    }
    memo[n] = n * factorial(n - 1);  // Almacena el resultado
    return memo[n];
}

int main() {
    int numero = 20;
    std::cout << "Factorial de " << numero << " es: " << factorial(numero) << std::endl;

    return 0;
}
