#include <iostream>

class A {
public:
    virtual void mostrar() const {
        std::cout << "Clase A\n";
    }
};

class B : virtual public A {
public:
    void mostrar() const override {
        std::cout << "Clase B\n";
    }
};

class C : virtual public A {
public:
    void mostrar() const override {
        std::cout << "Clase C\n";
    }
};

class D : public B, public C {
public:
    void mostrar() const override {
        std::cout << "Clase D\n";
    }
};

int main() {
    D obj;
    obj.mostrar();  // Muestra "Clase D", evitando la duplicación de A
    return 0;
}
