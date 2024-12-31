#include <iostream>
using namespace std;

// Clase base
class Animal {
public:
    virtual void hacerSonido() { cout << "Sonido de animal" << endl; }
};

// Clase derivada
class Perro : public Animal {
public:
    void hacerSonido() override { cout << "Guau!" << endl; }
};

// Clase derivada
class Gato : public Animal {
public:
    void hacerSonido() override { cout << "Miau!" << endl; }
};

int main() {
    Animal* a = new Perro();
    a->hacerSonido();  // Salida: Guau!

    a = new Gato();
    a->hacerSonido();  // Salida: Miau!

    delete a;
    return 0;
}