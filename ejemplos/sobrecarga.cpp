#include <iostream>
using namespace std;

class Punto {
private:
    int x, y;

public:
    // Constructor
    Punto(int x, int y) : x(x), y(y) {}

    // Sobrecarga del operador +
    Punto operator+(const Punto& p) {
        return Punto(x + p.x, y + p.y);
    }

    // Método para mostrar las coordenadas
    void mostrar() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Punto p1(1, 2), p2(3, 4);
    Punto p3 = p1 + p2;  // Llamada al operador sobrecargado

    p3.mostrar();  // Resultado: (4, 6)
    return 0;
}