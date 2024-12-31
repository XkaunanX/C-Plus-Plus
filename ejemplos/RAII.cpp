#include <iostream>
#include <fstream>
#include <string>  
#include <stdexcept>
using namespace std;

class Archivo {
private:
    ifstream file;

public:
    // Constructor que abre el archivo y lanza una excepción si no se puede abrir
    Archivo(const string& nombre) {
        file.open(nombre);
        if (!file) {
            throw runtime_error("No se pudo abrir el archivo: " + nombre);
        }
    }

    // Destructor para asegurarse de cerrar el archivo si está abierto
    ~Archivo() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Método para leer y mostrar el contenido del archivo
    void leer() {
        string linea;
        while (getline(file, linea)) {  // Usar getline correctamente
            cout << linea << endl;
        }

        // Comprobar si se ha alcanzado el final del archivo sin error
        if (file.bad()) {
            cerr << "Error de lectura en el archivo." << endl;
        }
    }
};

int main() {
    try {
        Archivo archivo("ejemplo.txt");
        archivo.leer();  // Leer y mostrar el contenido del archivo
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;  // Retorna un código de error si hay un problema con el archivo
    }

    return 0;
}
