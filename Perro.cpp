#include <iostream>
#include "Perro.h"

Perro::Perro(int id, string nombre, int edad, string salud, string raza, bool entrenado)
    : Animal(id, nombre, edad, salud), raza(raza), entrenado(entrenado) {}

void Perro::mostrarInfo() const {
    Animal::mostrarInfo();
    std::cout << "  Tipo: Perro | Raza: " << raza
              << " | Entrenado: " << (entrenado ? "Si" : "No") << std::endl;
}

Animal* Perro::clone() const {
    return new Perro(*this);
}