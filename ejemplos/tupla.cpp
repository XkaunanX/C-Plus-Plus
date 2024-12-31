#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> tupla(10, 3.14, "Hola Mundo");

    std::cout << "Primer elemento: " << std::get<0>(tupla) << std::endl;
    std::cout << "Segundo elemento: " << std::get<1>(tupla) << std::endl;
    std::cout << "Tercer elemento: " << std::get<2>(tupla) << std::endl;

    return 0;
}
