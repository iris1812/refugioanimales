#ifndef REFUGIO_H
#define REFUGIO_H

#include "Animal.h"

class Refugio {
private:
    Animal* animales;
    int cantidad;
    int capacidad;

public:
    // Constructor
    Refugio();

    // Destructor
    ~Refugio();

    // Métodos
    void agregarAnimal(const Animal& animal);
    void mostrarAnimales() const;
};

#endif