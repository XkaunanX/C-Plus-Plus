#include <iostream>
#include <string>

int main() {
    std::string str = "Hola, mundo!";
    std::string sub = str.substr(7, 5);  // Extrae "mundo"
    std::cout << "Subcadena extraída: " << sub << std::endl;
    return 0;
}
