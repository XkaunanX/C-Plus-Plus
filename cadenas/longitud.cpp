#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string cadena1 = "Hola";
    std::string cadena2 = "mundo";
    
    // Concatenar cadenas
    cadena1 += ", ";
    cadena1 += cadena2;
    std::cout << "Cadena concatenada: " << cadena1 << std::endl;
    
    // Comparar cadenas
    if (cadena1 == "Hola, mundo") {
        std::cout << "Las cadenas son iguales" << std::endl;
    }
    
    // Copiar cadenas
    std::string copia = cadena1;
    std::cout << "Cadena copiada: " << copia << std::endl;
    
    // Buscar subcadena
    size_t pos = cadena1.find("mundo");
    if (pos != std::string::npos) {
        std::cout << "Subcadena encontrada en la posición: " << pos << std::endl;
    }
    
    // Transformar a mayúsculas
    std::transform(cadena1.begin(), cadena1.end(), cadena1.begin(), ::toupper);
    std::cout << "Cadena en mayúsculas: " << cadena1 << std::endl;
    
    return 0;
}