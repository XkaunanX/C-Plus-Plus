#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void tarea_periodica(int sig) {
    printf("Tarea periódica ejecutada\n");
}

int main() {
    struct itimerval timer;

    // Establecer el temporizador para enviar una señal cada 2 segundos
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    signal(SIGALRM, tarea_periodica);  // Registrar la señal para la alarma

    // Establecer el temporizador
    setitimer(ITIMER_REAL, &timer, NULL);

    // El programa principal sigue ejecutándose
    while (1) {
        printf("Esperando tareas...\n");
        sleep(1);  // Simular trabajo en el hilo principal
    }

    return 0;
}
