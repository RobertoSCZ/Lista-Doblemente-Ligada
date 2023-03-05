#ifndef NODO_H
#define NODO_H

#include "Alumno.hpp"

class Nodo
{
    public:
        Nodo();
        Nodo(Alumno);

        Nodo *siguiente;
        Nodo *anterior;
        Alumno estudiante;
};

#endif // NODO_H
