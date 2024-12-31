#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ArchivoSecuencial {
private:
    std::string nombreArchivo;
    std::fstream archivo;

public:
    // Constructor que recibe el nombre del archivo
    ArchivoSecuencial(const std::string& nombre) : nombreArchivo(nombre) {}

    // Abrir archivo en modo lectura y escritura
    bool abrirArchivo() {
        archivo.open(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return false;
        }
        return true;
    }

    // Crear y cargar datos en el archivo
    bool cargarDatos(const std::vector<std::string>& datos) {
        archivo.open(nombreArchivo, std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo crear o abrir el archivo para escribir." << std::endl;
            return false;
        }

        // Guardar los datos en el archivo
        for (const auto& dato : datos) {
            archivo.write(dato.c_str(), dato.size());
            archivo.put('\0');  // Terminador nulo para cadenas
        }
        archivo.close();
        return true;
    }

    // Leer y mostrar todos los datos del archivo
    void leerDatos() {
        archivo.open(nombreArchivo, std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
            return;
        }

        std::string dato;
        char ch;
        while (archivo.get(ch)) {
            if (ch == '\0') {
                std::cout << dato << std::endl;
                dato.clear();
            } else {
                dato.push_back(ch);
            }
        }
        archivo.close();
    }

    // Método para buscar un dato en el archivo (lectura secuencial)
    bool buscarDato(const std::string& buscar) {
        archivo.open(nombreArchivo, std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para búsqueda." << std::endl;
            return false;
        }

        std::string dato;
        char ch;
        while (archivo.get(ch)) {
            if (ch == '\0') {
                if (dato == buscar) {
                    std::cout << "Encontrado: " << dato << std::endl;
                    archivo.close();
                    return true;
                }
                dato.clear();
            } else {
                dato.push_back(ch);
            }
        }

        archivo.close();
        std::cout << "No encontrado: " << buscar << std::endl;
        return false;
    }

    // Destructor que asegura cerrar el archivo
    ~ArchivoSecuencial() {
        if (archivo.is_open()) {
            archivo.close();
        }
    }
};

int main() {
    // Crear instancia de la clase ArchivoSecuencial
    ArchivoSecuencial archivo("datos.dat");

    // Cargar datos de ejemplo al archivo
    std::vector<std::string> datos = {"Juan", "Maria", "Pedro", "Ana"};
    if (!archivo.cargarDatos(datos)) {
        return 1;  // Error al cargar los datos
    }

    std::cout << "Contenido del archivo:" << std::endl;
    archivo.leerDatos();  // Leer y mostrar el contenido del archivo

    std::cout << "\nBuscar un dato en el archivo:" << std::endl;
    archivo.buscarDato("Maria");  // Buscar "Maria"

    return 0;
}
