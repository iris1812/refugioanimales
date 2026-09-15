// Adoptante.h
#ifndef ADOPTANTE_H
#define ADOPTANTE_H

#include <string>
using namespace std;

class Adoptante {
private:
    int id;
    string nombre;
    string contacto;      // telefono o email
    string tipoVivienda;  // ej: "Casa con patio", "Departamento"

public:
    Adoptante();                                                  // por defecto
    Adoptante(int id, string nombre, string contacto, string tipoVivienda); // parametrizado
    Adoptante(const Adoptante &otro);                              // copia
    ~Adoptante();

    int getId() const;
    string getNombre() const;
    string getContacto() const;
    string getTipoVivienda() const;

    void mostrarInfo() const;
};

#endif