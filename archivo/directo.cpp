#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ArchivoDirecto {
private:
    std::string nombreArchivo;
    std::fstream archivo;
    size_t tamañoRegistro;  // Tamaño de cada registro en el archivo

public:
    // Constructor que recibe el nombre del archivo y el tamaño del registro
    ArchivoDirecto(const std::string& nombre, size_t tamaño) 
        : nombreArchivo(nombre), tamañoRegistro(tamaño) {}

    // Abrir archivo en modo lectura y escritura
    bool abrirArchivo() {
        archivo.open(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return false;
        }
        return true;
    }

    // Crear y cargar datos en el archivo en posiciones específicas (acceso directo)
    bool cargarDatos(const std::vector<std::string>& datos) {
        archivo.open(nombreArchivo, std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo crear o abrir el archivo para escribir." << std::endl;
            return false;
        }

        // Escribir los datos en el archivo en posiciones fijas (acceso directo)
        for (size_t i = 0; i < datos.size(); ++i) {
            archivo.seekp(i * tamañoRegistro, std::ios::beg); // Mover el puntero al lugar correcto
            archivo.write(datos[i].c_str(), datos[i].size());
            archivo.put('\0');  // Terminador nulo para cadenas
        }
        archivo.close();
        return true;
    }

    // Leer un dato de una posición específica
    std::string leerDato(size_t index) {
        archivo.open(nombreArchivo, std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
            return "";
        }

        // Mover el puntero al registro específico
        archivo.seekg(index * tamañoRegistro, std::ios::beg);

        // Leer el dato
        std::string dato;
        char ch;
        while (archivo.get(ch)) {
            if (ch == '\0') {
                break;
            }
            dato.push_back(ch);
        }
        archivo.close();
        return dato;
    }

    // Modificar un dato en una posición específica
    bool modificarDato(size_t index, const std::string& nuevoDato) {
        archivo.open(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para modificar." << std::endl;
            return false;
        }

        // Mover el puntero al registro específico
        archivo.seekp(index * tamañoRegistro, std::ios::beg);

        // Escribir el nuevo dato
        archivo.write(nuevoDato.c_str(), nuevoDato.size());
        archivo.put('\0');  // Terminador nulo para cadenas

        archivo.close();
        return true;
    }

    // Destructor que asegura cerrar el archivo
    ~ArchivoDirecto() {
        if (archivo.is_open()) {
            archivo.close();
        }
    }
};

int main() {
    // Crear instancia de la clase ArchivoDirecto
    ArchivoDirecto archivo("datos_directo.dat", 20);  // Suponemos que cada registro tiene 20 bytes

    // Cargar datos de ejemplo en el archivo
    std::vector<std::string> datos = {"Juan", "Maria", "Pedro", "Ana"};
    if (!archivo.cargarDatos(datos)) {
        return 1;  // Error al cargar los datos
    }

    // Leer y mostrar el contenido del archivo
    std::cout << "Contenido del archivo:" << std::endl;
    for (size_t i = 0; i < datos.size(); ++i) {
        std::cout << "Dato en índice " << i << ": " << archivo.leerDato(i) << std::endl;
    }

    // Modificar un dato en el archivo
    std::cout << "\nModificar el dato en el índice 2..." << std::endl;
    archivo.modificarDato(2, "Carlos");

    // Leer nuevamente el dato modificado
    std::cout << "Nuevo dato en índice 2: " << archivo.leerDato(2) << std::endl;

    return 0;
}