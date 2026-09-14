

#include <iostream>  
#include "menu.h"

using namespace std;  
const int CANTIDAD_EJEMPLO = 3;
string animalesEjemplo[CANTIDAD_EJEMPLO] = {"Firulais", "Michi", "Rocky"};

void mostrarMenu() {
    cout << "\n Refugio de Animales" << endl;
    cout << "1. Registrar perro o gato" << endl;
    cout << "2. Listar animales" << endl;
    cout << "3. Registrar adoptante" << endl;
    cout << "4. Buscar animal por ID" << endl;
    cout << "5. Gestionar solicitud de adopcion" << endl;
    cout << "6. Devolver animal a disponible" << endl;
    cout << "7. Mostrar historial" << endl;
    cout << "0. Salir" << endl;
    cout << "Elegi una opcion: ";
}

int leerOpcion() {
    int opcion;          // Declaramos una variable entera (todavía vacía)
    cin >> opcion;        // cin guarda lo que tipea el usuario DENTRO de opcion
    return opcion;         // Devolvemos ese valor a quien llamó a la función
}

void registrarAnimal() {
    
}

void listarAnimales() {
    cout << "Animales de ejemplo cargados:" << endl;
    for (int i = 0; i < CANTIDAD_EJEMPLO; i++) {
        cout << " - " << animalesEjemplo[i] << endl;
    }
}

void registrarAdoptante() {
}

void buscarAnimalPorId() {
}

void gestionarSolicitud() {
}

void devolverAnimal() {
}

void mostrarHistorial() {
}
