# Conceptos Avanzados en C++

Este repositorio cubre varios conceptos avanzados en C++, que incluyen el uso de `bind`, excepciones, `friend`, punteros inteligentes, lambdas, `map`, punteros RAII, la STL (Standard Template Library), templates, manejo de tiempo y tuplas. A continuación, se explica brevemente cada uno de estos conceptos clave.

## `bind`

`std::bind` es una función de la STL que permite enlazar una función a un conjunto de parámetros fijos, creando así una nueva función. Esto es útil cuando necesitas pre-configurar un conjunto de argumentos para una función y luego pasarla a un contexto donde la función será ejecutada con diferentes parámetros.

### Características:
- Permite crear funciones parciales con parámetros fijos.
- Utiliza la STL `<functional>`.

## Excepciones

Las excepciones en C++ son mecanismos para manejar errores. Se utilizan con los bloques `try`, `catch` y `throw` para gestionar situaciones excepcionales que no pueden ser manejadas de manera directa.

### Características:
- **`try`**: Bloque donde se ejecuta el código que puede generar excepciones.
- **`throw`**: Se usa para lanzar una excepción.
- **`catch`**: Bloque que captura y maneja la excepción.

## `friend`

La palabra clave `friend` permite que una función o clase acceda a los miembros privados y protegidos de otra clase. Esto es útil cuando necesitas que una clase externa pueda acceder directamente a los detalles internos de una clase, sin hacerlos públicos.

### Características:
- Los miembros declarados como `friend` pueden acceder a los miembros privados de la clase.

## Punteros inteligentes

Los punteros inteligentes son objetos que gestionan automáticamente la memoria dinámica en C++, ayudando a prevenir fugas de memoria. Los tipos comunes incluyen `std::unique_ptr`, `std::shared_ptr`, y `std::weak_ptr`.

### Características:
- **`std::unique_ptr`**: Un puntero que tiene la propiedad exclusiva de un objeto. Cuando el puntero se destruye, el objeto también lo es.
- **`std::shared_ptr`**: Un puntero que permite compartir la propiedad de un objeto entre múltiples punteros.
- **`std::weak_ptr`**: Un puntero que no altera el contador de referencias de un `shared_ptr`.

## Lambdas

Las lambdas en C++ son funciones anónimas que pueden ser definidas directamente en el lugar donde se usan. Son útiles cuando se necesita una función rápida y pequeña, especialmente en operaciones de la STL como `std::for_each`.

### Características:
- Definidas con la sintaxis `[captura](parametros){ cuerpo }`.
- Permiten capturar variables locales desde el entorno donde se definen.

## `map`

`std::map` es una estructura de datos de la STL que almacena elementos en pares clave-valor. Es útil cuando se necesita asociar claves únicas con valores y acceder a los elementos mediante esas claves.

### Características:
- Ordenado: Los elementos están ordenados por las claves.
- Las claves son únicas.

## Punteros RAII

RAII (Resource Acquisition Is Initialization) es un patrón de diseño en C++ donde los recursos (como la memoria) son adquiridos y liberados automáticamente cuando un objeto es creado o destruido. Los punteros inteligentes como `std::unique_ptr` y `std::shared_ptr` siguen este patrón.

### Características:
- Garantiza que los recursos sean gestionados de forma automática, eliminando las fugas de memoria.

## STL (Standard Template Library)

La STL es una poderosa colección de clases y funciones en C++ que proporciona estructuras de datos comunes (como `vector`, `list`, `map`) y algoritmos que operan sobre ellas. Es una parte fundamental de C++ y facilita la programación genérica y reutilizable.

### Características:
- Contiene colecciones genéricas como `vector`, `map`, `set`, etc.
- Ofrece algoritmos eficientes para realizar operaciones sobre esas colecciones.

## Templates

Los templates en C++ permiten escribir código genérico. Los templates pueden ser de funciones o clases, y permiten que el mismo código funcione con diferentes tipos de datos.

### Características:
- **Templates de funciones**: Permiten crear funciones que pueden trabajar con cualquier tipo de dato.
- **Templates de clases**: Permiten definir clases que operan sobre diferentes tipos de datos.

## Manejo de tiempo

C++ proporciona varias formas de manejar tiempo, desde medir el tiempo de ejecución de un programa hasta manipular fechas y horas.

### Características:
- **`<chrono>`**: Biblioteca para medir el tiempo de ejecución de funciones y manipular intervalos de tiempo.
- **`std::chrono::high_resolution_clock`**: Para medir tiempos de alta precisión.

## Tuplas

Una `std::tuple` es una estructura que puede almacenar múltiples valores de diferentes tipos, similar a un array, pero permitiendo tipos heterogéneos.

### Características:
- Almacena múltiples valores de tipos diferentes.
- Acceso a los elementos mediante `std::get` o `std::tie`.
