#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    int max_fd = 0;
    struct timeval timeout;

    // Inicializar el conjunto de descriptores
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);  // Establecer stdin (teclado) como descriptor
    max_fd = 0;           // El descriptor máximo es 0 (stdin)

    timeout.tv_sec = 5;  // Timeout de 5 segundos
    timeout.tv_usec = 0;

    printf("Esperando entrada desde stdin...\n");

    // Usar select() para esperar una entrada en stdin
    int ret = select(max_fd + 1, &readfds, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Tiempo de espera agotado\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            char buffer[100];
            read(0, buffer, sizeof(buffer) - 1);
            printf("Entrada recibida: %s\n", buffer);
        }
    }

    return 0;
}
