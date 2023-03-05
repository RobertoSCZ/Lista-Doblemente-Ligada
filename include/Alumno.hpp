#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

class Alumno
{
    public:
        Alumno();
        Alumno(string, int);

        string nombre;
        int edad;
};

#endif // ALUMNO_H
