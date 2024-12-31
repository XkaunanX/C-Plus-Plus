#include <iostream>
using namespace std;

// Plantilla de función suma
template <typename T>
T suma(T a, T b) {
    return a + b;
}

int main() {
    // Usando la plantilla con int
    int a = 5, b = 10;
    int resultadoInt = suma(a, b);  // Llama a la versión de la plantilla con int
    cout << "La suma de los enteros es: " << resultadoInt << endl;

    // Usando la plantilla con double
    double x = 3.14, y = 2.71;
    double resultadoDouble = suma(x, y);  // Llama a la versión de la plantilla con double
    cout << "La suma de los doubles es: " << resultadoDouble << endl;

    // Usando la plantilla con float
    float p = 1.5f, q = 2.5f;
    float resultadoFloat = suma(p, q);  // Llama a la versión de la plantilla con float
    cout << "La suma de los floats es: " << resultadoFloat << endl;

    return 0;
}