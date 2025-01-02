#include <iostream>
#include <string>

int main() {
    std::string texto = "Hola";
    texto += " Mundo";  // Concatenación
    std::cout << texto << std::endl;
    std::cout << "Posición de 'Mundo': " << texto.find("Mundo") << std::endl;
    return 0;
}
