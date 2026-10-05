#ifndef UTILIDADES_H
#define UTILIDADES_H

// FASE 5: Funcion generica (template).
// leerDato<T> muestra un mensaje y lee un valor de CUALQUIER tipo desde cin.
// Si el usuario escribe algo que no corresponde al tipo (ej: una letra cuando
// se espera un int), limpia cin y lanza EntradaInvalidaException.
// Asi se evita el bucle infinito que pasaba antes con cin en estado de error.
//
// Se usa con dos tipos distintos en el programa:
//   leerDato<int>("ID: ")                    -> IDs, edades, opciones del menu
//   leerDato<char>("Es de interior (s/n): ") -> respuestas de una letra

#include <iostream>
#include <string>
#include <limits>
#include "Excepciones.h"
using namespace std;

template <typename T>
T leerDato(const string& mensaje) {
    T valor;
    cout << mensaje;
    if (!(cin >> valor)) {
        if (cin.eof()) {               // se terminó la entrada
            throw EntradaInvalidaException();
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw EntradaInvalidaException();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta el resto de la línea
    return valor;
}

#endif