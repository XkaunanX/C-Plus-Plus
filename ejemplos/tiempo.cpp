#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();  // Comienza el cronómetro

    // Código cuyo tiempo de ejecución deseas medir
    for (int i = 0; i < 1000000; ++i) {}

    auto end = std::chrono::high_resolution_clock::now();  // Detiene el cronómetro
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Tiempo de ejecución: " << duration.count() << " milisegundos." << std::endl;
    return 0;
}
