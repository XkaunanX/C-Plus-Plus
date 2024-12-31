#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;

public:
    Producto(string n, double p) : nombre(n), precio(p) {}

    // Mark the method as const to allow calling it on const objects
    void mostrar() const { 
        cout << nombre << " cuesta " << precio << " unidades." << endl;
    }
};

int main() {
    const Producto p1("Producto 1", 10.5);  // Constant object
    p1.mostrar();  // This will now work since mostrar is const

    const Producto& p2 = p1;  // Constant reference
    p2.mostrar();  // This also works because mostrar is const

    return 0;
}
