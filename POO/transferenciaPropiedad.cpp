#include <iostream>
#include <utility>

class Contenedor {
public:
    template <typename T>
    void almacenar(T&& valor) {
        this->valor = std::forward<T>(valor);
    }

    void mostrar() const {
        std::cout << "Valor almacenado: " << valor << std::endl;
    }

private:
    int valor;
};

int main() {
    Contenedor c;
    int v = 42;

    // Transferencia perfecta
    c.almacenar(v);  // Pasa por referencia
    c.mostrar();     // Muestra "Valor almacenado: 42"

    c.almacenar(100);  // Pasa por valor
    c.mostrar();       // Muestra "Valor almacenado: 100"

    return 0;
}
