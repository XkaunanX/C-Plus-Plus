# Estructuras de Datos en C++: `list`, `queue`, `stack`, `vector`

En C++, las bibliotecas estándar incluyen varias estructuras de datos comunes que permiten manejar colecciones de elementos de manera eficiente. Estas estructuras están contenidas en los encabezados `<list>`, `<queue>`, `<stack>` y `<vector>`, cada una con características y usos específicos.

## `std::list`

La clase `std::list` es una lista doblemente enlazada que permite la inserción y eliminación de elementos de manera eficiente en cualquier parte de la lista.

### Características:
- **Acceso secuencial**: No permite acceso aleatorio a los elementos.
- **Inserciones y eliminaciones eficientes**: Se pueden agregar o quitar elementos de cualquier parte de la lista con un costo constante.
- **Uso común**: Ideal para aplicaciones donde se necesita manipular frecuentemente el inicio o el final de una secuencia de datos.

## `std::queue`

La clase `std::queue` implementa una cola FIFO (First In, First Out), lo que significa que el primer elemento insertado es el primero en ser eliminado.

### Características:
- **FIFO**: Elementos añadidos al final de la cola y eliminados desde el principio.
- **No permite acceso aleatorio**: Solo puedes acceder al frente y al final de la cola.
- **Uso común**: Ideal para la gestión de tareas o procesos en orden de llegada, como en sistemas de impresión o en la programación de tareas.

## `std::stack`

La clase `std::stack` implementa una pila LIFO (Last In, First Out), donde el último elemento agregado es el primero en ser eliminado.

### Características:
- **LIFO**: Los elementos se apilan de manera que el último agregado es el primero en ser eliminado.
- **Acceso restringido**: Solo puedes acceder al elemento superior de la pila.
- **Uso común**: Útil en algoritmos que requieren retroceso, como la evaluación de expresiones o el recorrido de grafos.

## `std::vector`

La clase `std::vector` es un arreglo dinámico que permite el acceso aleatorio y redimensionamiento dinámico de su tamaño.

### Características:
- **Acceso aleatorio**: Permite acceder a cualquier elemento por su índice de manera eficiente.
- **Redimensionamiento dinámico**: El tamaño de un vector se ajusta automáticamente a medida que se agregan o eliminan elementos.
- **Uso común**: Es la estructura más versátil y generalmente se utiliza cuando se necesita un contenedor flexible que pueda crecer según sea necesario.

## Comparación de Estructuras de Datos

| **Estructura** | **Tipo**      | **Acceso**               | **Complejidad de Inserción/Eliminación** | **Uso Común**                   |
|----------------|---------------|--------------------------|------------------------------------------|---------------------------------|
| `std::list`    | Lista doble   | Secuencial               | O(1) en cualquier parte de la lista      | Manipulación frecuente de datos |
| `std::queue`   | Cola FIFO     | Acceso solo al frente y al final | O(1) al agregar o quitar elementos       | Gestión de tareas o procesos    |
| `std::stack`   | Pila LIFO     | Acceso solo al tope       | O(1) al agregar o quitar elementos       | Algoritmos de retroceso         |
| `std::vector`  | Arreglo dinámico | Acceso aleatorio        | O(1) promedio, O(n) en redimensionamiento | Datos que requieren acceso rápido |
