#include <iostream>
#include <memory>  // Para punteros inteligentes

using namespace std;

// Clase que gestiona un recurso (memoria dinamica)
class Archivo {
private:
    FILE* file;  // Puntero a un archivo

public:
    // Constructor que adquiere el recurso (abre el archivo)
    Archivo(const char* filename) {
        file = fopen(filename, "w");  // Abre un archivo para escribir
        if (file == nullptr) {
            throw runtime_error("No se pudo abrir el archivo.");
        }
        cout << "Archivo abierto: " << filename << endl;
    }

    // Destructor que libera el recurso (cierra el archivo)
    ~Archivo() {
        if (file != nullptr) {
            fclose(file);  // Cierra el archivo
            cout << "Archivo cerrado." << endl;
        }
    }

    // Metodo para escribir en el archivo
    void escribir(const char* texto) {
        if (file != nullptr) {
            fprintf(file, "%s\n", texto);
        }
    }

    // Metodo para leer del archivo (solo como ejemplo)
    void leer() {
        char buffer[256];
        if (file != nullptr) {
            fseek(file, 0, SEEK_SET);  // Mueve el puntero al principio del archivo
            while (fgets(buffer, sizeof(buffer), file)) {
                cout << buffer;
            }
        }
    }
};

int main() {
    try {
        // Usamos un puntero inteligente para gestionar el archivo
        unique_ptr<Archivo> archivo = make_unique<Archivo>("ejemplo.txt");

        // Escribimos en el archivo
        archivo->escribir("Este es un texto de prueba.");

        // Leemos el archivo (solo para mostrar como funciona)
        archivo->leer();

        // Al salir del bloque, el archivo se cierra automaticamente gracias a RAII
    } catch (const exception& e) {
        // En caso de que ocurra un error (por ejemplo, si el archivo no se puede abrir)
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
