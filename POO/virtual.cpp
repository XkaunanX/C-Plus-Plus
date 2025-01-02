#include <iostream>

class Animal {
public:
    virtual void hacerSonido() const {
        std::cout << "El animal hace un sonido.\n";
    }
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "El perro dice: ¡Guau!\n";
    }
};

int main() {
    Perro perro;
    Animal* ptrAnimal = &perro;

    // Uso de punteros a miembros virtuales
    void (Animal::*ptrFuncion)() const = &Animal::hacerSonido;
    (ptrAnimal->*ptrFuncion)();  // Llama a Perro::hacerSonido

    return 0;
}
