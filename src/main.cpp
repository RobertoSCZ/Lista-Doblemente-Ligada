#include <iostream>

#include <string>

using namespace std;

#include "Lista.hpp"
#include "Nodo.hpp"
#include "Alumno.hpp"

int main()
{

    Lista *lista = new Lista();

    int continuar = 1;
    int opcion;

    string nombre;
    int edad, posicion;

    while (continuar == 1)
    {
        cout << "\n\n**************************************" << endl;
        cout << "**** Programa Lista Doble Alumnos ****" << endl;
        cout << "**************************************" << endl;
        cout << "\n1.Insertar" << endl;
        cout << "\n2.Eliminar" << endl;
        cout << "\n3.Eliminar Todo" << endl;
        cout << "\n4.Buscar" << endl;
        cout << "\n5.Inicializa" << endl;
        cout << "\n6.Vacia" << endl;
        cout << "\n7.Primero" << endl;
        cout << "\n8.Ultimo" << endl;
        cout << "\n9.Tamano" << endl;
        cout << "\n10.Siguiente" << endl;
        cout << "\n11.Anterior" << endl;
        cout << "\n12.Mostrar todo" << endl;

        cout << "\n\nEleccion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "\n\nNombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "\nEdad: ";
            cin >> edad;
            cout << "\nPosicion: ";
            cin >> posicion;

            Alumno *student = new Alumno(nombre, edad);
            Nodo *node = new Nodo(*student);
            lista->insertar(node, posicion);
        }
        break;

        case 2:
        {
            cout << "\n\nNombre: ";
            cin.ignore();
            getline(cin, nombre);
            lista->eliminar(nombre);
        }
        break;

        case 3:
        {
            lista->eliminarTodo();
            cout << "\n\nLista Eliminada" << endl;
        }
        break;

        case 4:
        {
            cout << "\n\nNombre: ";
            cin.ignore();
            getline(cin, nombre);

            lista->buscar(nombre);
        }
        break;

        case 5:
        {
            lista->inicializa();
            cout << "\n\nLista Inicializada" << endl;
        }
        break;

        case 6:
        {
            lista->vacia();
        }
        break;

        case 7:
        {
            lista->primero();
        }
        break;

        case 8:
        {
            lista->ultimo();
        }
        break;

        case 9:
        {
            cout << "\n\nLa longitud de la lista es: " << lista->tamano() << endl;
        }
        break;

        case 10:
        {
            string nombre;

            cout << "\n\nAlumno siguiente a : ";
            cin.ignore();
            getline(cin, nombre);

            lista->siguiente(nombre);
        }
        break;

        case 11:
        {
            string nombre;

            cout << "\n\nAlumno anterior a: ";
            cin.ignore();
            getline(cin, nombre);

            lista->anterior(nombre);
        }
        break;

        case 12:
        {
            lista->mostrarTodo();
        }
        break;

        default:
            cout << "\n\nOpcion incorrecta" << endl;
        }

        cout << "\n\n\nContinuar 1/0 : ";
        cin >> continuar;
    }

    return 0;
}
