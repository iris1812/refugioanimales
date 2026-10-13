// Pruebas del sistema: miembro estatico de Collection<T>, copia profunda y liberacion de memoria.
// Tiene su propio main y se compila aparte del sistema (no forma parte del menu).
// Compilar desde la carpeta del proyecto:
//  g++ -I. Pruebas/pruebas.cpp refugio.cpp Animal.cpp Adoptante.cpp Gato.cpp Perro.cpp SolicitudAdopcion.cpp -o pruebas_exe
// ./pruebas_exe.exe

#include <iostream>
#include <string>
#include "refugio.h"
#include "Perro.h"
#include "Gato.h"
using namespace std;

int fallas = 0;

void verificar(const string& descripcion, bool ok) {
cout << (ok ? "  [OK]    " : "  [FALLA] ") << descripcion << endl;
if (!ok) {
        fallas++;
}
}

void mostrarContadores(const string& momento) {
        cout << momento << ": int = " << Collection<int>::obtenerCantidadColecciones()
        << ", string = " << Collection<string>::obtenerCantidadColecciones()
        << ", Adoptante = " << Collection<Adoptante>::obtenerCantidadColecciones() << endl;
}

bool contadoresIguales(int deInt, int deString, int deAdoptante) {
return Collection<int>::obtenerCantidadColecciones() == deInt &&
        Collection<string>::obtenerCantidadColecciones() == deString &&
        Collection<Adoptante>::obtenerCantidadColecciones() == deAdoptante;
}

void probarMiembroEstatico() {
cout << "MIEMBRO ESTATICO DE Collection<T>" << endl;
mostrarContadores("Antes de crear ninguna coleccion");
verificar("Los tres contadores estan en 0", contadoresIguales(0, 0, 0));

Refugio r1;
mostrarContadores("Despues de crear el Refugio r1");
verificar("Aumentan solo string y Adoptante", contadoresIguales(0, 1, 1));

Collection<int> a;
Collection<int> b;
mostrarContadores("Despues de crear dos Collection<int>");
verificar("Aumenta solo int", contadoresIguales(2, 1, 1));

Refugio r2(r1);
mostrarContadores("Despues de copiar r1 en r2");
verificar("Aumentan string y Adoptante (el constructor de copia tambien suma)",
contadoresIguales(2, 2, 2));
}

void probarCopiaProfundaYMemoria() {
cout << "\nCOPIA PROFUNDA Y LIBERACION DE MEMORIA" << endl;
int vivosAntes = Animal::getInstanciasVivas();
cout << "Animales vivos en memoria antes de la prueba: " << vivosAntes << endl;
{
Refugio original(2);
original.agregarAnimal(Perro(100, "Milo", 3, "Sano", "Mestizo", "Mediano"));
original.agregarAnimal(Gato(101, "Ellie", 2, "Sano", "Negro", true));
original.agregarAnimal(Perro(102, "Leyla", 5, "Sano", "Labrador", "Grande"));

Refugio copia(original);
copia[0].setEstadoSalud("En tratamiento");
copia.agregarAnimal(Gato(103, "Tom", 1, "Sano", "Gris", false));
cout << "\nOriginal:" << endl;
original.mostrarAnimales();
cout << "\nCopia (modificada):" << endl;
copia.mostrarAnimales();
cout << "\nDireccion de original[0]: " << &original[0] << endl;
cout << "Direccion de copia[0]:    " << &copia[0] << endl;
verificar("Las direcciones son distintas (no se comparten punteros)",
        &original[0] != &copia[0]);
verificar("La copia conserva el ID del animal (copia[0] tiene el ID 100)",
        copia[0].getId() == 100);
verificar("operator== compara por ID: original[0] == copia[0]",
        original[0] == copia[0]);
verificar("Cambiar la salud en la copia no cambia el original",
        original[0].getEstadoSalud() == "Sano");
verificar("Agregar a la copia no agrega al original",
        original.getCantidadAnimales() == 3 && copia.getCantidadAnimales() == 4);

Refugio asignado;
asignado = original;
asignado[1].setDisponible(false);
verificar("operator=: cambiar el asignado no cambia el original",
        original[1].getDisponible() && !asignado[1].getDisponible());

asignado = asignado;
verificar("Autoasignacion (a = a) no rompe el objeto",
        asignado.getCantidadAnimales() == 3);

cout << "Animales vivos dentro del bloque: " << Animal::getInstanciasVivas() << endl;
}

int vivosDespues = Animal::getInstanciasVivas();
cout << "Animales vivos despues de destruir los refugios: " << vivosDespues << endl;
verificar("Todos los animales creados en la prueba fueron liberados (sin fugas)",
        vivosAntes == vivosDespues);
}

int main() {
probarMiembroEstatico();
probarCopiaProfundaYMemoria();
cout << "\nVerificaciones con falla: " << fallas << endl;
return fallas == 0 ? 0 : 1;
}