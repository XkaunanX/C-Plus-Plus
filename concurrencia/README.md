# Uso de `setitimer`, `select()` y `async` en C

Este repositorio explora cómo trabajar con temporizadores y manejar operaciones asíncronas en C utilizando funciones como `setitimer`, `select()` y mecanismos para gestionar tareas en paralelo sin bloquear el flujo de ejecución del programa.

## `setitimer`

La función `setitimer()` en C se utiliza para configurar temporizadores que generan señales a intervalos regulares. Existen tres tipos de temporizadores: `ITIMER_REAL` (para señales de tiempo real), `ITIMER_VIRTUAL` (para el tiempo de CPU consumido por el proceso), e `ITIMER_PROF` (para el tiempo de CPU consumido por el proceso y sus hijos). Es útil en situaciones donde se necesitan realizar tareas a intervalos regulares o cuando se desea medir el tiempo transcurrido de una operación. El temporizador configurado mediante `setitimer()` puede enviar una señal, como `SIGALRM`, cuando el temporizador expira, permitiendo que el programa responda a eventos temporales sin bloquear la ejecución.

### Casos de uso:
- Realizar tareas periódicas como limpieza de recursos.
- Gestionar tiempo de ejecución de operaciones.
- Enviar señales a procesos cuando un intervalo de tiempo se haya cumplido.

## `select()`

La función `select()` se utiliza para monitorear múltiples descriptores de archivo y determinar si están listos para realizar operaciones de entrada o salida. Con `select()`, un programa puede esperar hasta que uno o más descriptores estén listos sin bloquear la ejecución del programa. Esto es útil cuando se trabaja con múltiples fuentes de entrada, como archivos, sockets o dispositivos, y se necesita gestionar múltiples eventos de manera eficiente. `select()` permite la espera por eventos como la disponibilidad de datos para lectura o la capacidad para escribir sin tener que bloquearse a esperar activamente.

### Casos de uso:
- Manejo de múltiples conexiones en servidores.
- Monitoreo de archivos o dispositivos para detectar cambios.
- Gestión eficiente de entradas de usuario sin bloqueo.

## `async` y tareas asíncronas

El uso de programación asíncrona permite ejecutar operaciones que pueden tomar tiempo (como leer archivos, acceder a bases de datos o hacer peticiones de red) sin bloquear la ejecución de otras tareas. En C, aunque no hay una funcionalidad nativa tan directa como en otros lenguajes, se pueden usar mecanismos como hilos, señales o bibliotecas externas para gestionar tareas en paralelo. La programación asíncrona mejora la eficiencia de los programas, ya que permite que el flujo de ejecución no se detenga por operaciones de entrada/salida o esperas de largo tiempo.

### Casos de uso:
- Ejecución de tareas en segundo plano.
- Optimización de programas que requieren realizar varias operaciones simultáneamente, como servidores web o aplicaciones con interfaces gráficas interactivas.
- Mejora del rendimiento en aplicaciones que manejan múltiples solicitudes simultáneamente.

## Resumen

- **`setitimer()`**: Permite establecer temporizadores para generar señales a intervalos regulares, útil para tareas programadas y gestión del tiempo de ejecución.
- **`select()`**: Monitorea múltiples descriptores de archivo para determinar su disponibilidad para operaciones de entrada/salida, útil para la gestión eficiente de eventos sin bloquear el flujo de ejecución.
- **`async` y tareas asíncronas**: Permiten la ejecución de operaciones de manera no bloqueante, mejorando la eficiencia en programas con múltiples tareas que pueden realizarse en paralelo.
