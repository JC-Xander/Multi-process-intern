#ifndef JEFE_H
#define JEFE_H

#include "Becario.h"
#include <iostream>
#include <vector> 

class Jefe : public Becario {
private:
    std::vector<Becario> Grupo;
    int numGrupo;

    key_t Clave;
    int ID_Memoria;

public:
    Jefe();
    Jefe(const int);

    bool AgregarPersonal();
    std::vector<Becario> getGrupo() const;
    int getNumGrupo() const;

};

#endif // JEFE_H
