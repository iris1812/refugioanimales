#include "menu.h"
int main() {
    int opcion;   // guardar la opción que elige
    do {
        mostrarMenu();
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
            case 0:
                // No hacemos nada acá: el "0" corta el do-while más abajo.
                break;
            default:
                break;
        }

    } while (opcion != 0); 

    return 0; 
}
