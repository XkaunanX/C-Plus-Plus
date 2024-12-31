# Uso de Hilos en C++

Los hilos (*threads*) permiten la ejecución simultánea de varias tareas dentro de un programa, aprovechando al máximo los procesadores multicore. A partir de **C++11**, se introduce soporte nativo para hilos en la biblioteca estándar.

## Conceptos Básicos

- **Hilos**: Representan unidades independientes de ejecución dentro de un programa.
- **Sincronización**: Gestiona el acceso concurrente a recursos compartidos para evitar condiciones de carrera.
- **Mutua Exclusión**: Uso de herramientas como mutex para garantizar que solo un hilo acceda a una sección crítica a la vez.
- **Paralelismo**: Divide tareas intensivas para ejecutarlas en paralelo, mejorando el rendimiento.

## Herramientas Disponibles

- **`std::thread`**: Para crear y gestionar hilos.
- **`std::mutex`**: Para sincronizar el acceso a recursos compartidos.
- **`std::condition_variable`**: Para la comunicación entre hilos.
- **`std::async`**: Para ejecutar tareas asíncronas con valores de retorno.
- **`std::future` y `std::promise`**: Para manejar resultados de tareas concurrentes.

## Ejemplo Básico

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void imprimir(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Hilo " << id << " ejecutándose\n";
}

int main() {
    std::thread hilos[5];
    for (int i = 0; i < 5; ++i)
        hilos[i] = std::thread(imprimir, i);

    for (auto &hilo : hilos)
        hilo.join();

    return 0;
}
```