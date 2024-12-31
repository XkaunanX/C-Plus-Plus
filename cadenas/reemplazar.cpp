#include <iostream>
#include <string>

int main() {
    std::string str = "Hola, mundo!";
    str.replace(7, 5, "C++");  // Reemplaza "mundo" por "C++"
    std::cout << str << std::endl;
    return 0;
}
