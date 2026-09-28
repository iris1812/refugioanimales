

#include <iostream>
#include <string>
#include "menu.h"
#include "refugio.h"
#include "Perro.h"
#include "Gato.h"

using namespace std;

namespace {
Refugio refugio;
int siguienteSolicitud = 1;
}

void mostrarMenu() {
    cout << "\n Refugio de Animales" << endl;
    cout << "1. Registrar perro o gato" << endl;
    cout << "2. Listar animales" << endl;
    cout << "3. Registrar adoptante" << endl;
    cout << "4. Buscar animal por ID" << endl;
    cout << "5. Gestionar solicitud de adopcion" << endl;
    cout << "6. Devolver animal a disponible" << endl;
    cout << "7. Mostrar historial" << endl;
    cout << "8. Mostrar solicitudes" << endl;
    cout << "0. Salir" << endl;
    cout << "Elegi una opcion: ";
}

int leerOpcion() {
    int opcion;          // Declaramos una variable entera (todavía vacía)
    cin >> opcion;        // cin guarda lo que tipea el usuario DENTRO de opcion
    return opcion;         // Devolvemos ese valor a quien llamó a la función
}

void registrarAnimal() {
    int tipo;
    int id;
    int edad;
    string nombre;
    string salud;

    cout << "1. Perro\n2. Gato\nTipo: ";
    cin >> tipo;
    if (tipo != 1 && tipo != 2) {
        cout << "Tipo invalido." << endl;
        return;
    }

    cout << "ID: ";
    cin >> id;
    if (refugio(id) != nullptr) {
        cout << "Ya existe un animal con ese ID." << endl;
        return;
    }
    cout << "Nombre: ";
    getline(cin >> ws, nombre);
    cout << "Edad: ";
    cin >> edad;
    cout << "Estado de salud: ";
    getline(cin >> ws, salud);

    if (tipo == 1) {
        string raza;
        string tamanio;
        cout << "Raza: ";
        getline(cin >> ws, raza);
        cout << "Tamaño: ";
        getline(cin >> ws, tamanio);
        Perro perro(id, nombre, edad, salud, raza, tamanio);
        refugio.agregarAnimal(perro);
    } else {
        string color;
        int interior;
        cout << "Color: ";
        getline(cin >> ws, color);
        cout << "Es de Interior (1 si, 0 no): ";
        cin >> interior;
        Gato gato(id, nombre, edad, salud, color, interior != 0);
        refugio.agregarAnimal(gato);
    }
    cout << "Animal registrado." << endl;
}

void listarAnimales() {
    int filtro;
    cout << "1. Todos\n2. Solo disponibles\nOpcion: ";
    cin >> filtro;

    if (filtro == 1) {
        refugio.mostrarAnimales();
    } else if (filtro == 2) {
        refugio.mostrardisponibles();
    } else {
        cout << "Opcion invalida." << endl;
    }
}

void registrarAdoptante() {
    int id;
    string nombre;
    string contacto;
    string vivienda;

    cout << "ID: ";
    cin >> id;
    if (refugio.buscarAdoptante(id) != nullptr) {
        cout << "Ya existe un adoptante con ese ID." << endl;
        return;
    }
    cout << "Nombre: ";
    getline(cin >> ws, nombre);
    cout << "Contacto: ";
    getline(cin >> ws, contacto);
    cout << "Tipo de vivienda: ";
    getline(cin >> ws, vivienda);

    Adoptante adoptante(id, nombre, contacto, vivienda);
    refugio.agregarAdoptante(adoptante);
    cout << "Adoptante registrado." << endl;
}

void buscarAnimalPorId() {
    int id;
    cout << "ID del animal: ";
    cin >> id;
    Animal* animal = refugio(id);
    if (animal == nullptr) {
        cout << "No se encontro ese animal." << endl;
        return;
    }
    animal->mostrarInfo();
}

void gestionarSolicitud() {
    int accion;
    cout << "1. Crear\n2. Confirmar\n3. Cancelar\nOpcion: ";
    cin >> accion;

    if (accion == 1) {
        int idAdoptante;
        int idAnimal;
        cout << "ID del adoptante: ";
        cin >> idAdoptante;
        cout << "ID del animal: ";
        cin >> idAnimal;

        if (refugio.crearSolicitud(siguienteSolicitud, idAdoptante, idAnimal)) {
            cout << "Solicitud " << siguienteSolicitud << " registrada." << endl;
            siguienteSolicitud++;
        } else {
            cout << "No se pudo crear la solicitud. Verifica los IDs y la disponibilidad." << endl;
        }
    } else if (accion == 2) {
        int idSolicitud;
        refugio.mostrarSolicitudes();
        cout << "Numero de solicitud a confirmar: ";
        cin >> idSolicitud;

        if (refugio.confirmarSolicitud(idSolicitud)) {
            cout << "Adopcion confirmada." << endl;
        } else {
            cout << "No se pudo confirmar. La solicitud no existe o no esta pendiente." << endl;
        }
    } else if (accion == 3) {
        int idSolicitud;
        refugio.mostrarSolicitudes();
        cout << "Numero de solicitud a cancelar: ";
        cin >> idSolicitud;

        if (refugio.cancelarSolicitud(idSolicitud)) {
            cout << "Solicitud cancelada. El animal vuelve a estar disponible." << endl;
        } else {
            cout << "No se pudo cancelar. La solicitud no existe o no esta pendiente." << endl;
        }
    } else {
        cout << "Opcion invalida." << endl;
    }
}
void devolverAnimal() {
    int id;
    cout << "ID del animal a devolver: ";
    cin >> id;

    if (refugio(id) == nullptr) {
        cout << "No se encontro ese animal." << endl;
        return;
    }
    if (!refugio.devolverAnimal(id)) {
        cout << "Ese animal no fue adoptado." << endl;
        return;
    }
    cout << "El animal vuelve a estar disponible." << endl;
}
void mostrarHistorial() {
    refugio.mostrarHistorial();
}

void mostrarSolicitudes() {
    refugio.mostrarSolicitudes();
}
