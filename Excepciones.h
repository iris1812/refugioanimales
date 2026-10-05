#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

// FASE 5: Excepciones personalizadas.
// Todas heredan de std::exception, asi un catch (const exception& e)
// tambien las puede atrapar. Cada una redefine what() para devolver su mensaje.

#include <exception>
#include <string>
using namespace std;

// Se lanza cuando se intenta registrar un animal o un adoptante con un ID que ya existe.
class IdRepetidoException : public exception {
private:
    string mensaje;
public:
    IdRepetidoException(int id)
        : mensaje("Ya existe un registro con el ID " + to_string(id)) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Se lanza cuando se accede a una posicion que no existe en una coleccion.
class IndiceInvalidoException : public exception {
private:
    string mensaje;
public:
    IndiceInvalidoException(int indice)
        : mensaje("Indice invalido: " + to_string(indice)) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Se lanza cuando se pide una adopcion de un animal que no esta disponible.
class AnimalNoDisponibleException : public exception {
private:
    string mensaje;
public:
    AnimalNoDisponibleException(int idAnimal)
        : mensaje("El animal con ID " + to_string(idAnimal) + " no esta disponible") {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Se lanza cuando se busca un animal, adoptante o solicitud que no existe.
class NoEncontradoException : public exception {
private:
    string mensaje;
public:
    NoEncontradoException(const string& que, int id)
        : mensaje("No se encontro " + que + " con ID " + to_string(id)) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
class OperacionInvalidaException : public exception {
private:
    string mensaje;
public:
    OperacionInvalidaException(const string& detalle)
        : mensaje("Operacion invalida: " + detalle) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
// Se lanza cuando el usuario escribe algo que no corresponde al tipo pedido
// (por ejemplo, una letra cuando se espera un numero).
class EntradaInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Entrada invalida: el dato ingresado no tiene el formato esperado";
    }
};

#endif