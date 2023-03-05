#include <iostream>
#include <string>

#include "Lista.hpp"
#include "Nodo.hpp"

Lista::Lista()
{
    inicializa();
}

int Lista::tamano()
{
    Nodo *temporal = h;

    if (!h)
    {
        return 0;
    }
    else
    {
        for (int i = 1; temporal; i++)
        {
            if (!temporal->siguiente)
            {
                return i;
            }
            temporal = temporal->siguiente;
        }
    }
}

void Lista::insertarInicio(Nodo *elemento)
{
    Nodo *temporal = h;

    if (h)
    {
        elemento->siguiente = temporal;
        temporal->anterior = elemento;
        elemento->anterior = nullptr;
        h = elemento;
    }
    else
    {
        h = elemento;
        t = elemento;
        elemento->siguiente = nullptr;
        elemento->anterior = nullptr;
    }
}

void Lista::insertarFinal(Nodo *elemento)
{
    Nodo *temporal = t;

    temporal->siguiente = elemento;
    elemento->anterior = temporal;
    elemento->siguiente = nullptr;
    t = elemento;
}

void Lista::insertar(Nodo *elemento, int posicion)
{
    Nodo *temporal = h;

    if (posicion < 1 || posicion > tamano() + 1)
    {
        std::cout << "\n\nPosicion incorrecta" << endl;
        return;
    }

    if (h)
    {
        if (posicion == 1)
        {
            Lista::insertarInicio(elemento);
            return;
        }
        else if (posicion == tamano() + 1)
        {
            Lista::insertarFinal(elemento);
            return;
        }

        int i = 1;

        while (i < posicion)
        {
            temporal = temporal->siguiente;
            i++;
        }

        elemento->siguiente = temporal;
        elemento->anterior = temporal->anterior;
        temporal->anterior->siguiente = elemento;
        temporal->anterior = elemento;
    }
    else
    {
        Lista::insertarInicio(elemento);
    }
}

void Lista::eliminar(string student)
{
    Nodo *temporal = h;
    bool found = false;
    int i = 1;

    if (h)
    {

        // Encontrar Alumno
        while (!found)
        {

            if (i > tamano())
            {
                std::cout << "\n\nAlumno no encontrado" << endl;
                return;
            }

            if (temporal->estudiante.nombre == student)
            {
                found = true;
            }
            else
            {
                temporal = temporal->siguiente;
                i++;
            }
        }

        std::cout << "\n\nAlumno eliminado" << endl;

        if (!temporal->siguiente && !temporal->anterior) // Eliminar Alumno en lista de un elemento
        {
            Lista::eliminarTodo();
            std::cout << "\n\nLista Vacia" << endl;
            return;
        }
        else if (temporal == h) // Eliminar Alumno en la primera posición
        {
            h = temporal->siguiente;
            temporal->siguiente->anterior = nullptr;
            return;
        }
        else if (temporal == t) // Eliminar Alumno en la última posición
        {
            t = temporal->anterior;
            temporal->anterior->siguiente = nullptr;
            return;
        }

        // Eliminar Alumno en una posición intermedia
        temporal->anterior->siguiente = temporal->anterior->siguiente->siguiente;
        temporal->siguiente->anterior = temporal->siguiente->anterior->anterior;
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
        return;
    }
}

void Lista::eliminarTodo()
{
    h = nullptr;
    t = nullptr;
}

void Lista::buscar(string student)
{
    Nodo *temporal = h;
    bool found = false;
    int i = 1;

    if (h)
    {
        while (!found)
        {
            if (i > tamano())
            {
                std::cout << "\n\nAlumno no encontrado" << endl;
                return;
            }

            if (temporal->estudiante.nombre == student)
            {
                found = true;
                std::cout << "\n\nNombre: " << temporal->estudiante.nombre << endl;
                std::cout << "Edad: " << temporal->estudiante.edad << endl;
                return;
            }
            else
            {
                temporal = temporal->siguiente;
                i++;
            }
        }
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
        return;
    }
}

void Lista::inicializa(){
    h = nullptr;
    t = nullptr;
}

bool Lista::vacia()
{
    if (!h)
    {
        std::cout << "\n\nLista vacia" << endl;
        return true;
    }
    std::cout<<"\n\nLista no vacia"<<endl;
    return false;
}    

void Lista::primero()
{
    if (h)
    {
        std::cout << "\n\nPrimer alumno de la lista" << endl;
        std::cout << "\nNombre: " << h->estudiante.nombre;
        std::cout << "\nEdad: " << h->estudiante.edad << endl;
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
    }
}

void Lista::ultimo()
{
    if (h)
    {
        std::cout << "\n\nUltimo alumno de la lista" << endl;
        std::cout << "\nNombre: " << t->estudiante.nombre;
        std::cout << "\nEdad: " << t->estudiante.edad << endl;
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
    }
}

void Lista::siguiente(string student)
{
    Nodo *temporal= h;
    bool found = false;
    int i = 1;

    if (h)
    {
        while (!found)
        {
            if (i > tamano())
            {
                std::cout << "\n\nAlumno no encontrado" << endl;
                return;
            }

            if(!temporal->siguiente){
                std::cout << "\n\nNo hay un alumno siguiente a este" << endl;
                return;
            }

            if (temporal->estudiante.nombre == student)
            {
                found = true;
                std::cout << "\n\nAlumno siguiente:" << endl;
                std::cout << "\nNombre: " << temporal->siguiente->estudiante.nombre << endl;
                std::cout << "Edad: " << temporal->siguiente->estudiante.edad << endl;
                return;
            }
            else
            {
                temporal = temporal->siguiente;
                i++;
            }
        }
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
        return;
    }
}

void Lista::anterior(string student)
{
    Nodo *temporal= t;
    bool found = false;
    int i = 1;

    if (h)
    {
        while (!found)
        {
            if (i > tamano())
            {
                std::cout << "\n\nAlumno no encontrado" << endl;
                return;
            }

            if(!temporal->anterior){
                std::cout << "\n\nNo hay un alumno anterior a este" << endl;
                return;
            }

            if (temporal->estudiante.nombre == student)
            {
                found = true;
                std::cout << "\n\nAlumno anterior:" << endl;
                std::cout << "\nNombre: " << temporal->anterior->estudiante.nombre << endl;
                std::cout << "Edad: " << temporal->anterior->estudiante.edad << endl;
                return;
            }
            else
            {
                temporal = temporal->anterior;
                i++;
            }
        }
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
        return;
    }
}

void Lista::mostrarTodo()
{
    Nodo *temporal = h;

    std::cout << "\n\nLista Alumnos" << endl;

    if (h)
    {
        do
        {
            std::cout << "\n\nNombre: " << temporal->estudiante.nombre << endl;
            std::cout << "Edad: " << temporal->estudiante.edad << endl;

            temporal = temporal->siguiente;

        } while (temporal);
    }
    else
    {
        std::cout << "\n\nLista vacia" << endl;
    }
}
