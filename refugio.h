#ifndef REFUGIO_H
#define REFUGIO_H

#include "Animal.h"
#include "Adoptante.h"
#include "SolicitudAdopcion.h"
#include "Collection.h"
#include "Excepciones.h"
#include <vector>
#include <string>

// ============================================================================
// DOCUMENTACION DE MEMORIA (quien crea y quien libera cada bloque)
// ----------------------------------------------------------------------------
// 1) Arreglo dinamico 'animales' (Animal**):
//    - LO CREA: Refugio, con new Animal*[capacidad] en sus constructores y
//      al duplicar la capacidad dentro de agregarAnimal().
//    - LO LIBERA: Refugio, con delete[] en el destructor y en agregarAnimal()
//      (se libera el arreglo viejo despues de pasar los punteros al nuevo).
// 2) Cada animal del catalogo (Perro/Gato):
//    - LO CREA: Refugio::agregarAnimal() llamando a animal.clone() (hace new).
//    - LO LIBERA: Refugio::~Refugio() con delete animales[i]. Como el
//      destructor de Animal es virtual, se llama tambien al de Perro/Gato.
// 3) Copia del animal dentro de cada SolicitudAdopcion:
//    - LA CREA: el constructor de SolicitudAdopcion con clone().
//    - LA LIBERA: automaticamente el unique_ptr al destruirse la solicitud.
// 4) adoptantes (Collection<Adoptante>), historial (Collection<string>) y
//    solicitudes (vector) manejan su memoria solos.
//
// REGLA DE LOS TRES: Refugio administra memoria dinamica, por eso define
// constructor de copia (copia profunda con clone()), operator= y destructor.
// ============================================================================

class Refugio {
private:
    Animal** animales;
    int cantidad;
    int capacidad;
    Collection<Adoptante> adoptantes;             // template con tipo Adoptante
    std::vector<SolicitudAdopcion> solicitudes;
    Collection<std::string> historial;            // template con tipo string

    // Busca la solicitud por ID; lanza NoEncontradoException si no existe
    SolicitudAdopcion& buscarSolicitud(int idSolicitud);

public:
    // Constructores
    Refugio();                                 // por defecto
    Refugio(int capacidadInicial);             // parametrizado
    Refugio(const Refugio& otro);              // de copia (copia profunda)

    // Destructor
    ~Refugio();

    // Asignacion (copia profunda)
    Refugio& operator=(const Refugio& otro);

    // ----- Animales -----
    void agregarAnimal(const Animal& animal);     // lanza IdRepetidoException
    void mostrardisponibles() const;
    void mostrarAnimales() const;
    int getCantidadAnimales() const;
    Animal& buscarAnimal(int id);                 // lanza NoEncontradoException

    // ----- Adoptantes -----
    void agregarAdoptante(const Adoptante& adoptante);  // lanza IdRepetidoException
    Adoptante* buscarAdoptante(int id);                 // devuelve nullptr si no existe
    void mostrarAdoptantes() const;

    // ----- Solicitudes -----
    // Lanzan NoEncontradoException, AnimalNoDisponibleException u
    // OperacionInvalidaException segun el caso
    void crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal);
    void confirmarSolicitud(int idSolicitud);
    void cancelarSolicitud(int idSolicitud);
    void devolverAnimal(int idAnimal);
    void mostrarSolicitudes() const;
    void mostrarHistorial() const;

    // ----- Operadores -----
    // [] acceso por posicion (lanza IndiceInvalidoException)
    Animal& operator[](int indice);
    const Animal& operator[](int indice) const;

    // () busqueda por ID: devuelve puntero al animal o nullptr si no existe
    Animal* operator()(int idBuscado);
    const Animal* operator()(int idBuscado) const;
};

#endif