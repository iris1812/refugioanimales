#ifndef REFUGIO_H
#define REFUGIO_H
#include "Animal.h"
#include "Adoptante.h"
#include "SolicitudAdopcion.h"
#include "Collection.h"
#include "Excepciones.h"
#include <vector>
#include <string>
class Refugio {
private:
    Animal** animales;
    int cantidad;
    int capacidad;
    Collection<Adoptante> adoptantes;
    std::vector<SolicitudAdopcion> solicitudes;
    Collection<std::string> historial;
    SolicitudAdopcion& buscarSolicitud(int idSolicitud);
public:
    Refugio();
    Refugio(int capacidadInicial);
    Refugio(const Refugio& otro);
    ~Refugio();
    Refugio& operator=(const Refugio& otro);
    void agregarAnimal(const Animal& animal);
    void mostrarDisponibles() const;
    void mostrarAnimales() const;
    int getCantidadAnimales() const;
    Animal& buscarAnimal(int id);
    void agregarAdoptante(const Adoptante& adoptante);
    Adoptante* buscarAdoptante(int id);
    void mostrarAdoptantes() const;
    void crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal);
    void confirmarSolicitud(int idSolicitud);
    void cancelarSolicitud(int idSolicitud);
    void devolverAnimal(int idAnimal);
    void mostrarSolicitudes() const;
    void mostrarHistorial() const;
    Animal& operator[](int indice);
    const Animal& operator[](int indice) const;
    Animal* operator()(int idBuscado);
    const Animal* operator()(int idBuscado) const;
};
#endif