#ifndef COLLECTION_H
#define COLLECTION_H
#include <vector>
#include "Excepciones.h"
template <typename T>
class Collection
{
private:
    std::vector<T> elementos;
    static int cantidadColecciones;
public:
    Collection(){
        cantidadColecciones++;
    }
    Collection(const Collection& otra) : elementos(otra.elementos){
        cantidadColecciones++;
    }
    Collection& operator=(const Collection& otra) = default;
    bool vacia() const {
        return elementos.empty();
    }
    void agregar(const T& elemento) {
        elementos.push_back(elemento);
    }
    int cantidad() const {
        return elementos.size();
    }
    T& operator[](int indice) {
        if (indice < 0 || indice >= cantidad()){
            throw IndiceInvalidoException(indice);
        }
        return elementos[indice];
    }
    const T& operator[](int indice) const {
        if (indice < 0 || indice >= cantidad()) {
            throw IndiceInvalidoException(indice);
        }
        return elementos[indice];
    }

    static int obtenerCantidadColecciones() {
        return cantidadColecciones;
    }
};
template <typename T>
int Collection<T>::cantidadColecciones = 0;
#endif
