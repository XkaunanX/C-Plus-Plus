#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Clase abstracta
class Forma {
public:
    virtual void dibujar() const = 0;  // Metodo abstracto puro
    virtual ~Forma() = default;  // Destructor virtual
};

// Clase derivada 1: Circulo
class Circulo : public Forma {
private:
    float radio;

public:
    Circulo(float r) : radio(r) {}

    // Sobrecarga de dibujar
    void dibujar() const override {
        cout << "Dibujando un Circulo con radio: " << radio << endl;
    }

    // Metodo adicional
    void calcularArea() const {
        cout << "Area del circulo: " << 3.14159f * radio * radio << endl;
    }
};

// Clase derivada 2: Rectangulo
class Rectangulo : public Forma {
private:
    float largo, ancho;

public:
    Rectangulo(float l, float a) : largo(l), ancho(a) {}

    // Sobrecarga de dibujar
    void dibujar() const override {
        cout << "Dibujando un Rectangulo de " << largo << "x" << ancho << endl;
    }

    // Metodo adicional
    void calcularArea() const {
        cout << "Area del rectangulo: " << largo * ancho << endl;
    }
};

// Herencia multiple (clases con mas de una clase base)
class Triangulo {
private:
    float base, altura;

public:
    Triangulo(float b, float h) : base(b), altura(h) {}

    void dibujar() const {
        cout << "Dibujando un Triangulo con base: " << base << " y altura: " << altura << endl;
    }

    void calcularArea() const {
        cout << "Area del triangulo: " << (base * altura) / 2 << endl;
    }
};

// Clase derivada de la herencia multiple
class FiguraCompleta : public Circulo, public Rectangulo, public Triangulo {
public:
    FiguraCompleta(float r, float l, float a, float b, float h)
        : Circulo(r), Rectangulo(l, a), Triangulo(b, h) {}

    // Metodo para usar polimorfismo
    void dibujar() const override {
        Circulo::dibujar();
        Rectangulo::dibujar();
        Triangulo::dibujar();
    }
};

// Clase friend
class ManagerDeFiguras {
private:
    vector<shared_ptr<Forma>> formas;

public:
    void agregarFigura(shared_ptr<Forma> figura) {
        formas.push_back(figura);
    }

    void mostrarFormas() const {
        for (const auto& forma : formas) {
            forma->dibujar();  // Llamada polimorfica
        }
    }

    // Funcion friend para mostrar el area
    friend void calcularAreas(const ManagerDeFiguras& manager);
};

// Funcion friend que puede acceder a los miembros privados de ManagerDeFiguras
void calcularAreas(const ManagerDeFiguras& manager) {
    for (const auto& forma : manager.formas) {
        if (auto circulo = dynamic_cast<const Circulo*>(forma.get())) {
            circulo->calcularArea();
        }
        else if (auto rectangulo = dynamic_cast<const Rectangulo*>(forma.get())) {
            rectangulo->calcularArea();
        }
        else if (auto triangulo = dynamic_cast<const Triangulo*>(forma.get())) {
            triangulo->calcularArea();
        }
    }
}

// Menu interactivo
void mostrarMenu() {
    cout << "\nMenu Interactivo:\n";
    cout << "1. Agregar un Circulo\n";
    cout << "2. Agregar un Rectangulo\n";
    cout << "3. Agregar un Triangulo\n";
    cout << "4. Mostrar todas las formas\n";
    cout << "5. Calcular el area de todas las formas\n";
    cout << "6. Salir\n";
    cout << "Elija una opcion: ";
}

int main() {
    ManagerDeFiguras manager;
    int opcion;
    float radio, largo, ancho, base, altura;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:  // Agregar Circulo
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                manager.agregarFigura(make_shared<Circulo>(radio));
                break;

            case 2:  // Agregar Rectangulo
                cout << "Ingrese el largo y el ancho del rectangulo: ";
                cin >> largo >> ancho;
                manager.agregarFigura(make_shared<Rectangulo>(largo, ancho));
                break;

            case 3:  // Agregar Triangulo
                cout << "Ingrese la base y la altura del triangulo: ";
                cin >> base >> altura;
                manager.agregarFigura(make_shared<Triangulo>(base, altura));
                break;

            case 4:  // Mostrar todas las formas
                manager.mostrarFormas();
                break;

            case 5:  // Calcular area de todas las formas
                calcularAreas(manager);
                break;

            case 6:  // Salir
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opcion invalida, por favor intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
