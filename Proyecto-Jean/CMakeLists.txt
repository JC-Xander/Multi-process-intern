cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MiProyecto)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir el directorio de encabezados
include_directories(include)

# Agregar el subdirectorio de la fuente
add_subdirectory(src)

# Especificar los archivos de salida
add_executable(BecarioRun src/Main.cpp)

# Vincular las bibliotecas con el ejecutable principal
target_link_libraries(BecarioRun Becario Jefe)
