#include <iostream>
#include <string>
using namespace std;

// Clase Persona
class Persona {
private:
    string nombre;
public:
    Persona(string nombre) : nombre(nombre) {}

    void mostrarNombre() const {
        cout << "Nombre de la persona: " << nombre << endl;
    }
};

// Clase Carro
class Carro {
private:
    string modelo;
    Persona dueño; // La clase Carro tiene una referencia a un objeto Persona

public:
    Carro(string modelo, Persona dueño) : modelo(modelo), dueño(dueño) {}

    void mostrarInformacion() const {
        cout << "Modelo del carro: " << modelo << endl;
        dueño.mostrarNombre();  // Usando el objeto Persona
    }
};

int main() {
    Persona persona1("Juan");
    Carro carro1("Toyota Corolla", persona1);

    carro1.mostrarInformacion();  // Salida: Modelo del carro: Toyota Corolla, Nombre de la persona: Juan

    return 0;
}
