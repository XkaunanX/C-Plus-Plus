#include <iostream>
#include <functional>

void imprimirMensaje(std::string mensaje, int repeticiones) {
    for (int i = 0; i < repeticiones; ++i) {
        std::cout << mensaje << std::endl;
    }
}

int main() {
    auto imprimirHola = std::bind(imprimirMensaje, "Hola", 3);
    imprimirHola();  // Imprime "Hola" 3 veces

    return 0;
}
