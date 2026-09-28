#include <iostream>
#include "Gato.h"

Gato::Gato(int id, string nombre, int edad, string salud, string color, bool usaArenero)
    : Animal(id, nombre, edad, salud), color(color), usaArenero(usaArenero) {}

void Gato::mostrarInfo() const {
    Animal::mostrarInfo();
    std::cout << "  Tipo: Gato | Color: " << color
              << " | Usa arenero: " << (usaArenero ? "Si" : "No") << std::endl;
}

Animal* Gato::clone() const {
    return new Gato(*this);
}