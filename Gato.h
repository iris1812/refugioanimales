#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal {
private:
    string color;
    bool usaArenero;

public:
    Gato(int id, string nombre, int edad, string salud, string color, bool usaArenero);
    void mostrarInfo() const override;
    Animal* clone() const override;
};

#endif