#include <iostream>
#include <unistd.h>  // Necesario para fork()
#include <sys/types.h>  // Necesario para pid_t

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid == -1) {
        // Error en el fork()
        std::cerr << "Error al crear el proceso hijo." << std::endl;
        return 1;
    } 
    else if (pid == 0) {
        // Proceso hijo
        std::cout << "Soy el proceso hijo. Mi PID es: " << getpid() << std::endl;
        std::cout << "PID del proceso padre: " << getppid() << std::endl;
    } 
    else {
        // Proceso padre
        std::cout << "Soy el proceso padre. Mi PID es: " << getpid() << std::endl;
        std::cout << "PID del proceso hijo: " << pid << std::endl;
    }

    return 0;
}