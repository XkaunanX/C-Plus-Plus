#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <semaphore.h>  // Requiere C++20

class ContadorRecurso {
private:
    std::counting_semaphore<5> semaforo;  // Semáforo con un recurso inicial de 5
    int contador;  // Para mostrar el estado del recurso

public:
    ContadorRecurso() : semaforo(5), contador(5) {}  // Inicializa el semáforo con 5 recursos

    // Intentar tomar un recurso (decrementar el semáforo)
    void tomar_recurso(int id) {
        std::cout << "Hilo " << id << " intenta tomar un recurso...\n";

        // Disminuir el semáforo (tomar un recurso)
        semaforo.acquire();

        // Si llegó aquí, significa que el recurso ha sido adquirido
        contador--;
        std::cout << "Hilo " << id << " tomó un recurso. Recursos disponibles: " << contador << "\n";
    }

    // Liberar un recurso (incrementar el semáforo)
    void liberar_recurso(int id) {
        std::cout << "Hilo " << id << " libera un recurso...\n";
        semaforo.release();  // Liberar un recurso
        contador++;
        std::cout << "Hilo " << id << " liberó un recurso. Recursos disponibles: " << contador << "\n";
    }

    // Obtener los recursos disponibles
    int obtener_recursos() const {
        return contador;
    }
};

class Hilo {
private:
    int id;  // Identificador del hilo
    ContadorRecurso& recurso;  // Referencia al contador de recursos

public:
    Hilo(int id, ContadorRecurso& recurso) : id(id), recurso(recurso) {}

    // Función que simula el trabajo del hilo tomando y liberando recursos
    void ejecutar() {
        for (int i = 0; i < 3; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simula trabajo previo
            recurso.tomar_recurso(id);  // Tomar un recurso
            std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Simula trabajo con el recurso
            recurso.liberar_recurso(id);  // Liberar el recurso
        }
    }
};

int main() {
    ContadorRecurso recurso;  // Objeto ContadorRecurso para gestionar los recursos
    std::vector<std::thread> hilos;  // Contenedor de hilos

    // Crear hilos que intentarán tomar y liberar recursos
    Hilo hilo1(1, recurso);
    Hilo hilo2(2, recurso);
    Hilo hilo3(3, recurso);

    hilos.push_back(std::thread(&Hilo::ejecutar, &hilo1));
    hilos.push_back(std::thread(&Hilo::ejecutar, &hilo2));
    hilos.push_back(std::thread(&Hilo::ejecutar, &hilo3));

    // Esperar a que los hilos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }

    // Mostrar el valor final del contador de recursos
    std::cout << "Recursos finales disponibles: " << recurso.obtener_recursos() << std::endl;

    return 0;
}