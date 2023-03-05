#include "Alumno.hpp"

#include <string>

using namespace std;

Alumno::Alumno(){
    this->nombre= "";
    this->edad= 0;
}

Alumno::Alumno(string nombre, int edad)
{
    this->nombre= nombre;
    this->edad = edad;
}
