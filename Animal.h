
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
    // "private" = solo funciones DE ESTA CLASE pueden tocar estos atributo directamente.
    int id;
    string nombre;
    int edad;
    string estadoSalud;      // ej: "Sano", "En tratamiento"
    bool disponibleAdopcion; // true = se puede adoptar, false = no

public:

    // 1) Constructor por defecto: se usa si escribís  Animal a;
    Animal();

    // 2) Constructor parametrizado: se usa si escribís
    //    Animal a(1, "Firulais", 3, "Sano");
    Animal(int id, string nombre, int edad, string estadoSalud);

    // 3) Constructor de copia: se usa si escribís
    //    Animal b(a);   (crea b copiando los datos de a)
    // Recibe una REFERENCIA CONSTANTE: "const Animal &otro" significa "te paso el objeto original sin copiarlo de más, y prometo no modificarlo".
    Animal(const Animal &otro);

    // --- Destructor ---
    // Se llama automáticamente cuando el objeto se destruye.
    // Por ahora Animal no tiene memoria dinámica propia, así que el destructor no necesita liberar nada especial todavía.
    virtual ~Animal();

    //(leer un atributo privado desde afuera)
    int getId() const;
    string getNombre() const;
    int getEdad() const;
    string getEstadoSalud() const;
    bool getDisponible() const;

    //(modificar un atributo privado desde afuera, con control) ---
    void setEstadoSalud(string nuevoEstado);
    void setDisponible(bool valor);

    // Función
    virtual void mostrarInfo() const;
    virtual Animal* clone() const = 0;
    // Sobrecarga del operador == para comparar por ID
    bool operator==(const Animal& otro) const;

    // Sobrecarga del operador unario ! para ver si NO está disponible
    bool operator!() const;
};

#endif