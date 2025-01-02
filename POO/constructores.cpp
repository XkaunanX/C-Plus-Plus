#include <iostream>
#include <memory>

class Recurso {
private:
    std::unique_ptr<int[]> datos;
    int tamano;

public:
    // Constructor
    Recurso(int tam) : tamano(tam), datos(std::make_unique<int[]>(tam)) {
        for (int i = 0; i < tamano; ++i) {
            datos[i] = i;
        }
        std::cout << "Recurso de tamano " << tamano << " creado.\n";
    }

    // Constructor de copia (se impide la copia)
    Recurso(const Recurso& other) = delete;

    // Constructor de movimiento
    Recurso(Recurso&& other) noexcept : tamano(other.tamano), datos(std::move(other.datos)) {
        other.tamano = 0;
        std::cout << "Recurso movido.\n";
    }

    // Método para mostrar datos
    void mostrar() const {
        for (int i = 0; i < tamano; ++i) {
            std::cout << datos[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Recurso r1(5);
    r1.mostrar();

    // Movemos el recurso a un nuevo objeto
    Recurso r2 = std::move(r1);
    r2.mostrar();

    return 0;
}
