#ifndef SOLICITUDADOPCION_H
#define SOLICITUDADOPCION_H

#include <string>
#include "Adoptante.h"
#include "Animal.h"

using namespace std;

class SolicitudAdopcion {
private:
    int idSolicitud;
    Adoptante solicitante;      // Usamos la clase que ya creaste
    Animal animalSolicitado;    // Usamos la clase que ya creaste
    string estado;              // Ej: "En revisión", "Aprobada", "Rechazada"

public:
    // 1. Constructor por defecto
    SolicitudAdopcion();

    // 2. Constructor parametrizado
    SolicitudAdopcion(int id, Adoptante adoptanteParam, Animal animalParam, string estadoParam);

    // 3. Constructor de copia
    SolicitudAdopcion(const SolicitudAdopcion &otra);

    // 4. Destructor
    ~SolicitudAdopcion();

    // Getters básicos
    int getIdSolicitud() const;
    string getEstado() const;

    // Método para imprimir
    void mostrarSolicitud() const;
};

#endif