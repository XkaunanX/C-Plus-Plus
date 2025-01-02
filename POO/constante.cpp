#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;

public:
    Producto(string n, double p) : nombre(n), precio(p) {}

    // Marcamos el metodo como const para permitir su uso en objetos constantes
    void mostrar() const { 
        cout << nombre << " cuesta " << precio << " unidades." << endl;
    }
};

int main() {
    const Producto p1("Producto 1", 10.5);  // Objeto constante
    p1.mostrar();  // Esto ahora funciona porque mostrar es const

    const Producto& p2 = p1;  // Referencia constante
    p2.mostrar();  // Esto tambien funciona porque mostrar es const

    return 0;
}
