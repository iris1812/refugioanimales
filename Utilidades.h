#ifndef UTILIDADES_H
#define UTILIDADES_H
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
        if (cin.eof()) {
            throw EntradaInvalidaException();
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw EntradaInvalidaException();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

#endif