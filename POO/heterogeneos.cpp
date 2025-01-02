#include <iostream>
#include <variant>

class Contenedor {
private:
    std::variant<int, double, std::string> valor;

public:
    Contenedor(int v) : valor(v) {}
    Contenedor(double v) : valor(v) {}
    Contenedor(const std::string& v) : valor(v) {}

    void mostrar() const {
        std::visit([](const auto& v) { std::cout << "Valor: " << v << std::endl; }, valor);
    }
};

int main() {
    Contenedor c1(10);
    Contenedor c2(3.14);
    Contenedor c3("Texto");

    c1.mostrar();  // Muestra "Valor: 10"
    c2.mostrar();  // Muestra "Valor: 3.14"
    c3.mostrar();  // Muestra "Valor: Texto"

    return 0;
}
