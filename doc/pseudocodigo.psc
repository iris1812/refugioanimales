Algoritmo RefugioAnimales
Definir opcion, subopcion Como Entero
Repetir
    Escribir '========================================'
    Escribir '       REFUGIO DE ANIMALES'
    Escribir '========================================'
    Escribir '1. Registrar perro o gato'
    Escribir '2. Listar animales'
    Escribir '3. Registrar adoptante'
    Escribir '4. Buscar animal por ID'
    Escribir '5. Gestionar solicitud de adopcion'
    Escribir '6. Devolver animal a disponible'
    Escribir '7. Mostrar historial'
    Escribir '8. Mostrar solicitudes'
    Escribir '9. Listar adoptantes'
    Escribir '0. Salir'
    Escribir 'Ingrese una opcion:'
    Leer opcion
    Segun opcion Hacer
        1:
            Escribir '===== REGISTRAR ANIMAL ====='
            Escribir '1. Registrar perro'
            Escribir '2. Registrar gato'
            Escribir '0. Volver'
            Escribir 'Ingrese una opcion:'
            Leer subopcion
            Segun subopcion Hacer
                1:
                    Escribir 'Selecciono registrar un perro'
                2:
                    Escribir 'Selecciono registrar un gato'
                0:
                    Escribir 'Volviendo al menu principal'
                De Otro Modo:
                    Escribir 'Opcion invalida'
            FinSegun
        2:
            Escribir '===== LISTAR ANIMALES ====='
            Escribir '1. Listar todos'
            Escribir '2. Mostrar disponibles'
            Escribir '3. Ver animal por posicion'
            Escribir '0. Volver'
            Escribir 'Ingrese una opcion:'
            Leer subopcion
            Segun subopcion Hacer
                1:
                    Escribir 'Listando todos los animales'
                2:
                    Escribir 'Mostrando animales disponibles'
                3:
                    Escribir 'Ingrese la posicion del animal'
                    Escribir 'Mostrando animal de la posicion seleccionada'
                0:
                    Escribir 'Volviendo al menu principal'
                De Otro Modo:
                    Escribir 'Opcion invalida'
            FinSegun
        3:
            Escribir '===== REGISTRAR ADOPTANTE ====='
            Escribir 'Ingrese los datos del adoptante'
            Escribir 'Adoptante registrado correctamente'
        4:
            Escribir '===== BUSCAR ANIMAL POR ID ====='
            Escribir 'Ingrese el ID del animal'
            Escribir 'Buscando animal'
            Escribir 'Mostrando informacion del animal'
        5:
            Escribir '===== GESTIONAR SOLICITUD DE ADOPCION ====='
            Escribir '1. Crear solicitud'
            Escribir '2. Confirmar solicitud'
            Escribir '3. Cancelar solicitud'
            Escribir '0. Volver'
            Escribir 'Ingrese una opcion:'
            Leer subopcion
            Segun subopcion Hacer
                1:
                    Escribir '===== CREAR SOLICITUD ====='
                    Escribir 'Ingrese ID del adoptante'
                    Escribir 'Ingrese ID del animal'
                    Escribir 'Crear solicitud de adopcion'
                2:
                    Escribir '===== CONFIRMAR SOLICITUD ====='
                    Escribir 'Mostrar solicitudes'
                    Escribir 'Ingrese numero de solicitud'
                    Escribir 'Confirmar solicitud de adopcion'
                3:
                    Escribir '===== CANCELAR SOLICITUD ====='
                    Escribir 'Mostrar solicitudes'
                    Escribir 'Ingrese numero de solicitud'
                    Escribir 'Cancelar solicitud'
                    Escribir 'El animal vuelve a estar disponible'
                0:
                    Escribir 'Volviendo al menu principal'
                De Otro Modo:
                    Escribir 'Opcion invalida'
            FinSegun
        6:
            Escribir '===== DEVOLVER ANIMAL ====='
            Escribir 'Ingrese el ID del animal'
            Escribir 'Buscar animal'
            Escribir 'Devolver animal'
            Escribir 'El animal vuelve a estar disponible'
        7:
            Escribir '===== MOSTRAR HISTORIAL ====='
            Escribir 'Mostrar historial de adopciones y devoluciones'
        8:
            Escribir '===== MOSTRAR SOLICITUDES ====='
            Escribir 'Mostrar todas las solicitudes de adopcion'
        9:
            Escribir '===== LISTAR ADOPTANTES ====='
            Escribir 'Mostrar todos los adoptantes registrados'
        0:
            Escribir 'Saliendo del sistema'
        De Otro Modo:
            Escribir 'Opcion invalida'
    FinSegun
Hasta Que opcion = 0
Escribir 'Fin del programa'
FinAlgoritmo