#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
private:
    string raza;
    string tamanio;

public:
    Perro(int id, string nombre, int edad, string salud, string raza, string tamanio);
    void mostrarInfo() const override;
    Animal* clone() const override;
};

#endif