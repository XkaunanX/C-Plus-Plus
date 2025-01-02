#include <iostream>
using namespace std;

class Caja {
private:
    int valor;

public:
    Caja(int v) : valor(v) {}

    // Declaración de función amiga
    friend void mostrarValor(Caja& c);
};

// Definición de función amiga
void mostrarValor(Caja& c) {
    cout << "Valor de la caja: " << c.valor << endl;
}

int main() {
    Caja c(100);
    mostrarValor(c);  // Función amiga accede a valor privado
    return 0;
}
