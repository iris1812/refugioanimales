#include <iostream>
#include "Perro.h"

Perro::Perro(int id, string nombre, int edad, string salud, string raza, string tamanio)
    : Animal(id, nombre, edad, salud), raza(raza), tamanio(tamanio) {}

void Perro::mostrarInfo() const {
    Animal::mostrarInfo();
    std::cout << "  Tipo: Perro | Raza: " << raza
              << " | Tamaño: " << tamanio << std::endl;
}

Animal* Perro::clone() const {
    return new Perro(*this);
}