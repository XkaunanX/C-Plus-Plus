#include <iostream>

class Vector {
private:
    int x, y;

public:
    Vector(int x, int y) : x(x), y(y) {}

    // Sobrecarga del operador +
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    void mostrar() const {
        std::cout << "Vector(" << x << ", " << y << ")\n";
    }
};

int main() {
    Vector v1(1, 2);
    Vector v2(3, 4);

    Vector v3 = v1 + v2;  // Suma de vectores
    v3.mostrar();  // Muestra Vector(4, 6)

    return 0;
}
