#include "lector_lectura_base.h"


void Lector_lectura_base::solicitar_datos_comunes(string* linea, Lista<Escritor*>& lista){

    cout << "Ingrese el titulo: ";
    getline(cin, linea[1]);

    cout << "Ingrese el tiempo de lectura: ";
    getline(cin, linea[2]);

    cout << "Ingrese el año de publicación: ";
    getline(cin, linea[3]);

    cout << endl;
    cout << "El listado de autores disponibles es el siguiente: " << endl;
    int cantidad_escritores = lista.obtener_cantidad();
    for (int i = 1; i <= cantidad_escritores; i++)
        cout << "Escritor " << i << ": " << lista.buscar(i)->obtener_nombre() << endl;
    cout << "Ingrese el numero del autor: ";
    string aux;
    getline(cin, aux);
    linea[5] = "(" + aux + ")";
}


