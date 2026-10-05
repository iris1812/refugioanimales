# refugioanimales

Proyecto de consola en C++ para gestionar un refugio de animales.

## Descripción
El programa usa programación orientada a objetos para modelar entidades del mundo real como animales, adoptantes y solicitudes de adopción. Se implementan clases como `Animal`, `Perro`, `Gato`, `Adoptante` y `SolicitudAdopcion`, con relaciones entre ellas para simular la gestión de un refugio.

## Requisitos
- C++ compiler instalado (por ejemplo, `g++`)
- Sistema operativo Windows, Linux o macOS
- Terminal o PowerShell

## Cómo ejecutar el programa

### 1. Abrir la terminal en la carpeta del proyecto
Ejemplo en Windows PowerShell:

```powershell
cd "C:\Users\Notebook\Documents\GitHub\refugioanimales"
```

### 2. Compilar el proyecto
Ejecuta este comando:

```powershell
g++ main.cpp menu.cpp refugio.cpp Animal.cpp Adoptante.cpp Gato.cpp Perro.cpp SolicitudAdopcion.cpp -o refugioanimales.exe
```

### 3. Ejecutar el programa
Luego corre:

```powershell
.\refugioanimales.exe
```

## Menú principal
Al iniciar, el programa muestra un menú con opciones para:
- registrar un animal
- listar animales
- registrar un adoptante
- buscar animal por ID
- gestionar una solicitud de adopción
- devolver un animal
- mostrar historial
- mostrar solicitudes
- salir del programa

## Nota
Este proyecto fue desarrollado como ejercicio de programación orientada a objetos y gestión de datos en C++.