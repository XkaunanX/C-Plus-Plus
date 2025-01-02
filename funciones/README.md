# Declaracion y Definicion de Funciones en c++

En C++, una funcion debe ser declarada antes de ser usada. La declaracion especifica el tipo de valor que la funcion devolvera y los parametros que tomara (si es que tiene). La definicion de la funcion es donde se describe el cuerpo de la funcion, es decir, que hace la funcion cuando es llamada.

## Funciones Inline

Una funcion `inline` es una funcion cuya definicion se incluye directamente en el lugar donde se llama. Esto puede mejorar el rendimiento al eliminar la sobrecarga de la llamada a la funcion. Sin embargo, se debe usar con precaucion, ya que la expansion de la funcion inline puede aumentar el tamaño del codigo.

## Funciones Recursivas

Una funcion recursiva es una funcion que se llama a si misma. Este tipo de funcion es util en algoritmos que pueden ser divididos en subproblemas similares, como en el caso de las estructuras de arbol o cuando se trabaja con algoritmos de busqueda y ordenamiento.

## Funciones Variadic

Las funciones variadic son funciones que pueden recibir un numero variable de argumentos. Esto se logra mediante el uso de macros como `va_start`, `va_arg`, y `va_end` o mediante el uso de plantillas (`templates`).

## Sobrecarga de Funciones

C++ permite que varias funciones tengan el mismo nombre pero con diferentes tipos o numeros de parametros. Esto se conoce como sobrecarga de funciones. La sobrecarga se resuelve en tiempo de compilacion y permite que el mismo nombre de funcion sea utilizado para realizar diferentes tareas.

## Funciones Amigas (Friend Functions)

Las funciones amigas son aquellas que no pertenecen a una clase, pero pueden acceder a sus miembros privados o protegidos. Esto permite que una funcion externa pueda operar sobre los datos internos de una clase sin ser parte de ella.

## Enlace Estático y Dinámico

El enlace de funciones en C++ puede ser estático o dinámico. El enlace estático ocurre cuando la llamada a la funcion se resuelve en tiempo de compilacion, mientras que el enlace dinamico ocurre cuando la funcion se resuelve en tiempo de ejecucion. Este ultimo es mas comun en el uso de polimorfismo.

## Tipos de Retorno y Punteros a Funciones

En C++, una funcion puede devolver cualquier tipo de dato, incluyendo punteros o referencias. Ademas, es posible definir punteros a funciones, lo que permite almacenar y llamar a funciones de manera dinámica.

## Funciones Lambda

Las funciones lambda son funciones anónimas que pueden ser definidas en cualquier parte del código. Son especialmente útiles en operaciones que requieren una funcion como parametro, como en el caso de las algoritmos de la STL (Biblioteca Estándar de Plantillas).
