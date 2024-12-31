#include <iostream>
using namespace std;

int main() {
    // Asignación de memoria dinámica para un entero
    int* ptr = new int(5);

    cout << "Valor almacenado en la memoria dinámica: " << *ptr << endl;

    // Liberar la memoria asignada
    delete ptr;
    return 0;
}
