#include <iostream>
#include <exception>
#include "menu.h"
#include "Excepciones.h"
using namespace std;

int main() {
    int opcion = -1;  
    do {
        mostrarMenu();
        try {
            opcion = leerOpcion();
            switch (opcion) {
                case 1:
                    registrarAnimal();
                    break;
                case 2:
                    listarAnimales();
                    break;
                case 3:
                    registrarAdoptante();
                    break;
                case 4:
                    buscarAnimalPorId();
                    break;
                case 5:
                    gestionarSolicitud();
                    break;
                case 6:
                    devolverAnimal();
                    break;
                case 7:
                    mostrarHistorial();
                    break;
                case 8:
                    mostrarSolicitudes();
                    break;
                case 9:
                    listarAdoptantes();
                    break;
                case 0:
                    cout << "Saliendo del sistema" << endl;
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
        }
        catch (const IdRepetidoException& e) {
            cout << "Error - " << e.what() << endl;
        }
        catch (const AnimalNoDisponibleException& e) {
            cout << "Error -" << e.what() << endl;
        }
        catch (const IndiceInvalidoException& e) {
            cout << "Error -  " << e.what() << endl;
        }
        catch (const NoEncontradoException& e) {
            cout << "Error - " << e.what() << endl;
        }
        catch (const OperacionInvalidaException& e) {
            cout << "Error - " << e.what() << endl;
        }
        catch (const EntradaInvalidaException& e) {
            cout << "Error - " << e.what() << endl;
            opcion = -1;           
            if (cin.eof()) {       
                opcion = 0;
            }
        }
        catch (const exception& e) {  
            cout << "Error - " << e.what() << endl;
        }
    } while (opcion != 0);
    return 0;
}

