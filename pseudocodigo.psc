Algoritmo RefugioAnimales
	Definir opcion, subopcion Como Entero
	Repetir
		Escribir 'REFUGIO DE ANIMALES'
		Escribir '1. Registrar perro o gato'
		Escribir '2. Listar animales'
		Escribir '3. Registrar adoptante'
		Escribir '4. Buscar animal por ID'
		Escribir '5. Solicitud de adopcion'
		Escribir '6. Devolver animal'
		Escribir '7. Mostrar solicitudes e historial'
		Escribir '0. Salir'
		Escribir 'Ingrese una opcion:'
		Leer opcion
		Según opcion Hacer
			1:
				Escribir '===== REGISTRAR ANIMAL ====='
				Escribir '1. Perro'
				Escribir '2. Gato'
				Escribir '0. Volver'
				Escribir 'Ingrese una opcion:'
				Leer subopcion
				Según subopcion Hacer
					1:
						Escribir 'Selecciono registrar un perro'
					2:
						Escribir 'Selecciono registrar un gato'
					0:
						Escribir 'Volviendo al menu'
					De Otro Modo:
						Escribir 'Opcion invalida'
				FinSegún
			2:
				Escribir '===== LISTAR ANIMALES ====='
				Escribir '1. Listar todos'
				Escribir '2. Mostrar disponibles'
				Escribir '0. Volver'
				Escribir 'Ingrese una opcion:'
				Leer subopcion
				Según subopcion Hacer
					1:
						Escribir 'Listando todos los animales'
					2:
						Escribir 'Mostrando animales disponibles'
					0:
						Escribir 'Volviendo al menu'
					De Otro Modo:
						Escribir 'Opcion invalida'
				FinSegún
			3:
				Escribir '===== REGISTRAR ADOPTANTE ====='
				Escribir 'Ingrese los datos del adoptante'
			4:
				Escribir '===== BUSCAR ANIMAL ====='
				Escribir 'Ingrese el ID del animal'
			5:
				Escribir '===== SOLICITUD DE ADOPCION ====='
				Escribir '1. Crear solicitud'
				Escribir '2. Confirmar solicitud'
				Escribir '3. Cancelar solicitud'
				Escribir '0. Volver'
				Escribir 'Ingrese una opcion:'
				Leer subopcion
				Según subopcion Hacer
					1:
						Escribir 'Crear solicitud'
					2:
						Escribir 'Confirmar solicitud'
					3:
						Escribir 'Cancelar solicitud'
					0:
						Escribir 'Volviendo al menu'
					De Otro Modo:
						Escribir 'Opcion invalida'
				FinSegún
			6:
				Escribir '===== DEVOLVER ANIMAL ====='
				Escribir 'Ingrese el ID del animal'
			7:
				Escribir '===== SOLICITUDES E HISTORIAL ====='
				Escribir '1. Mostrar solicitudes'
				Escribir '2. Mostrar historial'
				Escribir '0. Volver'
				Escribir 'Ingrese una opcion:'
				Leer subopcion
				Según subopcion Hacer
					1:
						Escribir 'Mostrando solicitudes'
					2:
						Escribir 'Mostrando historial'
					0:
						Escribir 'Volviendo al menu'
					De Otro Modo:
						Escribir 'Opcion invalida'
				FinSegún
			0:
				Escribir 'Saliendo del sistema'
			De Otro Modo:
				Escribir 'Opcion invalida'
		FinSegún
	Hasta Que opcion=0
	Escribir 'Fin del programa'
FinAlgoritmo