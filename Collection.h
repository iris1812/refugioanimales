#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <stdexcept>

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
            throw std::out_of_range("Indice fuera de rango en Collection");
        }

        return elementos[indice];
    }

    // Acceso para objetos const
    const T& operator[](int indice) const
    {
        if (indice < 0 || indice >= cantidad())
        {
            throw std::out_of_range("Indice fuera de rango en Collection");
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