#include "Nodo.hpp"

#include "Alumno.hpp"


Nodo::Nodo(){
    
}

Nodo::Nodo(Alumno estudiante)
{
    this->siguiente= nullptr;
    this->anterior= nullptr;
    this->estudiante= estudiante;
}
