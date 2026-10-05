#include <iostream>
#include "Animal.h"

// Fijate la sintaxis: "Animal::Animal()" significa "el constructor por defecto, QUE PERTENECE a la clase Animal".
// El "::" se llama "operador de resolución de ámbito": conecta el nombre de la clase con el nombre de la función.

Animal::Animal() {
    // valores iniciales "por defecto"
    id = 0;
    nombre = "Sin nombre";
    edad = 0;
    estadoSalud = "Desconocido";
    disponibleAdopcion = true;
}

Animal::Animal(int idParam, string nombreParam, int edadParam, string estadoParam) {
    // Uso "Param" en el nombre para no confundir el parámetro
    // con el atributo de la clase que se llama igual.
    id = idParam;
    nombre = nombreParam;
    edad = edadParam;
    estadoSalud = estadoParam;
    disponibleAdopcion = true; // todo animal nuevo arranca disponible
}

Animal::Animal(const Animal &otro) {
    // Copiamos cada atributo del objeto "otro" hacia el objeto nuevo.
    // Como Animal no tiene punteros propios, esto es una "copia simple": alcanza con copiar valor por valor. (En Refugio va a ser distinto, porque ahí SÍ vamos a tener memoria dinámica.)
    id = otro.id;
    nombre = otro.nombre;
    edad = otro.edad;
    estadoSalud = otro.estadoSalud;
    disponibleAdopcion = otro.disponibleAdopcion;
}

Animal::~Animal() {
}

int Animal::getId() const { return id; }
string Animal::getNombre() const { return nombre; }
int Animal::getEdad() const { return edad; }
string Animal::getEstadoSalud() const { return estadoSalud; }
bool Animal::getDisponible() const { return disponibleAdopcion; }

void Animal::setEstadoSalud(string nuevoEstado) {
    estadoSalud = nuevoEstado;
}

void Animal::setDisponible(bool valor) {
    disponibleAdopcion = valor;
}

void Animal::mostrarInfo() const {
    cout << "ID: " << id
        << " Nombre: " << nombre
        << " Edad: " << edad
        << " Salud: " << estadoSalud
        << " Disponible: " << (disponibleAdopcion ? "Si" : "No")
        << endl;
}
bool Animal::operator==(const Animal& otro) const {
    return this->id == otro.id;
}

// Sobrecarga de ! : Devuelve true si el animal NO está disponible
bool Animal::operator!() const {
 