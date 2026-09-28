#include <iostream>
#include <stdexcept>
#include "refugio.h"

using namespace std;

// Constructor
Refugio::Refugio() {
    cantidad = 0;
    capacidad = 5;

    animales = new Animal*[capacidad]();
}

Refugio::Refugio(int capacidadInicial) {
    cantidad = 0;
    capacidad = capacidadInicial > 0 ? capacidadInicial : 5;
    animales = new Animal*[capacidad]();
}

Refugio::Refugio(const Refugio& otro)
        : cantidad(otro.cantidad), capacidad(otro.capacidad),
            adoptantes(otro.adoptantes), solicitudes(otro.solicitudes),historial(otro.historial) {
    animales = new Animal*[capacidad]();

    for (int i = 0; i < cantidad; i++) {
        animales[i] = otro.animales[i]->clone();
    }
}

Refugio& Refugio::operator=(const Refugio& otro) {
    if (this != &otro) {
        Refugio copia(otro);
        std::swap(animales, copia.animales);
        std::swap(cantidad, copia.cantidad);
        std::swap(capacidad, copia.capacidad);
        adoptantes = copia.adoptantes;
        solicitudes = copia.solicitudes;
        historial = copia.historial;
    }
    return *this;
}

// Destructor
Refugio::~Refugio() {
    for (int i = 0; i < cantidad; i++) {
        delete animales[i];
    }
    delete[] animales;
    animales = nullptr;
}

// Agregar un animal
void Refugio::agregarAnimal(const Animal& animal) {

    // Si la colección está llena, aumentar la capacidad
    if (cantidad == capacidad) {

        int nuevaCapacidad = capacidad * 2;

        Animal** nuevosAnimales = new Animal*[nuevaCapacidad]();

        // Copiar los animales anteriores
        for (int i = 0; i < cantidad; i++) {
            nuevosAnimales[i] = animales[i];
        }

        // Liberar la memoria anterior
        delete[] animales;

        // Actualizar el puntero y la capacidad
        animales = nuevosAnimales;
        capacidad = nuevaCapacidad;
    }

    // Agregar el nuevo animal usando aritmética de punteros
    *(animales + cantidad) = animal.clone();

    cantidad++;
}

// Mostrar todos los animales
void Refugio::mostrarAnimales() const {

    cout << " ANIMALES DEL REFUGIO" << endl;

    for (Animal** p= animales; p < animales + cantidad; ++p) {
        (*p)->mostrarInfo();
    }
}
void Refugio:: mostrardisponibles() const {
    for (int i=0; i < cantidad; i++) {
        if (!(*animales[i])) continue; // Si el animal NO está disponible, saltar al siguiente{
            animales[i]->mostrarInfo();
        }
    }

// 2. Sobrecarga de corchetes [] (Acceso por posición)
Animal& Refugio::operator[](int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw out_of_range("Indice de animal fuera de rango");
    }
    return *animales[indice];
}

const Animal& Refugio::operator[](int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw out_of_range("Indice de animal fuera de rango");
    }
    return *animales[indice];
}

// 3. Sobrecarga de paréntesis () (Búsqueda por ID)
Animal* Refugio::operator()(int idBuscado) {
    for (int i = 0; i < cantidad; i++) {
        if (animales[i]->getId() == idBuscado) {
            return animales[i];
        }
    }
    return nullptr;
}

const Animal* Refugio::operator()(int idBuscado) const {
    for (int i = 0; i < cantidad; i++) {
        if (animales[i]->getId() == idBuscado) {
            return animales[i];
        }
    }
    return nullptr;
}

void Refugio::agregarAdoptante(const Adoptante& adoptante) {
    adoptantes.push_back(adoptante);
}

Adoptante* Refugio::buscarAdoptante(int id) {
    for (Adoptante& adoptante : adoptantes) {
        if (adoptante.getId() == id) {
            return &adoptante;
        }
    }
    return nullptr;
}

bool Refugio::crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal) {
    Adoptante* adoptante = buscarAdoptante(idAdoptante);
    Animal* animal = (*this)(idAnimal);
    if (adoptante == nullptr || animal == nullptr || !animal->getDisponible()) {
        return false;
    }

    solicitudes.emplace_back(idSolicitud, *adoptante, *animal, "Pendiente");
    animal->setDisponible(false);
    return true;
}

void Refugio::mostrarSolicitudes() const {
    if (solicitudes.empty()) {
        cout << "No hay solicitudes registradas." << endl;
        return;
    }
    for (const SolicitudAdopcion& solicitud : solicitudes) {
        solicitud.mostrarSolicitud();
    }
}
bool Refugio::confirmarSolicitud(int idSolicitud) {
    for (SolicitudAdopcion& s : solicitudes) {
        if (s.getIdSolicitud() == idSolicitud) {
            if (s.getEstado() != "Pendiente") return false;
            s.setEstado("Confirmada");
            Animal* animal = (*this)(s.getIdAnimal());
            if (animal != nullptr)
                historial.push_back(animal->getNombre() + " fue adoptado (solicitud " + to_string(idSolicitud) + ").");
            return true;
        }
    }
    return false;   // no existe esa solicitud
}

bool Refugio::cancelarSolicitud(int idSolicitud) {
    for (SolicitudAdopcion& s : solicitudes) {
        if (s.getIdSolicitud() == idSolicitud) {
            if (s.getEstado() != "Pendiente") return false;
            s.setEstado("Cancelada");
            Animal* animal = (*this)(s.getIdAnimal());
            if (animal != nullptr) animal->setDisponible(true);
            return true;
        }
    }
    return false;
}

bool Refugio::devolverAnimal(int idAnimal) {
    Animal* animal = (*this)(idAnimal);
    if (animal == nullptr) return false;

    for (SolicitudAdopcion& s : solicitudes) {
        if (s.getIdAnimal() == idAnimal && s.getEstado() == "Confirmada") {
            s.setEstado("Devuelta");
            animal->setDisponible(true);
            historial.push_back(animal->getNombre() + " fue devuelto al refugio.");
            return true;
        }
    }
    return false;   // nunca fue adoptado
}

void Refugio::mostrarHistorial() const {
    if (historial.empty()) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    for (const string& linea : historial) {
        cout << "- " << linea << endl;
    }
}