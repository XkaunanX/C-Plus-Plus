#include <iostream>
#include <future>
#include <chrono>

int funcionLarga() {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simula una tarea que toma tiempo
    return 42;
}

int main() {
    std::cout << "Llamando a la funcionLarga asíncronamente..." << std::endl;

    // Ejecutar la tarea en segundo plano utilizando std::async
    std::future<int> resultado = std::async(std::launch::async, funcionLarga);

    // Mientras la tarea está en ejecución, podemos hacer otras cosas
    std::cout << "Haciendo otras cosas mientras esperamos..." << std::endl;

    // Obtener el resultado (esto bloqueará hasta que la tarea se complete)
    int valor = resultado.get();

    std::cout << "El resultado de la funcionLarga es: " << valor << std::endl;
    return 0;
}
