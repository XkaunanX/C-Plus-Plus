#include <iostream>

class ContadorReferencias {
private:
    int* contador;

public:
    ContadorReferencias() : contador(new int(1)) {}

    // Constructor de copia
    ContadorReferencias(const ContadorReferencias& other) : contador(other.contador) {
        ++(*contador);
    }

    // Destructor
    ~ContadorReferencias() {
        --(*contador);
        if (*contador == 0) {
            delete contador;
            std::cout << "Memoria liberada\n";
        }
    }

    int obtenerContador() const {
        return *contador;
    }
};

int main() {
    ContadorReferencias obj1;
    std::cout << "Contador: " << obj1.obtenerContador() << std::endl;  // 1

    {
        ContadorReferencias obj2 = obj1;  // Copia
        std::cout << "Contador: " << obj1.obtenerContador() << std::endl;  // 2
    }

    std::cout << "Contador: " << obj1.obtenerContador() << std::endl;  // 1
    return 0;
}
