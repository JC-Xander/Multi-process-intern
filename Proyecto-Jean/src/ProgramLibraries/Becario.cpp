#include "Becario.h"
#include <unistd.h>
#include <iostream>

Becario::Becario() : ID(0), ID_Proceso(getpid()) {}

Becario::Becario(const int _ID) : ID(_ID), ID_Proceso(getpid()) {
}

int Becario::getID() const {
    return this->ID;
}

pid_t Becario::getID_Proceso() const {
    return this->ID_Proceso;
}

std::ostream& operator<<(std::ostream& os, const Becario& becario) {
    os << "Identificador: " << becario.getID() << " ; " << becario.getID_Proceso();
    return os;
}




