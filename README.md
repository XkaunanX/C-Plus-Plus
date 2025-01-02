# C++

C++ es un lenguaje de programacion de proposito general desarrollado por **Bjarne Stroustrup** en **1979** como una extension de C en los laboratorios Bell. Inicialmente llamado "C con clases", fue renombrado a C++ en 1983 para reflejar la adicion de caracteristicas avanzadas al lenguaje original.

## **Contexto Historico y Proposito**

C++ nacio para combinar las capacidades de bajo nivel de C con herramientas de programacion de alto nivel, como la programacion orientada a objetos. Esto permitio a los desarrolladores escribir programas eficientes y flexibles, adecuados para aplicaciones complejas, como sistemas operativos, motores de videojuegos, y simulaciones cientificas.

## **Caracteristicas de C++**

### 1. Lenguaje de Bajo Nivel
C++ proporciona acceso directo al hardware y manipulacion de registros de memoria, lo que lo hace ideal para el desarrollo de sistemas operativos y software de alto rendimiento. Su sintaxis permite una gestion precisa de los recursos del sistema.

**Ejemplo:**

```cpp
#include <iostream>

int main() {
    int numero = 10;
    int* puntero = &numero;  // Puntero que apunta a la direccion de memoria de 'numero'
    
    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Direccion de memoria de numero: " << puntero << std::endl;
    std::cout << "Valor a traves del puntero: " << *puntero << std::endl;  // Accediendo al valor mediante el puntero
    
    return 0;
}
```

### 2. Ausencia de Recoleccion de Basura
Al igual que C, C++ no cuenta con un recolector de basura automatizado. Esto otorga a los desarrolladores control total sobre la asignacion y liberacion de memoria, pero tambien requiere una gestion manual cuidadosa para evitar fugas de memoria.

**Ejemplo:**

```cpp
#include <iostream>

int main() {
    int* puntero = new int;  // Asignacion dinamica de memoria
    
    *puntero = 10;
    std::cout << "Valor almacenado: " << *puntero << std::endl;
    
    delete puntero;  // Liberacion manual de memoria
    puntero = nullptr;  // Se recomienda asignar nullptr al puntero tras liberarlo
    
    return 0;
}
```

### 3. Uso de Punteros
C++ extiende el uso de punteros de C, permitiendo la manipulacion directa de memoria, asi como el acceso a direcciones y el manejo de estructuras de datos dinamicas como listas enlazadas y arboles. Los punteros son fundamentales en el manejo de objetos y recursos en la memoria.

**Ejemplo:**

```cpp
#include <iostream>

class Persona {
public:
    std::string nombre;
    Persona(std::string n) : nombre(n) {}
};

int main() {
    Persona* persona1 = new Persona("Juan");  // Asignacion dinamica de memoria
    std::cout << "Nombre: " << persona1->nombre << std::endl;
    
    delete persona1;  // Liberacion manual de memoria
    persona1 = nullptr;  // Asignar nullptr tras liberar memoria
    
    return 0;
}
```

### 4. Paradigma (Programacion Orientada a Objetos - POO)
C++ soporta la programacion orientada a objetos (POO), un paradigma que organiza el software en "objetos" que combinan datos y las funciones que operan sobre esos datos. Esto facilita la modularidad, reutilizacion de codigo y mantenimiento del software.

**Ejemplo:**

```cpp
#include <iostream>

class Animal {
public:
    std::string nombre;
    Animal(std::string n) : nombre(n) {}
    
    void hablar() {
        std::cout << nombre << " hace un sonido" << std::endl;
    }
};

class Perro : public Animal {
public:
    Perro(std::string n) : Animal(n) {}
    
    void hablar() override {
        std::cout << nombre << " dice guau!" << std::endl;
    }
};

int main() {
    Perro perro1("Fido");
    perro1.hablar();  // Llamada al metodo de la clase Perro
    
    return 0;
}
```

### 5. Portabilidad
El codigo en C++ es altamente portable, lo que significa que puede ser compilado y ejecutado en una amplia variedad de plataformas, desde PC hasta sistemas embebidos, con pocos o ningun cambio en el codigo fuente.

### 6. Tipado Estatico
C++ es un lenguaje con tipado estatico, lo que significa que los tipos de las variables deben ser definidos en tiempo de compilacion y no pueden cambiar durante la ejecucion. Esto aumenta la seguridad y la eficiencia del codigo.

### 7. Compilado
C++ es un lenguaje compilado, lo que significa que el codigo fuente se traduce a codigo de maquina antes de ser ejecutado. Este proceso se realiza utilizando compiladores como `g++`, lo que permite que los programas en C++ se ejecuten de manera rapida y eficiente.

**Ejemplo:**

Para compilar un archivo `test.cpp` usando el compilador `g++`, puedes usar el siguiente comando en la terminal:

```bash
g++ test.cpp -o test
```

### 8. Bibliotecas Estandar
C++ incluye una extensa biblioteca estandar que proporciona funcionalidades para realizar operaciones comunes, como la gestion de entradas y salidas, manipulación de cadenas, operaciones matematicas, y manejo de memoria. Algunas de las bibliotecas principales incluyen:
- `<iostream>`: Para operaciones de entrada y salida.
- `<string>`: Para manipular cadenas de caracteres.
- `<vector>`: Para utilizar estructuras de datos dinamicas como los vectores.
- `<cmath>`: Para funciones matematicas avanzadas.
- `<algorithm>`: Para algoritmos de ordenacion y busqueda.

### 9. Como Son las Clases en C++
Las clases en C++ son plantillas para crear objetos. Una clase define los atributos (datos) y metodos (funciones) que los objetos de esa clase tendran. La clase es la base de la programacion orientada a objetos en C++. Los atributos y metodos pueden tener diferentes niveles de acceso, como `public`, `protected` y `private`. C++ tambien soporta conceptos como la herencia, el polimorfismo y la sobrecarga de metodos.

**Accesibilidad:**
- `public`: Los miembros son accesibles desde cualquier parte del programa.
- `protected`: Los miembros son accesibles desde la propia clase y las clases derivadas.
- `private`: Los miembros son accesibles solo dentro de la propia clase.

**Tipos de Datos en Clases:**
Las clases pueden contener atributos de cualquier tipo de datos, como enteros, flotantes, cadenas, punteros, objetos de otras clases, entre otros.

**Metodos:**
Los metodos son funciones dentro de una clase que operan sobre los atributos de esa clase. Pueden ser:
- Métodos públicos: Son accesibles desde fuera de la clase.
- Métodos privados: Son solo accesibles desde dentro de la clase.
- Métodos protegidos: Son accesibles dentro de la clase y en las clases derivadas.

**Herencia:**
La herencia permite que una clase derive de otra, heredando sus atributos y métodos. Esto facilita la reutilización de código y permite crear jerarquías de clases.

**Polimorfismo:**
El polimorfismo permite que una misma operación se ejecute de manera diferente dependiendo del objeto que la invoque. Esto puede lograrse mediante la sobrecarga de métodos o el uso de métodos virtuales.

**Ejemplo:**

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    string nombre;

    Animal(string n) : nombre(n) {}

    virtual void hacerSonido() {
        cout << nombre << " hace un sonido general." << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string n) : Animal(n) {}

    void hacerSonido() override {
        cout << nombre << " dice: Guau!" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(string n) : Animal(n) {}

    void hacerSonido() override {
        cout << nombre << " dice: Miau!" << endl;
    }
};

int main() {
    Animal* animal1 = new Perro("Fido");
    Animal* animal2 = new Gato("Mittens");

    animal1->hacerSonido(); // Guau!
    animal2->hacerSonido(); // Miau!

    delete animal1;
    delete animal2;
    return 0;
}
```

### 10. Palabras Claves
Algunas de las palabras clave utilizadas en C++ incluyen:
- `int`, `char`, `float`, `double`, `void`: Tipos de datos.
- `class`, `public`, `private`, `protected`: Definicion de clases y especificadores de acceso.
- `if`, `else`, `for`, `while`, `switch`: Control de flujo.
- `new`, `delete`: Manejo de memoria dinamica.
- `virtual`, `override`: Polimorfismo y herencia.

### 11. Operadores
C++ incluye una gran variedad de operadores, como:
- **Aritmeticos**: `+`, `-`, `*`, `/`, `%`.
- **Comparacion**: `==`, `!=`, `>`, `<`, `>=`, `<=`.
- **Logicos**: `&&`, `||`, `!`.
- **Asignacion**: `=`, `+=`, `-=`, `*=`, `/=`.
- **Punteros**: `*`, `&`.

### 12. Especificadores de Formato
C++ utiliza especificadores de formato para la entrada y salida de datos. Algunos de los especificadores mas comunes son:
- `%d`: Para enteros.
- `%f`: Para flotantes.
- `%s`: Para cadenas.
- `%p`: Para punteros.

## Palabras claves comunes en C++ 

### `cout` y `<<`
En C++, `cout` es un objeto de la biblioteca estándar de entrada/salida (`iostream`) que se utiliza para imprimir datos en la consola. Se encuentra en el espacio de nombres `std`. Para imprimir datos, se usa el operador `<<`, que se conoce como "operador de inserción". Este operador toma el dato que le sigue y lo envía a `cout` para que sea mostrado en la pantalla.

**Ejemplo:**
- `cout << "Hola Mundo!";` imprime el texto "Hola Mundo!" en la consola.

El operador `<<` se puede usar múltiples veces en una sola línea para imprimir múltiples valores.

**Ejemplo:**
- `cout << "El valor de x es: " << x;` imprimirá el valor de `x` junto con el texto.

### `endl`
`endl` es un manipulador de salida en C++ que se usa para insertar un salto de línea (como presionar "Enter") en la salida estándar. Además de hacer un salto de línea, también asegura que el búfer de salida se vacíe (flush), lo que puede ser importante en programas más complejos que requieren una sincronización precisa de la salida.

**Ejemplo:**
- `cout << "Hola" << endl;` imprimirá "Hola" y luego saltará a la siguiente línea.

### `::` (Operador de Resolución de Ámbito)
El operador `::`, conocido como "operador de resolución de ámbito", se utiliza en C++ para especificar el ámbito de una variable, función o clase. Es particularmente útil cuando hay nombres que se repiten en diferentes ámbitos o clases, y se necesita especificar a cuál se hace referencia.

**Ejemplo de uso:**
1. **Acceso a miembros de un espacio de nombres**:
   - En C++, la biblioteca estándar se encuentra dentro del espacio de nombres `std`, por lo que se utiliza `::` para acceder a sus miembros. 
   - `std::cout` indica que `cout` pertenece al espacio de nombres `std`.

2. **Acceso a miembros estáticos de una clase**:
   - `MiClase::miVariable` permite acceder a una variable estática de una clase sin necesidad de crear una instancia de la clase.

3. **Acceso a funciones de una clase o espacio de nombres**:
   - Para llamar a una función miembro de una clase o a una función en un espacio de nombres específico, se utiliza el operador `::`.

**Ejemplo:**
- `std::cout << "Hola, mundo!";` indica que `cout` es parte del espacio de nombres `std`.

### `new` y `delete`
En C++, `new` y `delete` son operadores para la gestión dinámica de memoria. A diferencia de C, donde se utilizan funciones como `malloc()` y `free()`, C++ introduce estos operadores para gestionar memoria en un formato más intuitivo y compatible con la orientación a objetos.

- **`new`** se usa para asignar memoria dinámica, es decir, para crear objetos o variables en tiempo de ejecución. Devuelve un puntero al bloque de memoria recién asignado.
- **`delete`** se usa para liberar memoria previamente asignada con `new`.

**Ejemplo:**
- `int* ptr = new int(10);` asigna memoria para un entero y lo inicializa a 10.
- `delete ptr;` libera la memoria ocupada por el puntero `ptr`.

### `namespace`
Los espacios de nombres (`namespace`) en C++ son utilizados para organizar el código y evitar conflictos de nombres. Permiten agrupar funciones, clases y objetos bajo un mismo nombre para diferenciar sus contextos de uso.

- **`namespace std`** es el espacio de nombres estándar que agrupa las clases y funciones comunes como `cout`, `cin`, `vector`, entre otros.
- Se puede definir un espacio de nombres propio para organizar el código en proyectos grandes.

**Ejemplo:**
- `namespace miEspacio { int var; }` define un espacio de nombres con una variable `var`.
- Para acceder a ella, se usaría `miEspacio::var`.

### `auto` (Tipo Inferido)
El tipo de una variable puede ser deducido automáticamente por el compilador utilizando la palabra clave `auto`. Esto facilita la declaración de variables sin necesidad de especificar explícitamente el tipo, especialmente en tipos complejos o al trabajar con contenedores de la STL.

**Ejemplo:**
- `auto x = 10;` deduce automáticamente que `x` es de tipo `int`.
- `auto iter = v.begin();` deduce el tipo del iterador cuando se utiliza con contenedores de la STL.

### `nullptr`
En C++, `nullptr` es un literal que representa un puntero nulo, reemplazando a `NULL` de C. La principal ventaja es que es un tipo seguro, ya que `nullptr` es de tipo `std::nullptr_t` y no puede ser confundido con otros valores como enteros o punteros no válidos.

**Ejemplo:**
- `int* ptr = nullptr;` asigna un puntero nulo a `ptr`.

### `const`
El modificador `const` en C++ se usa para declarar que una variable no puede cambiar su valor después de ser inicializada. Es especialmente útil en funciones, para asegurar que ciertos parámetros no se modifiquen accidentalmente.

- Se puede usar con variables, punteros, y miembros de clases.

**Ejemplo:**
- `const int a = 10;` declara una constante `a` que no puede cambiar.
- `const int* ptr;` declara un puntero a una constante, lo que significa que el valor apuntado no puede ser modificado a través de ese puntero.

### `static`
El modificador `static` tiene varios usos en C++:
- **En variables dentro de funciones**: Las variables declaradas como `static` mantienen su valor entre llamadas a la función.
- **En funciones miembro de clases**: Las funciones estáticas pertenecen a la clase y no a instancias de la misma, lo que significa que se pueden llamar sin crear un objeto.

**Ejemplo:**
- `static int contador = 0;` mantiene la variable `contador` entre llamadas sucesivas a la función.
- `static void metodoEstatico();` define una función estática que puede ser llamada sin una instancia de la clase.

### `friend`
La palabra clave `friend` en C++ permite que una función o clase acceda a los miembros privados y protegidos de otra clase. Esto es útil cuando una función o clase necesita interactuar con los detalles internos de otra clase sin ser parte de ella.

**Ejemplo:**
- `friend class MiClase;` otorga acceso a todos los miembros privados y protegidos de la clase `MiClase` a la clase que declara este `friend`.

### `explicit`
El modificador `explicit` se utiliza en C++ para evitar que el compilador haga conversiones implícitas automáticas de tipos. Esto es útil en constructores que no deben ser llamados de forma implícita cuando se realiza una conversión de tipo.

**Ejemplo:**
- `explicit MiClase(int x);` asegura que el constructor solo se llame cuando se pasa un `int` explícitamente, evitando conversiones automáticas no deseadas.

### `virtual` y `override`
En C++, el modificador `virtual` se usa para declarar funciones que pueden ser sobrecargadas en clases derivadas. Esto es una parte fundamental del polimorfismo.

- **`virtual`** indica que la función puede ser sobrescrita.
- **`override`** se usa para garantizar que una función está sobrescribiendo correctamente una función virtual de la clase base.

**Ejemplo:**
- `virtual void hacerSonido();` en la clase base permite que las clases derivadas implementen su propia versión de la función.
- `void hacerSonido() override;` en la clase derivada asegura que la función sobrescribe correctamente a la función de la clase base.

### `typedef` y `using`
En C++, `typedef` se usa para crear un alias de tipo, lo que facilita el trabajo con tipos complejos o largos. La palabra clave `using` se ha introducido como una forma moderna de hacer lo mismo que `typedef`, pero con una sintaxis más clara.

**Ejemplo:**
- `typedef unsigned long long ULL;` crea un alias `ULL` para `unsigned long long`.
- `using ULL = unsigned long long;` es una alternativa moderna a `typedef`.

### `decltype`
El operador `decltype` permite obtener el tipo de una expresión en C++. Es útil cuando se trabaja con tipos complejos o cuando no se conoce el tipo de antemano.

**Ejemplo:**
- `decltype(x) y;` declara una variable `y` del mismo tipo que `x`.

### `typeid`
El operador `typeid` se utiliza para obtener el tipo de una expresión en tiempo de ejecución. Es especialmente útil cuando se trabaja con polimorfismo y punteros a clases base.

**Ejemplo:**
- `typeid(*obj).name();` devuelve el nombre del tipo de la instancia apuntada por `obj`.
