#include <iostream>
#include <string>

template <typename T>
class Caja {
private:
    T contenido;

public:
    Caja(T c) : contenido(c) {}

    void mostrar() const {
        std::cout << "Contenido de la caja: " << contenido << std::endl;
    }
};

// Especialización de la plantilla para std::string
template <>
class Caja<std::string> {
private:
    std::string contenido;

public:
    Caja(std::string c) : contenido(c) {}

    void mostrar() const {
        std::cout << "Cadena en la caja: " << contenido << std::endl;
    }
};

int main() {
    Caja<int> cajaInt(5);
    cajaInt.mostrar();  // Muestra "Contenido de la caja: 5"

    Caja<std::string> cajaStr("Hola Mundo");
    cajaStr.mostrar();  // Muestra "Cadena en la caja: Hola Mundo"

    return 0;
}
