#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const { cout << "Sonido de animal" << endl; }
    virtual ~Animal() {} // Destructor virtual
};

class Perro : public Animal {
public:
    void hacerSonido() const override { cout << "Guau!" << endl; }
};

class Gato : public Animal {
public:
    void hacerSonido() const override { cout << "Miau!" << endl; }
};

int main() {
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();

    animal1->hacerSonido();  // Guau!
    animal2->hacerSonido();  // Miau!

    delete animal1;
    delete animal2;
    return 0;
}
