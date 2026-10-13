# Sistema de Gestion de un Refugio de Animales
Trabajo Practico Integrador - Programacion Orientada a Objetos 2026

## Integrantes
- Maccagno, Iris
- Ladú, Luz
- Molina, Guadalupe

## Descripcion
Programa que gestiona un refugio de animales. Permite registrar perros y gatos, registrar adoptantes, crear, confirmar y cancelar solicitudes de adopcion, devolver animales y consultar el historial.
Cada animal tiene ID, nombre, edad, estado de salud y estado de adopcion. El perro agrega raza y tamanio. El gato agrega color de pelaje y si es de interior o exterior.

## Por que el problema se adapta al paradigma orientado a objetos
El refugio esta formado por entidades realess (animales, adoptantes y solicitudes) que tienen datos y comportamiento propios. El paradigma orientado a objetos permite modelar cada una como una clase:
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
- Fase 1: este README, el pseudocodigo, los diagramas de flujo y el esqueleto de archivos .h y .cpp.
- Fase 2: Refugio administra un arreglo dinamico Animal** y lo recorre con aritmetica de punteros en Refugio::mostrarAnimales().
- Fase 3: constructor de copia, operador de asignacion y destructor en Refugio y en SolicitudAdopcion. Operadores == y ! en Animal, y operadores [] y () en Refugio.
- Fase 4: Animal es abstracta, Perro y Gato heredan de ella, y el catalogo es un unico arreglo de Animal*. Refugio y SolicitudAdopcion usan composicion.
- Fase 5: Collection<T> se instancia con string y con Adoptante (en Refugio) y tiene el miembro estatico cantidadColecciones. La funcion generica leerDato<T> se usa con int y con char. Las excepciones estan en Excepciones.h y se capturan en main.cpp.

## Decisiones de diseno
- clone() funciona como constructor virtual. Para copiar un animal a traves de un puntero a Animal, cada clase derivada implementa clone(), que devuelve una copia del tipo real (Perro o Gato). Se usa al registrar animales y en la copia profunda. Al ser virtual puro, tambien es lo que hace abstracta a Animal.
- Un unico catalogo. Refugio guarda un arreglo dinamico de Animal* que duplica su capacidad cuando se llena.
- Adoptantes e historial usan Collection<T>. Las solicitudes usan std::vector. Los dos manejan su propia memoria.
- Estados de una solicitud: Pendiente, Confirmada, Cancelada y Devuelta.
- Al crear una solicitud, el animal pasa a no disponible (queda reservado). Si se cancela, vuelve a estar disponible. Si se confirma, queda no disponible hasta que se lo devuelve.
- La solicitud guarda una copia del animal (unique_ptr y clone()) tal como estaba al momento de crearla. El estado actual siempre esta en el catalogo del refugio.
- Las excepciones propias heredan de std::exception. leerDato<T> lanza EntradaInvalidaException si se ingresa, por ejemplo, una letra donde va un numero, y asi se evita un bucle infinito con cin.
- Animal::instanciasVivas es un miembro estatico que cuenta los animales existentes, y se usa para comprobar que no hay fugas de memoria.

## Gestion de memoria: quien crea y quien libera cada bloque
- Arreglo de punteros Animal** animales: lo crean los constructores de Refugio con new Animal*[capacidad]. Cuando se llena, Refugio::agregarAnimal() crea un arreglo nuevo del doble de tamanio, copia los punteros y libera el viejo con delete[]. El constructor de copia de Refugio crea su propio arreglo. Lo libera ~Refugio() con delete[].
- Cada animal del catalogo (Perro o Gato): lo crea clone() con new, llamado desde Refugio::agregarAnimal() y desde el constructor de copia de Refugio (copia profunda). El refugio es el responsable de esos animales: ~Refugio() los libera uno por uno con delete antes de liberar el arreglo. Como el destructor de Animal es virtual, se ejecuta el destructor correcto de Perro o Gato.
- Operador de asignacion de Refugio: crea una copia temporal (que hace sus propios clone()) e intercambia los datos con ella. Al terminar la funcion se destruye la copia temporal, y con ella se liberan los animales y el arreglo viejos.
- Animal de cada SolicitudAdopcion: lo crea clone() en el constructor de SolicitudAdopcion y en su constructor de copia. Se guarda en un unique_ptr, que lo libera automaticamente cuando se destruye la solicitud, por lo que no hace falta un delete manual.
- Animales temporales del menu: en registrarAnimal() el Perro o el Gato se crea como variable local (sin new). El refugio guarda una copia hecha con clone(), y la variable local se destruye sola al salir de la funcion.
- Collection<T> (adoptantes e historial) y std::vector (solicitudes): guardan los elementos por valor y manejan su memoria internamente, asi que se liberan solas cuando se destruye el Refugio.

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

## Miembro estatico de Collection<T>
Collection<T> tiene el miembro estatico cantidadColecciones, que cuenta las colecciones creadas (las copias tambien cuentan). Como Collection es una plantilla, el compilador genera una clase distinta por cada tipo T: Collection<int>, Collection<string> y Collection<Adoptante> son clases diferentes, y cada una tiene su propio contador, independiente de los demas. Al crear o copiar una coleccion de un tipo, aumenta solo el contador de ese tipo. Se consulta con obtenerCantidadColecciones().
En el sistema, Refugio usa una Collection<Adoptante> y una Collection<string> (el historial). Por eso cada Refugio que se crea o se copia suma uno a esos dos contadores y no al de int.

## Casos de prueba
Situaciones validas:
- Registrar un perro y un gato.
- Registrar un adoptante.
- Listar todos los animales y filtrar los disponibles.
- Buscar un animal por ID y ver un animal por posicion.
- Crear una solicitud (el animal queda reservado), confirmarla y verla en las solicitudes y en el historial.
- Cancelar una solicitud (el animal vuelve a estar disponible).
- Devolver un animal adoptado.

Situaciones de error:
- ID repetido de animal o de adoptante.
- Tipo de animal invalido, edad negativa o respuesta distinta de s o n.
- Crear una solicitud sobre un animal no disponible, o con un animal o un adoptante inexistente.
- Confirmar o cancelar una solicitud inexistente o que ya no esta pendiente.
- Devolver un animal inexistente o sin adopcion confirmada.
- Posicion invalida al ver un animal por posicion.
- Letras donde se espera un numero.

Copia profunda y liberacion de memoria:
- Copiar un Refugio con el constructor de copia y con el operador de asignacion: la copia es independiente del original.
- Autoasignacion de un Refugio.
- Al destruir los refugios no queda ningun animal sin liberar (el contador instanciasVivas vuelve al valor inicial).

El detalle de cada prueba, con los pasos y los resultados, esta en el documento de pruebas.
