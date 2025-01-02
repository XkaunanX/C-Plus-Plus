#include <iostream>
using namespace std;

class Caja {
private:
    int valor;

public:
    Caja(int v) : valor(v) {}

    void mostrarValor() { cout << "Valor: " << valor << endl; }
    void setValor(int v) { valor = v; }
};

int main() {
    Caja c1(10);

    // Puntero
    Caja* ptr = &c1;
    ptr->mostrarValor();

    // Referencia
    Caja& ref = c1;
    ref.setValor(20);
    ref.mostrarValor();

    return 0;
}
