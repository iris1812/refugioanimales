#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
private:
    string raza;
    bool entrenado;

public:
    Perro(int id, string nombre, int edad, string salud, string raza, bool entrenado);
    void mostrarInfo() const override;
    Animal* clone() const override;
};

#endif