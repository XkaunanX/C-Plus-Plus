#include <iostream>
#include <memory>  // Para punteros inteligentes

class Persona {
public:
    Persona() { std::cout << "Persona creada" << std::endl; }
    ~Persona() { std::cout << "Persona destruida" << std::endl; }
};

int main() {
    // std::unique_ptr asegura que la memoria se libere automáticamente
    std::unique_ptr<Persona> ptr = std::make_unique<Persona>();
    // No es necesario llamar a delete, la memoria se libera cuando 'ptr' sale del ámbito
    return 0;
}
