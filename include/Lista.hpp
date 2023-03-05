#ifndef LISTA_H
#define LISTA_H

#include "Nodo.hpp"
#include "Alumno.hpp"

#include <string>

using namespace std;

class Lista
{
    public:
        Lista();

        Nodo *elemento;
        Nodo *h, *t;

        void insertarInicio(Nodo*);
        void insertarFinal(Nodo*);
        void insertar(Nodo*, int);

        void eliminar(string);
        void eliminarTodo();

        void buscar(string);

        void inicializa();

        bool vacia();

        void primero();

        void ultimo();

        int tamano();

        void siguiente(string);

        void anterior(string);

        void mostrarTodo();

};

#endif // LISTA_H
