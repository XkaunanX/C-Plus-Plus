#include <iostream>
#include <random>

int main() {
    // Crear una semilla aleatoria basada en el tiempo
    std::random_device rd;
    
    // Usar la semilla con el generador de números aleatorios
    std::mt19937 gen(rd());  // mt19937 es un generador Mersenne Twister
    
    // Definir el rango de los números aleatorios
    std::uniform_int_distribution<> dis(1, 100);  // Entre 1 y 100

    // Generar 5 números aleatorios dentro del rango
    for (int i = 0; i < 5; ++i) {
        std::cout << "Número aleatorio: " << dis(gen) << std::endl;
    }

    return 0;
}
