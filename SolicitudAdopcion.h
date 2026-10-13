#ifndef SOLICITUDADOPCION_H
#define SOLICITUDADOPCION_H
#include <string>
#include <memory>
#include "Adoptante.h"
#include "Animal.h"
using namespace std;
class SolicitudAdopcion {
private:
    int idSolicitud;
    Adoptante solicitante;
    unique_ptr<Animal> animalSolicitado;
    string estado;
public:
    SolicitudAdopcion();
    SolicitudAdopcion(int id, const Adoptante& adoptanteParam, const Animal& animalParam, string estadoParam);
    SolicitudAdopcion(const SolicitudAdopcion &otra);
    SolicitudAdopcion& operator=(const SolicitudAdopcion& otra);
    ~SolicitudAdopcion();
    int getIdSolicitud() const;
    string getEstado() const;
    void mostrarSolicitud() const;
    void setEstado(string nuevoEstado);
    int getIdAnimal() const;
};

#endif