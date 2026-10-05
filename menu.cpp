#include <iostream>
#include <string>
#include <stdexcept>
#include "menu.h"
#include "refugio.h"
#include "Perro.h"
#include "Gato.h"
#include "Collection.h"
#include "Utilidades.h"
#include "Excepciones.h"

using namespace std;

// Funcion generica (template): sirve para una Collection de cualquier tipo.
// Se usa con Collection<int> y Collection<string> en probarTemplates().
template <typename T>
void mostrarCantidad(const string& nombre, const Collection<T>& coleccion)
{
    cout << "La coleccion '" << nombre << "' tiene "
         << coleccion.cantidad() << " elementos." << endl;
}

namespace {
Refugio refugio;             // objeto principal del sistema
int siguienteSolicitud = 1;  // numerador automatico de solicitudes

// Lee una linea completa (para nombres con espacios)
string leerLinea(const string& mensaje) {
    string texto;
    cout << mensaje;
    getline(cin >> ws, texto);
    return texto;
}
}

void mostrarMenu() {
    cout << "\n===== REFUGIO DE ANIMALES =====" << endl;
    cout << "1. Registrar perro o gato" << endl;
    cout << "2. Listar animales" << endl;
    cout << "3. Registrar adoptante" << endl;
    cout << "4. Buscar animal por ID" << endl;
    cout << "5. Gestionar solicitud de adopcion" << endl;
    cout << "6. Devolver animal a disponible" << endl;
    cout << "7. Mostrar historial" << endl;
    cout << "8. Mostrar solicitudes" << endl;
    cout << "9. Listar adoptantes" << endl;
    cout << "10. Probar templates" << endl;
    cout << "11. Prueba de copia profunda y memoria" << endl;
    cout << "0. Salir" << endl;
}

int leerOpcion() {
    return leerDato<int>("Elegi una opcion: ");   // leerDato con tipo int
}

void registrarAnimal() {
    int tipo = leerDato<int>("1. Perro\n2. Gato\nTipo: ");
    if (tipo != 1 && tipo != 2) {
        throw invalid_argument("Tipo de animal invalido (debe ser 1 o 2)");
    }

    int id = leerDato<int>("ID: ");
    // Se controla antes de pedir el resto de los datos
    if (refugio(id) != nullptr) {
        throw IdRepetidoException(id);
    }
    string nombre = leerLinea("Nombre: ");
    int edad = leerDato<int>("Edad: ");
    if (edad < 0) {
        throw invalid_argument("La edad no puede ser negativa");
    }
    string salud = leerLinea("Estado de salud: ");

    if (tipo == 1) {
        string raza = leerLinea("Raza: ");
        string tamanio = leerLinea("Tamanio (chico/mediano/grande): ");
        Perro perro(id, nombre, edad, salud, raza, tamanio);
        refugio.agregarAnimal(perro);
    } else {
        string color = leerLinea("Color de pelaje: ");
        char interior = leerDato<char>("Es de interior? (s/n): ");   // leerDato con tipo char
        if (interior != 's' && interior != 'S' && interior != 'n' && interior != 'N') {
            throw invalid_argument("Respuesta invalida: debe ser 's' o 'n'");
        }
        Gato gato(id, nombre, edad, salud, color, interior == 's' || interior == 'S');
        refugio.agregarAnimal(gato);
    }
    cout << "Animal registrado." << endl;
}

void listarAnimales() {
    int filtro = leerDato<int>("1. Todos\n2. Solo disponibles\n3. Ver animal por posicion\nOpcion: ");

    if (filtro == 1) {
        refugio.mostrarAnimales();
    } else if (filtro == 2) {
        refugio.mostrardisponibles();
    } else if (filtro == 3) {
        cout << "Hay " << refugio.getCantidadAnimales() << " animales (posiciones 0 a "
             << refugio.getCantidadAnimales() - 1 << ")." << endl;
        int pos = leerDato<int>("Posicion: ");
        refugio[pos].mostrarInfo();   // operador [] -> puede lanzar IndiceInvalidoException
    } else {
        cout << "Opcion invalida." << endl;
    }
}

void registrarAdoptante() {
    int id = leerDato<int>("ID: ");
    if (refugio.buscarAdoptante(id) != nullptr) {
        throw IdRepetidoException(id);
    }
    string nombre = leerLinea("Nombre: ");
    string contacto = leerLinea("Contacto (telefono o email): ");
    string vivienda = leerLinea("Tipo de vivienda: ");

    Adoptante adoptante(id, nombre, contacto, vivienda);
    refugio.agregarAdoptante(adoptante);
    cout << "Adoptante registrado." << endl;
}

void buscarAnimalPorId() {
    int id = leerDato<int>("ID del animal: ");
    refugio.buscarAnimal(id).mostrarInfo();   // lanza NoEncontradoException si no existe
}

void gestionarSolicitud() {
    int accion = leerDato<int>("1. Crear\n2. Confirmar\n3. Cancelar\nOpcion: ");

    if (accion == 1) {
        int idAdoptante = leerDato<int>("ID del adoptante: ");
        int idAnimal = leerDato<int>("ID del animal: ");
        refugio.crearSolicitud(siguienteSolicitud, idAdoptante, idAnimal);
        cout << "Solicitud " << siguienteSolicitud << " registrada (Pendiente)." << endl;
        siguienteSolicitud++;
    } else if (accion == 2) {
        refugio.mostrarSolicitudes();
        int idSolicitud = leerDato<int>("Numero de solicitud a confirmar: ");
        refugio.confirmarSolicitud(idSolicitud);
        cout << "Adopcion confirmada." << endl;
    } else if (accion == 3) {
        refugio.mostrarSolicitudes();
        int idSolicitud = leerDato<int>("Numero de solicitud a cancelar: ");
        refugio.cancelarSolicitud(idSolicitud);
        cout << "Solicitud cancelada. El animal vuelve a estar disponible." << endl;
    } else {
        cout << "Opcion invalida." << endl;
    }
}

void devolverAnimal() {
    int id = leerDato<int>("ID del animal a devolver: ");
    refugio.devolverAnimal(id);
    cout << "El animal vuelve a estar disponible." << endl;
}

void mostrarHistorial() {
    refugio.mostrarHistorial();
}

void mostrarSolicitudes() {
    refugio.mostrarSolicitudes();
}

void listarAdoptantes() {
    refugio.mostrarAdoptantes();
}

// ---------------------------------------------------------------------------
// FASE 5: prueba de templates y miembro estatico
// ---------------------------------------------------------------------------
void probarTemplates() {
    cout << "\n--- PRUEBA DE TEMPLATES ---" << endl;

    Collection<int> numeros;          // instanciacion 1: T = int
    numeros.agregar(10);
    numeros.agregar(20);

    Collection<string> razas;         // instanciacion 2: T = string
    razas.agregar("Labrador");
    razas.agregar("Caniche");
    razas.agregar("Mestizo");

    // Funcion generica usada con dos tipos distintos
    mostrarCantidad("numeros", numeros);   // T = int
    mostrarCantidad("razas", razas);       // T = string

    cout << "numeros[0] = " << numeros[0] << endl;
    cout << "razas[2]   = " << razas[2] << endl;

    // Indice invalido -> la coleccion lanza IndiceInvalidoException
    try {
        cout << "Intentando acceder a numeros[5]..." << endl;
        cout << numeros[5] << endl;
    } catch (const IndiceInvalidoException& e) {
        cout << "Excepcion capturada: " << e.what() << endl;
    }

    // Miembro estatico: cada instanciacion tiene SU PROPIO contador
    cout << "\nMiembro estatico cantidadColecciones (uno por cada tipo T):" << endl;
    cout << "  Collection<int>       -> " << Collection<int>::obtenerCantidadColecciones() << endl;
    cout << "  Collection<string>    -> " << Collection<string>::obtenerCantidadColecciones() << endl;
    cout << "  Collection<Adoptante> -> " << Collection<Adoptante>::obtenerCantidadColecciones() << endl;
    cout << "Collection<int>, Collection<string> y Collection<Adoptante> son clases\n"
            "distintas generadas por el compilador, por eso cada una lleva su propia\n"
            "cuenta. Las de string y Adoptante ya valen al menos 1 porque el Refugio\n"
            "usa una para el historial y otra para los adoptantes." << endl;
}

// ---------------------------------------------------------------------------
// Prueba de copia profunda, operador = y liberacion de memoria
// ---------------------------------------------------------------------------
namespace {
void verificar(const string& descripcion, bool ok) {
    cout << (ok ? "  [OK]    " : "  [FALLA] ") << descripcion << endl;
}
}

void probarCopiaProfunda() {
    cout << "\n--- PRUEBA DE COPIA PROFUNDA Y MEMORIA ---" << endl;
    int vivosAntes = Animal::getInstanciasVivas();
    cout << "Animales vivos en memoria antes de la prueba: " << vivosAntes << endl;

    {   // bloque: al cerrar la llave se destruyen todos los refugios de prueba
        Refugio original(2);   // capacidad 2 para forzar que el arreglo crezca
        original.agregarAnimal(Perro(100, "Rocky", 3, "Sano", "Mestizo", "Mediano"));
        original.agregarAnimal(Gato(101, "Michi", 2, "Sano", "Negro", true));
        original.agregarAnimal(Perro(102, "Luna", 5, "Sano", "Labrador", "Grande")); // crece a 4

        // 1) Constructor de copia
        Refugio copia(original);
        copia[0].setEstadoSalud("En tratamiento");
        copia.agregarAnimal(Gato(103, "Tom", 1, "Sano", "Gris", false));

        cout << "\nOriginal:" << endl;
        original.mostrarAnimales();
        cout << "\nCopia (modificada):" << endl;
        copia.mostrarAnimales();

        cout << "\nDireccion de original[0]: " << &original[0] << endl;
        cout << "Direccion de copia[0]:    " << &copia[0] << endl;

        verificar("Las direcciones son distintas (no se comparten punteros)", &original[0] != &copia[0]);
        verificar("operator== compara por ID: original[0] == copia[0]", original[0] == copia[0]);
        verificar("Cambiar la salud en la copia no cambia el original",
                  original[0].getEstadoSalud() == "Sano");
        verificar("Agregar a la copia no agrega al original",
                  original.getCantidadAnimales() == 3 && copia.getCantidadAnimales() == 4);

        // 2) Operador de asignacion
        Refugio asignado;
        asignado = original;
        asignado[1].setDisponible(false);
        verificar("operator=: cambiar el asignado no cambia el original",
                  original[1].getDisponible() && !asignado[1].getDisponible());

        // 3) Autoasignacion
        asignado = asignado;
        verificar("Autoasignacion (a = a) no rompe el objeto", asignado.getCantidadAnimales() == 3);

        cout << "Animales vivos dentro del bloque: " << Animal::getInstanciasVivas() << endl;
    }   // <- aca se llaman los destructores de original, copia y asignado

    int vivosDespues = Animal::getInstanciasVivas();
    cout << "Animales vivos despues de destruir los refugios: " << vivosDespues << endl;
    verificar("Todos los animales creados en la prueba fueron liberados (sin fugas)",
              vivosAntes == vivosDespues);
}
