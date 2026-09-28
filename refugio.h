#ifndef REFUGIO_H
#define REFUGIO_H

#include "Animal.h"
#include "SolicitudAdopcion.h"
#include <vector>

 //DOCUMENTACIÓN DE MEMORIA:
 //La clase Refugio se encarga de crear el bloque de memoria dinámica para el arreglo 'animales' en sus constructores y al expandir su capacidad. Asimismo, es responsable de liberar esta memoria en su destructor.

class Refugio {
private:
    Animal** animales;
    int cantidad;
    int capacidad;
    vector<Adoptante> adoptantes;
    vector<SolicitudAdopcion> solicitudes;

public:
    // ConstructoresFase 2
    Refugio();                                 // Constructor por defecto
    Refugio(int capacidadInicial);             // Constructor parametrizado
    Refugio(const Refugio& otro);              // Constructor de copia

    // Destructor
    ~Refugio();

    // Métodos
    void agregarAnimal(const Animal& animal);
    void mostrarAnimales() const;
    void agregarAdoptante(const Adoptante& adoptante);
    Adoptante* buscarAdoptante(int id);
    bool crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal);
    void mostrarSolicitudes() const;
    Refugio& operator=(const Refugio& otro);

    // 2. Sobrecarga de corchetes [] para acceso por posición
    Animal& operator[](int indice);
    const Animal& operator[](int indice) const;

    // 3. Sobrecarga de paréntesis () para búsqueda por ID
    // Retorna un puntero al animal si lo encuentra, o nullptr si no existe
    Animal* operator()(int idBuscado);
    const Animal* operator()(int idBuscado) const;
};

#endif