#include <iostream>
#include "Refugio.h"

using namespace std;

// Constructor
Refugio::Refugio() {
    cantidad = 0;
    capacidad = 5;

    animales = new Animal[capacidad];
}

// Destructor
Refugio::~Refugio() {
    delete[] animales;
    animales = nullptr;
}

// Agregar un animal
void Refugio::agregarAnimal(const Animal& animal) {

    // Si la colección está llena, aumentar la capacidad
    if (cantidad == capacidad) {

        int nuevaCapacidad = capacidad * 2;

        Animal* nuevosAnimales = new Animal[nuevaCapacidad];

        // Copiar los animales anteriores
        for (int i = 0; i < cantidad; i++) {
            *(nuevosAnimales + i) = *(animales + i);
        }

        // Liberar la memoria anterior
        delete[] animales;

        // Actualizar el puntero y la capacidad
        animales = nuevosAnimales;
        capacidad = nuevaCapacidad;
    }

    // Agregar el nuevo animal usando aritmética de punteros
    *(animales + cantidad) = animal;

    cantidad++;
}

// Mostrar todos los animales
void Refugio::mostrarAnimales() const {

    cout << "===== ANIMALES DEL REFUGIO =====" << endl;

    for (int i = 0; i < cantidad; i++) {

        (animales + i)->mostrarInfo();
    }
}