#include <iostream>
#include <stdexcept>
using namespace std;

class Division {
public:
    static double dividir(int a, int b) {
        if (b == 0) {
            throw invalid_argument("División por cero no permitida");
        }
        return static_cast<double>(a) / b;
    }
};

int main() {
    try {
        cout << "Resultado: " << Division::dividir(10, 2) << endl;
        cout << "Resultado: " << Division::dividir(10, 0) << endl;  // Excepción
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}