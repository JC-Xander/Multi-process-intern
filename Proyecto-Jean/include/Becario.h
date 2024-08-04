#ifndef BECARIO_H
#define BECARIO_H

#include <iostream>
#include <string>

class Becario {
private:
    int ID;
    pid_t ID_Proceso;

public:
    Becario();
    Becario(const int);
    pid_t getID_Proceso() const;
    int getID() const;

    // Sobrecarga del operador de inserción <<
};
std::ostream& operator<<(std::ostream& os, const Becario& becario);

#endif // BECARIO_H
