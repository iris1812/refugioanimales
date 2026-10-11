#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;
class Animal {
private:
    int id;
    string nombre;
    int edad;
    string estadoSalud;      // ej: "Sano", "En tratamiento"
    bool disponibleAdopcion; // true = se puede adoptar, false = no
    static int instanciasVivas;
public:
    Animal();
    Animal(int id, string nombre, int edad, string estadoSalud);
    Animal(const Animal &otro);
    virtual ~Animal();
    int getId() const;
    string getNombre() const;
    int getEdad() const;
    string getEstadoSalud() const;
    bool getDisponible() const;
    void setEstadoSalud(string nuevoEstado);
    void setDisponible(bool valor);
    virtual void mostrarInfo() const;
    virtual Animal* clone() const = 0;
    bool operator==(const Animal& otro) const;
    bool operator!() const;
    static int getInstanciasVivas();
};

#endif