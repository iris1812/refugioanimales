#include <iostream>
#include "Animal.h"
int Animal::instanciasVivas = 0;
int Animal::getInstanciasVivas() { return instanciasVivas; }

Animal::Animal() {
    id = 0;
    nombre = "Sin nombre";
    edad = 0;
    estadoSalud = "Desconocido";
    disponibleAdopcion = true;
    instanciasVivas++;
}
Animal::Animal(int idParam, string nombreParam, int edadParam, string estadoParam) {
    id = idParam;
    nombre = nombreParam;
    edad = edadParam;
    estadoSalud = estadoParam;
    disponibleAdopcion = true;
    instanciasVivas++;
}
Animal::Animal(const Animal &otro) {
    id = otro.id;
    nombre = otro.nombre;
    edad = otro.edad;
    estadoSalud = otro.estadoSalud;
    disponibleAdopcion = otro.disponibleAdopcion;
    instanciasVivas++;
}
Animal::~Animal() {
    instanciasVivas--;
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
bool Animal::operator!() const {
    return !this->disponibleAdopcion; 
}