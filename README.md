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

## Sintaxis particular de C++ 

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
