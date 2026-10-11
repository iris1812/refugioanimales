#include <iostream>
#include <utility>
#include "SolicitudAdopcion.h"
using namespace std;

SolicitudAdopcion::SolicitudAdopcion() {
    idSolicitud = 0;
    estado = "Pendiente";
}
SolicitudAdopcion::SolicitudAdopcion(int id, const Adoptante& adoptanteParam, const Animal& animalParam, string estadoParam)
    : idSolicitud(id), solicitante(adoptanteParam), animalSolicitado(animalParam.clone()), estado(estadoParam) {
    animalSolicitado->setDisponible(false);
}
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
SolicitudAdopcion::~SolicitudAdopcion() {
}
int SolicitudAdopcion::getIdSolicitud() const {
    return idSolicitud;
}
string SolicitudAdopcion::getEstado() const {
    return estado;
}

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
void SolicitudAdopcion::setEstado(string nuevoEstado) {
    estado = nuevoEstado;
}

int SolicitudAdopcion::getIdAnimal() const {
    if (animalSolicitado == nullptr) {
        return -1;
    }
    return animalSolicitado->getId();
}