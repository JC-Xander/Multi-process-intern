#include "Jefe.h"


// Constructor
Jefe::Jefe() : Becario(), numGrupo(0) {}

Jefe::Jefe(const int _ID) : Becario(_ID), numGrupo(0) {}



// Agrega un nuevo personal a la memoria compartida
bool Jefe::AgregarPersonal() {
    // Aquí deberías implementar la lógica para agregar el becario a la memoria compartida
    // Asegúrate de manejar los límites del arreglo y la sincronización si es necesario
    return true; // Devuelve el resultado de la operación
}

// Obtiene el puntero al grupo de becarios
std::vector<Becario> Jefe::getGrupo() const {
    return this->Grupo;
}

// Obtiene el numero de integrantes del grupo
int Jefe::getNumGrupo() const {
    return this->numGrupo;
}

