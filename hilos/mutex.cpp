#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

class Contador {
private:
    int contador;      // Contador compartido entre los hilos
    std::mutex mtx;    // Mutex para proteger el acceso al contador

public:
    Contador() : contador(0) {}

    // Incrementar el contador de forma segura con mutex
    void incrementar() {
        std::lock_guard<std::mutex> lock(mtx);
        contador++;
        std::cout << "Contador incrementado a: " << contador << std::endl;
    }

    // Obtener el valor actual del contador
    int obtener() const {
        return contador;
    }
};

class Hilo {
private:
    int id;          // Identificador del hilo
    Contador& contador;  // Referencia al objeto Contador

public:
    Hilo(int id, Contador& contador) : id(id), contador(contador) {}

    // Función para incrementar el contador
    void ejecutar() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simula trabajo
            contador.incrementar();  // Incrementa el contador
            std::cout << "Hilo " << id << " ha incrementado el contador." << std::endl;
        }
    }
};

int main() {
    Contador contador;  // Crear objeto Contador
    std::vector<std::thread> hilos;  // Contenedor para los hilos

    // Crear y ejecutar los hilos
    Hilo hilo1(1, contador);
    Hilo hilo2(2, contador);

    hilos.push_back(std::thread(&Hilo::ejecutar, &hilo1));
    hilos.push_back(std::thread(&Hilo::ejecutar, &hilo2));

    // Esperar que ambos hilos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }

    // Mostrar el valor final del contador
    std::cout << "Contador final: " << contador.obtener() << std::endl;

    return 0;
}
