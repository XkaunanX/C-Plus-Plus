#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

class ArchivoIndexado {
private:
    std::string nombreArchivo;
    std::fstream archivo;
    size_t tamañoRegistro;  // Tamaño de cada registro en el archivo
    std::unordered_map<int, long> índice;  // Índice que almacena la posición de cada registro (por ejemplo, usando un ID)

public:
    // Constructor que recibe el nombre del archivo y el tamaño del registro
    ArchivoIndexado(const std::string& nombre, size_t tamaño) 
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
    bool cargarDatos(const std::vector<std::pair<int, std::string>>& datos) {
        archivo.open(nombreArchivo, std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo crear o abrir el archivo para escribir." << std::endl;
            return false;
        }

        // Escribir los datos en el archivo y crear el índice
        for (size_t i = 0; i < datos.size(); ++i) {
            int id = datos[i].first;
            const std::string& dato = datos[i].second;
            
            // Escribir en la posición adecuada
            archivo.seekp(i * tamañoRegistro, std::ios::beg); // Moverse al registro i
            archivo.write(reinterpret_cast<const char*>(&id), sizeof(int));
            archivo.write(dato.c_str(), dato.size());
            archivo.put('\0');  // Terminador nulo para cadenas

            // Crear el índice con la posición del registro
            índice[id] = i * tamañoRegistro;
        }

        archivo.close();
        return true;
    }

    // Buscar un registro por ID utilizando el índice
    std::string buscarPorID(int id) {
        if (índice.find(id) == índice.end()) {
            std::cerr << "ID no encontrado: " << id << std::endl;
            return "";
        }

        // Obtener la posición del registro desde el índice
        long posición = índice[id];
        archivo.open(nombreArchivo, std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
            return "";
        }

        // Mover el puntero al registro
        archivo.seekg(posición, std::ios::beg);

        // Leer el registro
        int idLeído;
        char buffer[256];
        archivo.read(reinterpret_cast<char*>(&idLeído), sizeof(int));
        archivo.getline(buffer, 256, '\0');
        std::string datoLeído(buffer);

        archivo.close();
        return datoLeído;
    }

    // Modificar un registro por ID
    bool modificarPorID(int id, const std::string& nuevoDato) {
        if (índice.find(id) == índice.end()) {
            std::cerr << "ID no encontrado: " << id << std::endl;
            return false;
        }

        // Obtener la posición del registro desde el índice
        long posición = índice[id];
        archivo.open(nombreArchivo, std::ios::in | std::ios::out | std::ios::binary);
        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo para modificar." << std::endl;
            return false;
        }

        // Mover el puntero al registro
        archivo.seekp(posición, std::ios::beg);

        // Escribir el nuevo dato
        archivo.write(reinterpret_cast<const char*>(&id), sizeof(int));
        archivo.write(nuevoDato.c_str(), nuevoDato.size());
        archivo.put('\0');  // Terminador nulo para cadenas

        archivo.close();
        return true;
    }

    // Destructor que asegura cerrar el archivo
    ~ArchivoIndexado() {
        if (archivo.is_open()) {
            archivo.close();
        }
    }
};

int main() {
    // Crear instancia de la clase ArchivoIndexado
    ArchivoIndexado archivo("datos_indexados.dat", 64);  // Suponemos que cada registro tiene 64 bytes

    // Cargar datos de ejemplo en el archivo
    std::vector<std::pair<int, std::string>> datos = {
        {101, "Juan"},
        {102, "Maria"},
        {103, "Pedro"},
        {104, "Ana"}
    };

    if (!archivo.cargarDatos(datos)) {
        return 1;  // Error al cargar los datos
    }

    // Buscar y mostrar el contenido de un registro
    std::cout << "Contenido del archivo para ID 102: " << archivo.buscarPorID(102) << std::endl;

    // Modificar un dato en el archivo
    std::cout << "\nModificar el dato para el ID 103..." << std::endl;
    archivo.modificarPorID(103, "Carlos");

    // Leer nuevamente el dato modificado
    std::cout << "Nuevo dato para ID 103: " << archivo.buscarPorID(103) << std::endl;

    return 0;
}
