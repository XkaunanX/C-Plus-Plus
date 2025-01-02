# POO de C++

## 1. Clases y Objetos

### 1.1. Clases
Una clase en C++ es una plantilla o un tipo de datos definido por el usuario. Define las propiedades y comportamientos que los objetos de esa clase tendrán. Una clase encapsula tanto los atributos (datos) como los métodos (funciones) que operan sobre esos datos.

- **Atributos**: Son variables que representan el estado de un objeto. Los atributos se definen dentro de la clase y pueden tener distintos modificadores de acceso, como `private`, `protected` y `public`.
- **Métodos**: Son funciones que definen las acciones o comportamientos que los objetos de la clase pueden realizar. Los métodos pueden operar sobre los atributos de la clase o realizar otras tareas.

### 1.2. Objetos
Un objeto es una instancia de una clase. Cuando se crea un objeto, se asigna memoria para los atributos definidos por la clase y se pueden utilizar los métodos para interactuar con los datos del objeto. Un objeto existe durante su ciclo de vida, que va desde su creación hasta su destrucción.

## 2. Encapsulamiento

El **encapsulamiento** es una característica clave de la POO en C++. Consiste en ocultar los detalles internos de la implementación de una clase, permitiendo solo el acceso a través de una interfaz pública. Esto garantiza que los objetos de una clase solo interactúen con otros objetos mediante métodos específicos, lo que aumenta la seguridad y la modularidad del código.

### 2.1. Modificadores de Acceso
Los modificadores de acceso controlan la visibilidad de los atributos y métodos de una clase:
- **`private`**: Los atributos y métodos son inaccesibles desde fuera de la clase.
- **`protected`**: Los atributos y métodos son inaccesibles desde fuera de la clase, pero pueden ser accedidos por clases derivadas.
- **`public`**: Los atributos y métodos son accesibles desde cualquier parte del código.

### 2.2. Getters y Setters
Para controlar el acceso a los atributos privados, se utilizan **getters** y **setters**. Los **getters** permiten obtener el valor de un atributo, y los **setters** permiten modificar el valor de un atributo. Esta técnica es parte de la práctica del encapsulamiento.

## 3. Herencia

La **herencia** es un mecanismo mediante el cual una clase puede heredar propiedades y comportamientos de otra. Esto facilita la reutilización de código y la creación de jerarquías de clases.

### 3.1. Herencia Simple
En la herencia simple, una clase derivada hereda de una única clase base. La clase derivada puede agregar nuevos métodos o atributos, o bien modificar los existentes de la clase base.

### 3.2. Herencia Múltiple
C++ también soporta **herencia múltiple**, donde una clase derivada puede heredar de más de una clase base. Aunque esta característica ofrece mayor flexibilidad, también puede generar complejidad, como la ambigüedad en la resolución de nombres de métodos y atributos heredados.

### 3.3. Sobrescritura de Métodos
Las clases derivadas pueden **sobrescribir** los métodos de la clase base. Esto significa que se puede proporcionar una implementación diferente de un método en la clase derivada, manteniendo el mismo nombre y la misma firma del método.

## 4. Polimorfismo

El **polimorfismo** permite que un objeto pueda ser tratado como una instancia de su clase base, pero ejecutando el comportamiento definido en la clase derivada. Esto se logra a través de la vinculación dinámica y el uso de punteros o referencias a clases base.

### 4.1. Polimorfismo en Tiempo de Ejecución
El **polimorfismo en tiempo de ejecución** se consigue utilizando funciones virtuales. Una función virtual es una función de la clase base que puede ser sobrescrita por la clase derivada. Cuando se llama a una función virtual a través de un puntero o referencia a la clase base, C++ ejecutará la versión más específica de la función (es decir, la de la clase derivada).

### 4.2. Funciones Virtuales y Punteros
El polimorfismo en C++ es posible principalmente a través de punteros o referencias a clases base. Al utilizar punteros o referencias, el tipo de objeto se resuelve en tiempo de ejecución, permitiendo que la versión correcta de un método sea ejecutada.

### 4.3. Funciones Virtuales Puras
Una función virtual pura es una función que no tiene implementación en la clase base, y obliga a las clases derivadas a proporcionar su propia implementación. Este concepto es utilizado para crear **clases abstractas**, que no pueden ser instanciadas directamente.

## 5. Abstracción

La **abstracción** en C++ permite a los programadores enfocarse en las características esenciales de un objeto sin preocuparse por los detalles internos de su implementación. Esto se logra mediante el uso de clases abstractas y métodos virtuales.

### 5.1. Clases Abstractas
Una clase abstracta es una clase que contiene al menos una función virtual pura. Las clases abstractas no pueden ser instanciadas directamente, sino que deben ser heredadas por otras clases que proporcionen implementaciones específicas para las funciones virtuales puras.

### 5.2. Interfaz
Una interfaz en C++ es similar a una clase abstracta, pero todos sus métodos son funciones virtuales puras. Una interfaz no proporciona ninguna implementación, solo define las firmas de los métodos que deben ser implementados por las clases que la implementen.

## 6. Composición

La **composición** es una forma de asociar objetos dentro de otros objetos, en lugar de usar la herencia. La composición permite que los objetos compuestos deleguen tareas a los objetos que contienen, siguiendo el principio de "composición sobre herencia". Esto facilita una mayor modularidad y flexibilidad en el diseño.

### 6.1. Clases Simples
Una **clase simple** es aquella que está compuesta solo por atributos y métodos que interactúan con esos atributos. No contiene ningún otro objeto dentro de sí misma y es una estructura sencilla para representar conceptos o entidades en el código. Las clases simples son ideales para representar objetos con una sola responsabilidad.

### 6.2. Clases Compuestas
Una **clase compuesta** es aquella que tiene instancias de otras clases dentro de sí misma como parte de su estructura. Estas clases permiten que los objetos deleguen tareas a otros objetos más especializados, promoviendo una mayor modularidad y reutilización del código. La composición se usa cuando se necesitan representar relaciones "tiene un" entre los objetos, como un automóvil que "tiene un" motor o una biblioteca que "tiene un" conjunto de libros.

## 7. Destrucción de Objetos

Cuando un objeto ya no es necesario, se destruye automáticamente (en el caso de objetos estáticos) o manualmente (en el caso de objetos dinámicos). La destrucción de objetos es gestionada por el **destructor**, una función especial de la clase que se invoca cuando un objeto sale de su alcance o es destruido explícitamente.

### 7.1. Destructor
El destructor se utiliza para liberar recursos adquiridos por un objeto, como memoria dinámica o recursos de archivos. En C++, el destructor se invoca automáticamente cuando el objeto es destruido, y no debe devolver ningún valor ni aceptar parámetros.

# Ciclo de Vida de un Objeto en C++

En C++, el ciclo de vida de un objeto es un proceso que abarca desde su creación hasta su destrucción. Los objetos en C++ son instancias de clases y están gestionados por la memoria en el contexto del sistema de ejecución. A continuación se explica cómo un objeto es creado, utilizado y destruido, detallando la parte de clases y objetos en C++.

## 1. Creación de un Objeto

Un objeto en C++ es una instancia de una clase. La creación de un objeto puede ocurrir de dos maneras principales: estática o dinámica.

### 1.1. Creación Estática
Cuando un objeto es creado en el ámbito de una función o en la declaración de una variable dentro de un bloque de código, se habla de creación estática. En este caso, la memoria para el objeto es asignada en la pila del sistema. El objeto se destruye automáticamente cuando sale del ámbito donde fue creado, es decir, cuando la función o bloque de código termina.

### 1.2. Creación Dinámica
La creación dinámica de un objeto ocurre cuando se utiliza el operador `new`. Este tipo de objetos no están gestionados por la pila, sino por el montón (heap). La memoria para estos objetos no se libera automáticamente, por lo que es responsabilidad del programador liberarla mediante el operador `delete` cuando el objeto ya no sea necesario.

## 2. Constructores

Los constructores son métodos especiales de una clase que son llamados automáticamente cuando se crea un objeto de esa clase. Su principal responsabilidad es inicializar los atributos del objeto, asegurando que el objeto esté en un estado válido antes de ser utilizado.

### 2.1. Constructor por Defecto
El constructor por defecto es un constructor que no recibe parámetros. Si no se define explícitamente, el compilador generará uno automáticamente. Este constructor es invocado cuando un objeto es creado sin proporcionar argumentos.

### 2.2. Constructor Parametrizado
Un constructor parametrizado permite inicializar un objeto con valores específicos proporcionados en el momento de su creación. Esto permite una mayor flexibilidad al crear instancias de objetos.

### 2.3. Constructor de Copia
El constructor de copia se invoca cuando un objeto es creado a partir de otro objeto de la misma clase. Su tarea es crear una copia exacta del objeto original, realizando una copia profunda de sus atributos.

## 3. Métodos de una Clase

Una vez que un objeto ha sido creado, es posible interactuar con él mediante métodos. Los métodos son funciones que se definen dentro de una clase y operan sobre los atributos del objeto.

### 3.1. Métodos de Instancia
Son aquellos métodos que operan sobre los datos de una instancia específica de la clase. Estos métodos tienen acceso a los atributos y pueden modificar el estado del objeto.

### 3.2. Métodos Estáticos
Los métodos estáticos no están asociados a ninguna instancia particular de la clase. En lugar de operar sobre los atributos de un objeto, estos métodos pueden operar solo sobre datos estáticos o realizar operaciones que no dependen de ninguna instancia en particular.

## 4. Destrucción de un Objeto

El ciclo de vida de un objeto concluye cuando el objeto es destruido. Este proceso puede ser automático o manual, dependiendo de cómo fue creado el objeto.

### 4.1. Destructor
El destructor es un método especial que se invoca cuando un objeto es destruido. Su propósito es liberar los recursos que el objeto pueda haber adquirido durante su vida útil, como memoria dinámica o handles de archivos. El destructor se invoca automáticamente cuando el objeto sale del ámbito de su creación o cuando es destruido explícitamente mediante `delete`.

### 4.2. Destrucción Estática
Los objetos creados estáticamente se destruyen automáticamente cuando el bloque de código o la función donde fueron creados termina su ejecución. El compilador gestiona la destrucción de estos objetos sin la intervención del programador.

### 4.3. Destrucción Dinámica
En el caso de objetos creados dinámicamente, el programador debe asegurarse de liberar la memoria manualmente mediante el uso de `delete` cuando el objeto ya no sea necesario. La memoria ocupada por estos objetos no se libera automáticamente, lo que puede llevar a problemas como fugas de memoria si no se gestionan adecuadamente.

## 5. El Papel de la Herencia

La herencia es un concepto fundamental en la programación orientada a objetos y permite que una clase derive de otra, heredando sus atributos y métodos. En C++, se pueden crear jerarquías de clases donde una clase base es extendida por una o más clases derivadas.

### 5.1. Herencia Simple
La herencia simple se refiere al caso en el que una clase derivada hereda de una única clase base. Esto permite que la clase derivada reutilice el comportamiento de la clase base y agregue o modifique funcionalidades según sea necesario.

### 5.2. Herencia Múltiple
C++ también soporta la herencia múltiple, lo que significa que una clase derivada puede heredar de más de una clase base. Aunque esto proporciona mayor flexibilidad, también introduce complejidad, ya que la clase derivada hereda atributos y métodos de múltiples clases base.

## 6. El Ciclo Completo de Vida de un Objeto

El ciclo completo de vida de un objeto en C++ es un proceso que involucra varias etapas:

1. **Creación**: Un objeto es creado a través de un constructor. La memoria es asignada ya sea en la pila o en el montón, dependiendo de si el objeto es creado estática o dinámicamente.
2. **Inicialización**: El constructor se encarga de inicializar los atributos del objeto, dejándolo en un estado válido.
3. **Uso**: El objeto puede ser manipulado mediante sus métodos, interactuando con otros objetos y realizando las tareas para las que fue diseñado.
4. **Destrucción**: El objeto es destruido mediante un destructor. Si fue creado dinámicamente, la memoria debe ser liberada manualmente para evitar fugas de memoria.

## Resumen

El ciclo de vida de un objeto en C++ es un proceso gestionado por los constructores, métodos y destructores. Los objetos son creados mediante constructores, manipulados a través de métodos y finalmente destruidos cuando ya no son necesarios.

- **Creación**: Los objetos pueden ser creados estáticamente o dinámicamente.
- **Constructores**: Inicializan los objetos con valores específicos.
- **Métodos**: Permiten operar sobre los atributos de los objetos.
- **Destrucción**: La destrucción automática o manual de objetos implica liberar recursos.
- **Herencia**: Facilita la reutilización de código y la creación de jerarquías de clases.
