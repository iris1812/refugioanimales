#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include <exception>
#include <string>
using namespace std;

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
class EntradaInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Entrada invalida: el dato ingresado no tiene el formato esperado";
    }
};

#endif