#include <iostream>
#include <string>
#include <stdexcept>
#include "menu.h"
#include "refugio.h"
#include "Perro.h"
#include "Gato.h"
#include "Utilidades.h"
#include "Excepciones.h"

using namespace std;

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
