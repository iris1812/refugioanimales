#include <iostream>
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
SolicitudAdopcion::SolicitudAdopcion(int id, Adoptante adoptanteParam, Animal animalParam, string estadoParam) {
    idSolicitud = id;
    solicitante = adoptanteParam;
    animalSolicitado = animalParam;
    estado = estadoParam;
}

// 3. Constructor de copia (recibe una referencia constante)
SolicitudAdopcion::SolicitudAdopcion(const SolicitudAdopcion &otra) {
    idSolicitud = otra.idSolicitud;
    solicitante = otra.solicitante;
    animalSolicitado = otra.animalSolicitado;
    estado = otra.estado;
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
    // Si tus clases Adoptante y Animal tienen el método mostrarInfo(), podés llamarlo así:
    // solicitante.mostrarInfo();
    // animalSolicitado.mostrarInfo();
}