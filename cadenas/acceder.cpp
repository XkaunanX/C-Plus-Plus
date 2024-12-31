#include <iostream>
#include <string>

int main() {
    std::string str = "Hola";
    std::cout << "El primer carácter es: " << str[0] << std::endl;
    std::cout << "El segundo carácter es: " << str.at(1) << std::endl;
    return 0;
}
