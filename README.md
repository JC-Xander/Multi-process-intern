```
██████╗░███████╗░█████╗░░█████╗░██████╗░██╗░█████╗░░██████╗
██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██║██╔══██╗██╔════╝
██████╦╝█████╗░░██║░░╚═╝███████║██████╔╝██║██║░░██║╚█████╗░
██╔══██╗██╔══╝░░██║░░██╗██╔══██║██╔══██╗██║██║░░██║░╚═══██╗
██████╦╝███████╗╚█████╔╝██║░░██║██║░░██║██║╚█████╔╝██████╔╝
╚═════╝░╚══════╝░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░╚════╝░╚═════╝░
```

@author: JC-Xander<br>
@version: 1.0.0<br>
@since:  2024/08/04

## Documentación

### Proyecto-Jean
#### Copilacion
Para copilarlo utilizo el programe `CMake` el cual debe estar previamente instalado.
- Instalación CMake
    - Actualiza lista de paquetes (Opcional)
    ```sh
        sudo apt update
    ``` 
    - Instalación
    ```sh
        sudo apt install cmake
    ```
    podemos verificar si la instalación se realizo opteniendo la verción del CMake intalado con el comnando: `cmake --version`

- __Ejecución:__<br>
    Para ejecutar CMake debemos crear un archivo CMakeLists.txt el cual debera contener el como se conectan la distintas clases, libreria y archivos del programa, pero no te preocupes por ello ya que incluyo los archivos CMakeLists en el proyectos vinculando las clases creadas.

    __Nota__ En caso de crear una nueva clase deberas añadirlo a los archivos CMakeList.

    Dentro del proyecto vamos a la carpeta build y ejecutamos el comando `cmake ..` los dos puntos indica que buscar los archivos CMakeLists.txt en la carpeta anterios

    Luego ejecutamos `make` y esto nos crear el binario del proyecto con el nombre de **BecariosRun** y los ejcutamos con  `./BecariosRun`


