#ifndef NODO_H_
#define NODO_H_

#include <iostream>

using namespace std;

template <class Tipo_dato>
class Nodo{

public:
    Tipo_dato dato;
    Nodo* siguiente;

    //Pre:
    //Post:
    Nodo(Tipo_dato dato);

    //Pre:
    //Post:
    void cambiar_siguiente(Nodo* n);

        //Pre:
    //Post:
    Tipo_dato obtener_dato();

        //Pre:
    //Post:
    Nodo* obtener_siguiente();
};

template <class Tipo_dato>
Nodo<Tipo_dato>::Nodo(Tipo_dato d){
    dato = d;
    siguiente = 0;
}

template <class Tipo_dato>
void Nodo<Tipo_dato>::cambiar_siguiente(Nodo<Tipo_dato>* n){
    siguiente = n;
}

template <class Tipo_dato>
Tipo_dato Nodo<Tipo_dato>::obtener_dato(){
    return dato;
}

template <class Tipo_dato>
Nodo<Tipo_dato> *Nodo<Tipo_dato>::obtener_siguiente(){
    return siguiente;
}
#endif