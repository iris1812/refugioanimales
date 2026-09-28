#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal {
private:
    string color;
    bool interior;

public:
    Gato(int id, string nombre, int edad, string salud, string color, bool interior);
    void mostrarInfo() const override;
    Animal* clone() const override;
};

#endif