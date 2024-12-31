#include <iostream>
#include <string>

int main() {
    std::string str = "Hola, mundo!";
    size_t pos = str.find("mundo");
    if (pos != std::string::npos) {
        std::cout << "'mundo' encontrado en la posición: " << pos << std::endl;
    } else {
        std::cout << "Subcadena no encontrada" << std::endl;
    }
    return 0;
}
