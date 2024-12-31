#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string n, int e) : nombre(n), edad(e) {}

    // Métodos
    void saludar() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }

    // Métodos para obtener los valores
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
};

int main() {
    Persona p1("Carlos", 30);
    p1.saludar();
    return 0;
}