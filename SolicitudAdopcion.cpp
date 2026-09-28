#include <iostream>
#include <utility>
#include "SolicitudAdopcion.h"

using namespace std;

// 1. Constructor por defecto
SolicitudAdopcion::SolicitudAdopcion() {
    idSolicitud = 0;
    estado = "Pendiente";
    // Nota: 'solicitante' y 'animalSolicitado' se inicializan solos 
    // porque C++ llama automáticamente a sus propios constructores por defecto.
}

// 2. Constructor parametrizado
SolicitudAdopcion::SolicitudAdopcion(int id, const Adoptante& adoptanteParam, const Animal& animalParam, string estadoParam)
    : idSolicitud(id), solicitante(adoptanteParam), animalSolicitado(animalParam.clone()), estado(estadoParam) {
    animalSolicitado->setDisponible(false);
}

// 3. Constructor de copia (recibe una referencia constante)
SolicitudAdopcion::SolicitudAdopcion(const SolicitudAdopcion &otra)
    : idSolicitud(otra.idSolicitud), solicitante(otra.solicitante),
      animalSolicitado(otra.animalSolicitado ? otra.animalSolicitado->clone() : nullptr), estado(otra.estado) {}

SolicitudAdopcion& SolicitudAdopcion::operator=(const SolicitudAdopcion& otra) {
    if (this != &otra) {
        SolicitudAdopcion copia(otra);
        std::swap(idSolicitud, copia.idSolicitud);
        std::swap(solicitante, copia.solicitante);
        animalSolicitado.swap(copia.animalSolicitado);
        estado.swap(copia.estado);
    }
    return *this;
}

// 4. Destructor
SolicitudAdopcion::~SolicitudAdopcion() {
    // Como esta clase no usa "new" para crear memoria dinámica propia, 
    // el destructor queda vacío. Igual se incluye para cumplir la consigna.
}

// Implementación de los Getters
int SolicitudAdopcion::getIdSolicitud() const {
    return idSolicitud;
}

string SolicitudAdopcion::getEstado() const {
    return estado;
}

// Implementación del método para mostrar datos
void SolicitudAdopcion::mostrarSolicitud() const {
    cout << "=== Solicitud Nro: " << idSolicitud << " ===" << endl;
    cout << "Estado: " << estado << endl;
    cout << "Adoptante: ";
    solicitante.mostrarInfo();
    cout << "Animal solicitado: ";
    if (animalSolicitado) {
        animalSolicitado->mostrarInfo();
    }
}