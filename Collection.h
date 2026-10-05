#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include "Excepciones.h"

// Cada instanciacion (Collection<int>, Collection<string>...) es una clase
// distinta generada por el compilador, por eso cada una tiene SU PROPIO
// contador cantidadColecciones.

template <typename T>
class Collection
{
private:
    std::vector<T> elementos;

    // Miembro estatico
    static int cantidadColecciones;

public:

    // Constructor
    Collection()
    {
        cantidadColecciones++;
    }

    // Constructor de copia: también es una colección nueva, así que suma
    Collection(const Collection& otra) : elementos(otra.elementos)
    {
        cantidadColecciones++;
    }

    Collection& operator=(const Collection& otra) = default;

    // Devuelve true si la colección no tiene elementos
    bool vacia() const
    {
        return elementos.empty();
    }

    // Agregar un elemento
    void agregar(const T& elemento)
    {
        elementos.push_back(elemento);
    }

    // Devuelve la cantidad de elementos
    int cantidad() const
    {
        return elementos.size();
    }

    // Acceso a los elementos
    T& operator[](int indice)
    {
        if (indice < 0 || indice >= cantidad())
        {
            throw IndiceInvalidoException(indice);
        }
        return elementos[indice];
    }

    // Acceso para objetos const
    const T& operator[](int indice) const
    {
        if (indice < 0 || indice >= cantidad())
        {
            throw IndiceInvalidoException(indice);
        }
        return elementos[indice];
    }

    // Obtener cantidad de colecciones creadas
    static int obtenerCantidadColecciones()
    {
        return cantidadColecciones;
    }
};

// Inicializacion del miembro estatico
template <typename T>
int Collection<T>::cantidadColecciones = 0;

#endif
