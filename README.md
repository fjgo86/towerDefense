Servidor para el towerDefense

Instrucciones:

1) Abrir CMake (Actualmente la 3.5.2 genera el proyecto sin problema).

2) Última versión de SFML x64 (Actualmente 2.4.1) dentro de la carpeta src/include/ (incluida por defecto).

3) Actualizar src/CMakeLists.txt con la información de la librería (solo en caso de update), por ejemplo: set(SFML_ROOT "include/SFML-2.4.1").

4) Asignar la ruta de source code en el CMake a 'rutaProyecto/src', por ej: E:/Proyectos/tdServer/src.

   Asignar la ruta de build en el CMake a 'rutaProyecto/build', por ej: E:/Proyectos/tdServer/build.
   
5) Generar proyecto con compilador de 64bits.



Configuracion CMake:

1) Modificar la ruta de MYSQL_ROOT de ser necesario: set(MYSQL_ROOT "C:/Program Files/MySQL/Connector.C++ 1.1") #Ruta de MySQL.

2) Usar el siguiente comando desde la carpeta del repositorio: git update-index --assume-unchanged include/GitRevision.h

3) En caso de actualizar la librería de SFML, actualizar el nombre del directorio: set(SFML_ROOT "include/SFML-2.4.1") #Ruta de la librería SFML_(x64).