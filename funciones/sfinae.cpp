#include <iostream>
#include <type_traits>

// Función template general
template <typename T>
void imprimir(T val) {
    std::cout << "Valor: " << val << std::endl;
}

// Especialización para tipos enteros
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type
imprimir(T val) {
    std::cout << "Valor entero: " << val << std::endl;
}

int main() {
    imprimir(10);  // Llama a la versión especializada para enteros
    imprimir(3.14);  // Llama a la versión general para otros tipos

    return 0;
}
