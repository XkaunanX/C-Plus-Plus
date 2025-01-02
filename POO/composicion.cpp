#include <iostream>
using namespace std;

// Clase Motor
class Motor {
public:
    void encender() {
        cout << "Motor encendido" << endl;
    }

    void apagar() {
        cout << "Motor apagado" << endl;
    }
};

// Clase Coche
class Coche {
private:
    Motor motor; // Composición: Coche tiene un Motor

public:
    void arrancar() {
        cout << "Arrancando el coche..." << endl;
        motor.encender();
    }

    void detener() {
        cout << "Deteniendo el coche..." << endl;
        motor.apagar();
    }
};

int main() {
    Coche miCoche;
    miCoche.arrancar();
    miCoche.detener();
    
    return 0;
}
