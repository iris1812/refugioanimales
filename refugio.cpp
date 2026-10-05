#include <iostream>
#include <utility>
#include "refugio.h"

using namespace std;

// ---------------------------------------------------------------------------
// Constructores, destructor y asignacion (Regla de los Tres)
// ---------------------------------------------------------------------------

// Constructor por defecto: crea el arreglo dinamico con capacidad 5
Refugio::Refugio() {
    cantidad = 0;
    capacidad = 5;
    animales = new Animal*[capacidad]();   // CREA: Refugio
}

// Constructor parametrizado
Refugio::Refugio(int capacidadInicial) {
    cantidad = 0;
    capacidad = capacidadInicial > 0 ? capacidadInicial : 5;
    animales = new Animal*[capacidad]();   // CREA: Refugio
}

// Constructor de copia: COPIA PROFUNDA.
// No copia los punteros (eso seria copia superficial y los dos refugios
// compartirian los mismos animales -> doble delete). Crea un arreglo nuevo
// y clona cada animal con clone(), que respeta el tipo real (Perro/Gato).
Refugio::Refugio(const Refugio& otro)
    : cantidad(otro.cantidad), capacidad(otro.capacidad),
      adoptantes(otro.adoptantes), solicitudes(otro.solicitudes),
      historial(otro.historial) {
    animales = new Animal*[capacidad]();
    for (int i = 0; i < cantidad; i++) {
        animales[i] = otro.animales[i]->clone();
    }
}

// Operador de asignacion: "copy and swap".
// Se crea una copia profunda temporal y se intercambian los datos; al salir,
// el destructor de 'copia' libera lo que tenia antes este objeto.
Refugio& Refugio::operator=(const Refugio& otro) {
    if (this != &otro) {
        Refugio copia(otro);
        swap(animales, copia.animales);
        swap(cantidad, copia.cantidad);
        swap(capacidad, copia.capacidad);
        adoptantes = copia.adoptantes;
        solicitudes = copia.solicitudes;
        historial = copia.historial;
    }
    return *this;
}

// Destructor: libera cada animal y luego el arreglo de punteros
Refugio::~Refugio() {
    for (int i = 0; i < cantidad; i++) {
        delete animales[i];      // LIBERA: cada Perro/Gato (destructor virtual)
    }
    delete[] animales;           // LIBERA: el arreglo de punteros
    animales = nullptr;
}

// ---------------------------------------------------------------------------
// Animales
// ---------------------------------------------------------------------------

void Refugio::agregarAnimal(const Animal& animal) {
    if ((*this)(animal.getId()) != nullptr) {
        throw IdRepetidoException(animal.getId());
    }

    // Si la coleccion esta llena, duplicar la capacidad
    if (cantidad == capacidad) {
        int nuevaCapacidad = capacidad * 2;
        Animal** nuevosAnimales = new Animal*[nuevaCapacidad]();
        for (int i = 0; i < cantidad; i++) {
            nuevosAnimales[i] = animales[i];   // se pasan los punteros
        }
        delete[] animales;                     // libera solo el arreglo viejo
        animales = nuevosAnimales;
        capacidad = nuevaCapacidad;
    }

    // Agregar el nuevo animal usando aritmetica de punteros
    *(animales + cantidad) = animal.clone();
    cantidad++;
}

// Recorrido con ARITMETICA DE PUNTEROS y POLIMORFISMO:
// (*p)->mostrarInfo() llama a la version de Perro o de Gato segun el tipo real.
void Refugio::mostrarAnimales() const {
    cout << "--- ANIMALES DEL REFUGIO ---" << endl;
    if (cantidad == 0) {
        cout << "No hay animales registrados." << endl;
        return;
    }
    for (Animal** p = animales; p < animales + cantidad; ++p) {
        (*p)->mostrarInfo();
    }
}

void Refugio::mostrardisponibles() const {
    cout << "--- ANIMALES DISPONIBLES ---" << endl;
    int mostrados = 0;
    for (int i = 0; i < cantidad; i++) {
        if (!(*animales[i])) {   // operador ! : true si NO esta disponible
            continue;
        }
        animales[i]->mostrarInfo();
        mostrados++;
    }
    if (mostrados == 0) {
        cout << "No hay animales disponibles." << endl;
    }
}

int Refugio::getCantidadAnimales() const {
    return cantidad;
}

Animal& Refugio::buscarAnimal(int id) {
    Animal* animal = (*this)(id);
    if (animal == nullptr) {
        throw NoEncontradoException("un animal", id);
    }
    return *animal;
}

// ---------------------------------------------------------------------------
// Operadores sobrecargados
// ---------------------------------------------------------------------------

// [] acceso por posicion
Animal& Refugio::operator[](int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw IndiceInvalidoException(indice);
    }
    return *animales[indice];
}

const Animal& Refugio::operator[](int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw IndiceInvalidoException(indice);
    }
    return *animales[indice];
}

// () busqueda por ID
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

// ---------------------------------------------------------------------------
// Adoptantes (Collection<Adoptante>: se recorre con indice)
// ---------------------------------------------------------------------------

void Refugio::agregarAdoptante(const Adoptante& adoptante) {
    if (buscarAdoptante(adoptante.getId()) != nullptr) {
        throw IdRepetidoException(adoptante.getId());
    }
    adoptantes.agregar(adoptante);
}

Adoptante* Refugio::buscarAdoptante(int id) {
    for (int i = 0; i < adoptantes.cantidad(); i++) {
        if (adoptantes[i].getId() == id) {
            return &adoptantes[i];
        }
    }
    return nullptr;
}

void Refugio::mostrarAdoptantes() const {
    cout << "--- ADOPTANTES ---" << endl;
    if (adoptantes.vacia()) {
        cout << "No hay adoptantes registrados." << endl;
        return;
    }
    for (int i = 0; i < adoptantes.cantidad(); i++) {
        adoptantes[i].mostrarInfo();
    }
}

// ---------------------------------------------------------------------------
// Solicitudes de adopcion
// ---------------------------------------------------------------------------

SolicitudAdopcion& Refugio::buscarSolicitud(int idSolicitud) {
    for (SolicitudAdopcion& s : solicitudes) {
        if (s.getIdSolicitud() == idSolicitud) {
            return s;
        }
    }
    throw NoEncontradoException("una solicitud", idSolicitud);
}

void Refugio::crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal) {
    Adoptante* adoptante = buscarAdoptante(idAdoptante);
    if (adoptante == nullptr) {
        throw NoEncontradoException("un adoptante", idAdoptante);
    }
    Animal& animal = buscarAnimal(idAnimal);          // puede lanzar NoEncontrado
    if (!animal) {                                    // operador ! : no disponible
        throw AnimalNoDisponibleException(idAnimal);
    }

    solicitudes.emplace_back(idSolicitud, *adoptante, animal, "Pendiente");
    animal.setDisponible(false);   // queda reservado mientras la solicitud esta pendiente
    historial.agregar("Solicitud " + to_string(idSolicitud) + " creada: " +
                      adoptante->getNombre() + " pide adoptar a " + animal.getNombre() + ".");
}

void Refugio::confirmarSolicitud(int idSolicitud) {
    SolicitudAdopcion& s = buscarSolicitud(idSolicitud);
    if (s.getEstado() != "Pendiente") {
        throw OperacionInvalidaException("la solicitud " + to_string(idSolicitud) +
                                         " esta en estado '" + s.getEstado() + "'");
    }
    s.setEstado("Confirmada");
    Animal* animal = (*this)(s.getIdAnimal());
    if (animal != nullptr) {
        historial.agregar(animal->getNombre() + " fue adoptado (solicitud " +
                          to_string(idSolicitud) + ").");
    }
}

void Refugio::cancelarSolicitud(int idSolicitud) {
    SolicitudAdopcion& s = buscarSolicitud(idSolicitud);
    if (s.getEstado() != "Pendiente") {
        throw OperacionInvalidaException("la solicitud " + to_string(idSolicitud) +
                                         " esta en estado '" + s.getEstado() + "'");
    }
    s.setEstado("Cancelada");
    Animal* animal = (*this)(s.getIdAnimal());
    if (animal != nullptr) {
        animal->setDisponible(true);
        historial.agregar("Solicitud " + to_string(idSolicitud) + " cancelada: " +
                          animal->getNombre() + " vuelve a estar disponible.");
    }
}

void Refugio::devolverAnimal(int idAnimal) {
    Animal& animal = buscarAnimal(idAnimal);   // puede lanzar NoEncontrado

    for (SolicitudAdopcion& s : solicitudes) {
        if (s.getIdAnimal() == idAnimal && s.getEstado() == "Confirmada") {
            s.setEstado("Devuelta");
            animal.setDisponible(true);
            historial.agregar(animal.getNombre() + " fue devuelto al refugio.");
            return;
        }
    }
    throw OperacionInvalidaException("el animal " + to_string(idAnimal) +
                                     " no tiene una adopcion confirmada");
}

void Refugio::mostrarSolicitudes() const {
    cout << "--- SOLICITUDES ---" << endl;
    if (solicitudes.empty()) {
        cout << "No hay solicitudes registradas." << endl;
        return;
    }
    for (const SolicitudAdopcion& solicitud : solicitudes) {
        solicitud.mostrarSolicitud();
    }
}

void Refugio::mostrarHistorial() const {
    cout << "--- HISTORIAL ---" << endl;
    if (historial.vacia()) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    for (int i = 0; i < historial.cantidad(); i++) {
        cout << "- " << historial[i] << endl;
    }
}