Sistema de Gestion de un Refugio de Animales
Trabajo Practico Integrador - Programacion Orientada a Objetos 2026 (UCC)

## Integrantes
Maccagno, Iris
Ladú, Luz
Molina, Guadalupe

## Descripcion
Programa de consola que gestiona un refugio de animales. Permite registrar perros y gatos, registrar adoptantes, crear, confirmar y cancelar solicitudes de adopcion, devolver animales y consultar el historial.
Cada animal tiene ID, nombre, edad, estado de salud y estado de adopcion. El perro agrega raza y tamanio. El gato agrega color de pelaje y si es de interior o exterior.

## Por que el problema se adapta al paradigma orientado a objetos
El refugio esta formado por entidades del mundo real (animales, adoptantes y solicitudes) que tienen datos y comportamiento propios. El paradigma orientado a objetos permite modelar cada una como una clase:
- Abstraccion y encapsulamiento: cada entidad es una clase con atributos privados y una interfaz publica. Por ejemplo, la disponibilidad de un animal solo se cambia con setDisponible().
- Herencia y polimorfismo: perros y gatos comparten datos y operaciones (clase base Animal) pero se muestran distinto. El refugio guarda un unico catalogo de punteros a Animal y llama a mostrarInfo() sin saber de que tipo es cada uno.
- Composicion: Refugio contiene adoptantes y solicitudes, y cada SolicitudAdopcion contiene un Adoptante y un animal. Esto reproduce como se relacionan estas entidades en la realidad.
- Extensibilidad: agregar otra especie (por ejemplo Conejo) solo requiere una nueva clase derivada, sin modificar el resto del sistema.

## Estructura del proyecto
- main.cpp: bucle del menu y captura de todas las excepciones.
- menu.h y menu.cpp: funciones de cada opcion del menu y lectura de datos.
- Animal.h y Animal.cpp: clase base abstracta (clone() virtual puro y destructor virtual), con los operadores == y !.
- Perro.h, Perro.cpp, Gato.h y Gato.cpp: clases derivadas con herencia publica y metodos override.
- Adoptante.h y Adoptante.cpp: datos del adoptante.
- SolicitudAdopcion.h y SolicitudAdopcion.cpp: relaciona un adoptante con un animal y guarda su estado.
- refugio.h y refugio.cpp: catalogo de animales con memoria dinamica, adoptantes, solicitudes e historial. Define los operadores [] y ().
- Collection.h: clase generica Collection<T> con un miembro estatico.
- Utilidades.h: funcion generica leerDato<T>.
- Excepciones.h: excepciones personalizadas.
- pseudocodigo.psc: pseudocodigo del menu principal.

## Ubicacion de fases 
- Fase 1: este README, el pseudocodigo, los diagramas de flujo (en el documento del trabajo) y el esqueleto de archivos .h y .cpp.
- Fase 2: Refugio administra un arreglo dinamico Animal** y lo recorre con aritmetica de punteros en Refugio::mostrarAnimales().
- Fase 3: constructor de copia, operador de asignacion y destructor en Refugio y en SolicitudAdopcion. Operadores == y ! en Animal, y operadores [] y () en Refugio.
- Fase 4: Animal es abstracta, Perro y Gato heredan de ella, y el catalogo es un unico arreglo de Animal*. Refugio y SolicitudAdopcion usan composicion.
- Fase 5: Collection<T> se instancia con string y con Adoptante (en Refugio) y tiene el miembro estatico cantidadColecciones. La funcion generica leerDato<T> se usa con int y con char. Las excepciones estan en Excepciones.h y se capturan en main.cpp.

## Decisiones de diseno
- clone() funciona como constructor virtual. Para copiar un animal a traves de un puntero a Animal, cada clase derivada implementa clone(), que devuelve una copia del tipo real (Perro o Gato). Se usa al registrar animales y en la copia profunda. Al ser virtual puro, tambien es lo que hace abstracta a Animal.
- Un unico catalogo polimorfico. Refugio guarda un arreglo dinamico de Animal* que duplica su capacidad cuando se llena.
- Adoptantes e historial usan Collection<T>. Las solicitudes usan std::vector. Los dos manejan su propia memoria.
- Estados de una solicitud: Pendiente, Confirmada, Cancelada y Devuelta.
- Al crear una solicitud, el animal pasa a no disponible (queda reservado). Si se cancela, vuelve a estar disponible. Si se confirma, queda no disponible hasta que se lo devuelve.
- La solicitud guarda una copia del animal (unique_ptr y clone()) tal como estaba al momento de crearla. El estado actual siempre esta en el catalogo del refugio.
- Las excepciones propias heredan de std::exception. leerDato<T> lanza EntradaInvalidaException si se ingresa, por ejemplo, una letra donde va un numero, y asi se evita un bucle infinito con cin.
- Animal::instanciasVivas es un miembro estatico que cuenta los animales existentes, y se usa para comprobar que no hay fugas de memoria.

## Compilacion y uso
Requiere un compilador de C++11 o superior (por ejemplo g++).
Para compilar:
    g++ main.cpp menu.cpp refugio.cpp Animal.cpp Adoptante.cpp Gato.cpp Perro.cpp SolicitudAdopcion.cpp -o refugioanimales

Para ejecutar en Windows:
    .\refugioanimales.exe
Para ejecutar en Linux o macOS:
    ./refugioanimales

## Menu
1. Registrar perro o gato
2. Listar animales (todos, solo disponibles o por posicion)
3. Registrar adoptante
4. Buscar animal por ID
5. Gestionar solicitud de adopcion (crear, confirmar o cancelar)
6. Devolver animal a disponible
7. Mostrar historial
8. Mostrar solicitudes
9. Listar adoptantes
0. Salir

Si se ingresa un dato invalido, el programa muestra el error y vuelve al menu.

## Pruebas, pseudocodigo y diagramas
Las pruebas de situaciones validas y de error, la copia profunda, la liberacion de memoria, el pseudocodigo y los diagramas de flujo estan en el documento del trabajo.