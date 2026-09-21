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

// 1. Sobrecarga del operador de asignación (=) para Deep Copy
Refugio& Refugio::operator=(const Refugio& otro) {
    // Evitar la autoasignación (ej: miRefugio = miRefugio)
    if (this == &otro) {
        return *this;
    }

    // Liberar la memoria actual del objeto que recibe la asignación
    delete[] this->animales;

    // Copiar los atributos simples
    this->cantidad = otro.cantidad;
    this->capacidad = otro.capacidad;

    // Asignar nueva memoria y copiar los elementos
    this->animales = new Animal[this->capacidad];
    for (int i = 0; i < this->cantidad; i++) {
        *(this->animales + i) = *(otro.animales + i); 
    }

    return *this; // Retornamos el objeto actual para permitir asignaciones en cadena (a = b = c)
}

// 2. Sobrecarga de corchetes [] (Acceso por posición)
Animal& Refugio::operator[](int indice) {
    // Validar que el índice esté dentro del rango
    if (indice < 0 || indice >= cantidad) {
        std::cerr << "Error: Indice fuera de rango." << std::endl;
        // Para evitar crashes inmediatos, devolvemos el primero o manejamos el error.
        return *animales; 
    }
    // Retornamos el animal usando aritmética de punteros (o animales[indice])
    return *(animales + indice);
}

// 3. Sobrecarga de paréntesis () (Búsqueda por ID)
Animal* Refugio::operator()(int idBuscado) {
    for (int i = 0; i < cantidad; i++) {
        // Usamos el operador == que sobrecargaste en la clase Animal
        // o directamente comparamos los IDs.
        if ((animales + i)->getId() == idBuscado) {
            return (animales + i); // Retorna el puntero al animal encontrado
        }
    }
    return nullptr; // Si no lo encuentra, retorna un puntero nulo
}