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
    Collection<Adoptante> adoptantes;             // template con tipo Adoptante
    std::vector<SolicitudAdopcion> solicitudes;
    Collection<std::string> historial;            // template con tipo string
    SolicitudAdopcion& buscarSolicitud(int idSolicitud);

public:
    Refugio();                                 // por defecto
    Refugio(int capacidadInicial);             // parametrizado
    Refugio(const Refugio& otro);              // de copia (copia profunda)
    ~Refugio();
    Refugio& operator=(const Refugio& otro);
    void agregarAnimal(const Animal& animal);     // lanza IdRepetidoException
    void mostrarDisponibles() const;
    void mostrarAnimales() const;
    int getCantidadAnimales() const;
    Animal& buscarAnimal(int id);                 // lanza NoEncontradoException
    void agregarAdoptante(const Adoptante& adoptante);  // lanza IdRepetidoException
    Adoptante* buscarAdoptante(int id);                 // devuelve nullptr si no existe
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