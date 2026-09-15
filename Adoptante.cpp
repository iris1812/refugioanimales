#include <iostream>
#include "Adoptante.h"

Adoptante::Adoptante() {
    id = 0;
    nombre = "Sin nombre";
    contacto = "Sin contacto";
    tipoVivienda = "Sin especificar";
}

Adoptante::Adoptante(int idParam, string nombreParam, string contactoParam, string viviendaParam) {
    id = idParam;
    nombre = nombreParam;
    contacto = contactoParam;
    tipoVivienda = viviendaParam;
}

Adoptante::Adoptante(const Adoptante &otro) {
    id = otro.id;
    nombre = otro.nombre;
    contacto = otro.contacto;
    tipoVivienda = otro.tipoVivienda;
}

Adoptante::~Adoptante() {
    // Sin memoria dinámica propia todavía, nada que liberar.
}

int Adoptante::getId() const { return id; }
string Adoptante::getNombre() const { return nombre; }
string Adoptante::getContacto() const { return contacto; }
string Adoptante::getTipoVivienda() const { return tipoVivienda; }

void Adoptante::mostrarInfo() const {
    cout << "ID: " << id
        << " | Nombre: " << nombre
        << " | Contacto: " << contacto
        << " | Vivienda: " << tipoVivienda<< endl;
}