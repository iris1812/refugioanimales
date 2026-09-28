#include <iostream>
#include "Gato.h"

Gato::Gato(int id, string nombre, int edad, string salud, string color, bool interior)
    : Animal(id, nombre, edad, salud), color(color), interior(interior) {}

void Gato::mostrarInfo() const {
    Animal::mostrarInfo();
    std::cout << "  Tipo: Gato | Color: " << color
            << " | Interior: " << (interior ? "Si" : "No") << std::endl;
}

Animal* Gato::clone() const {
    return new Gato(*this);
}