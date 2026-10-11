#ifndef ADOPTANTE_H
#define ADOPTANTE_H
#include <string>
using namespace std;

class Adoptante {
private:
    int id;
    string nombre;
    string contacto;
    string tipoVivienda;

public:
    Adoptante();
    Adoptante(int id, string nombre, string contacto, string tipoVivienda);
    Adoptante(const Adoptante &otro);
    ~Adoptante();

    int getId() const;
    string getNombre() const;
    string getContacto() const;
    string getTipoVivienda() const;

    void mostrarInfo() const;
};

#endif