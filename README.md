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

En C++, la programación orientada a objetos (POO) es un paradigma fundamental que organiza el software en unidades llamadas "objetos". Estos objetos combinan atributos (datos) y métodos (funciones) que operan sobre esos datos. A continuación, se detallan los aspectos principales de las clases en C++.

#### Constructor y Destructor
- **Constructor**: Es un método especial que se ejecuta automáticamente cuando se crea un objeto de la clase. Su propósito es inicializar los atributos del objeto. Los constructores pueden ser sobrecargados, lo que permite crear objetos de distintas formas.
  
- **Destructor**: Es un método especial que se ejecuta automáticamente cuando un objeto es destruido o fuera de alcance. Su función principal es liberar los recursos que el objeto haya adquirido durante su vida útil, como la memoria dinámica.

#### Atributos de la Clase
Los atributos de una clase son las variables que representan el estado de un objeto. Cada instancia de la clase tendrá sus propios valores para estos atributos. Los atributos pueden ser públicos, privados o protegidos, lo que se define mediante los modificadores de acceso.

#### Modificadores de Acceso
C++ ofrece tres niveles de acceso a los miembros de una clase:
- **`public`**: Los miembros son accesibles desde cualquier parte del programa.
- **`private`**: Los miembros son accesibles solo dentro de la propia clase. Es el nivel de acceso por defecto.
- **`protected`**: Los miembros son accesibles dentro de la clase y en las clases derivadas.

#### Métodos de la Clase
Los métodos de una clase son funciones que operan sobre los atributos de la clase y que definen el comportamiento de los objetos. Los métodos pueden ser:
- **Métodos estáticos**: Pertenecen a la clase en sí, y no a las instancias individuales. Se accede a ellos sin necesidad de crear un objeto.
- **Métodos de instancia**: Pertenecen a objetos específicos y operan sobre los atributos del objeto.

#### Métodos de Instancia
Son funciones miembro que solo pueden ser invocadas en instancias específicas de la clase. Un método de instancia generalmente manipula los atributos no estáticos del objeto.

#### Herencia Múltiple
C++ permite la **herencia múltiple**, lo que significa que una clase puede heredar de más de una clase base. Esto se logra porque C++ soporta la herencia de varias clases simultáneamente, lo que le da flexibilidad para construir jerarquías más complejas y reutilizar código de diferentes fuentes. La herencia múltiple puede ser útil cuando una clase necesita combinar comportamientos de varias clases base, pero requiere un manejo adecuado para evitar problemas como la ambigüedad en la herencia (por ejemplo, métodos con el mismo nombre en clases base distintas).

El uso de herencia múltiple permite que las clases hereden propiedades y comportamientos de varias clases base, lo que fomenta la reutilización del código y la modularidad. Sin embargo, puede requerir un diseño cuidadoso para manejar conflictos y garantizar que las clases derivadas mantengan coherencia en su estructura.

**Ejemplo:**

```cpp
#include <iostream>
#include <string>

using namespace std;

// Clase base 1
class Persona {
public:
    string nombre;

    Persona(string _nombre) : nombre(_nombre) {}

    void mostrarNombre() {
        cout << "Nombre: " << nombre << endl;
    }
};

// Clase base 2
class Trabajador {
public:
    string profesion;

    Trabajador(string _profesion) : profesion(_profesion) {}

    void mostrarProfesion() {
        cout << "Profesion: " << profesion << endl;
    }
};

// Clase derivada que hereda de Persona y Trabajador
class Ingeniero : public Persona, public Trabajador {
public:
    Ingeniero(string _nombre, string _profesion) 
        : Persona(_nombre), Trabajador(_profesion) {}

    void mostrarInformacion() {
        mostrarNombre();
        mostrarProfesion();
    }
};

int main() {
    Ingeniero ingeniero("Juan Perez", "Ingeniero Civil");
    ingeniero.mostrarInformacion();

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

## 9. Palabras claves comunes en C++ 

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

### 10. Operadores
C++ incluye una gran variedad de operadores, como:
- **Aritmeticos**: `+`, `-`, `*`, `/`, `%`.
- **Comparacion**: `==`, `!=`, `>`, `<`, `>=`, `<=`.
- **Logicos**: `&&`, `||`, `!`.
- **Asignacion**: `=`, `+=`, `-=`, `*=`, `/=`.
- **Punteros**: `*`, `&`.

### 11. Especificadores de Formato
C++ utiliza especificadores de formato para la entrada y salida de datos. Algunos de los especificadores mas comunes son:
- `%d`: Para enteros.
- `%f`: Para flotantes.
- `%s`: Para cadenas.
- `%p`: Para punteros.
