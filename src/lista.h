#ifndef LISTA_H_ 
#define LISTA_H_

#include <iostream>

#include "nodo.h"

template <class Tipo_dato>

class Lista{

private:
    Nodo<Tipo_dato> *primero;
    int cantidad;

public:

    //Pre:
    //Post: Constructor
    Lista();

    //Pre: Recibe dato valido y posicion
    //Post: Inserta un dato en una posicion valida de la lista
    void insertar_elemento(Tipo_dato nuevo_dato, int posicion);
    
    //Pre: recibe un dato valido
    //Post: Inserta al fibnal de la lista
    void insertar_final(Tipo_dato nuevo_dato);
    
    //Pre: Recibe una posicion valida
    //Post: Elimina de esa posicion el dato de la lista
    void eliminar_elemento(int posicion);
    
    //Pre: Recibe una posicion valida
    //Post: devuelve el dato que se encuentra en esa posicion de la lista
    Tipo_dato buscar(int posicion);
    
    //Pre:
    //Post: Devuelve true si esta vacia la lista
    bool esta_vacia();
    
    //Pre:
    //Post: Obteiene la cantidad de elementos de la lista
    int obtener_cantidad();
    
    //Pre:
    //Post: Destructor
    ~Lista();
private:

    //Pre:
    //Post:
    Lista(const Lista<Tipo_dato>& lista);
    
    //Pre:
    //Post:
    Nodo<Tipo_dato>* obtener_nodo(int posicion);
};

template <class Tipo_dato>
int Lista<Tipo_dato>::obtener_cantidad(){
    return cantidad;
}

template <class Tipo_dato>
bool Lista<Tipo_dato>::esta_vacia(){
    return cantidad == 0;
}

template <class Tipo_dato>
Lista<Tipo_dato>::Lista(){
    primero = nullptr;
    cantidad = 0;
}

template <class Tipo_dato>
void Lista<Tipo_dato>::insertar_elemento(Tipo_dato nuevo_dato, int posicion){
    Nodo<Tipo_dato>* nuevo = new Nodo<Tipo_dato>(nuevo_dato);
    if (posicion == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<Tipo_dato>* anterior = obtener_nodo(posicion - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

template <class Tipo_dato>
void Lista<Tipo_dato>::eliminar_elemento(int posicion){
    Nodo<Tipo_dato>* borrar = primero;
    if (posicion == 1){
        primero = primero->obtener_siguiente();
    } else {
        Nodo<Tipo_dato>* anterior = obtener_nodo(posicion - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

template <class Tipo_dato>
Tipo_dato Lista<Tipo_dato>::buscar(int posicion){
    Nodo<Tipo_dato>* auxiliar = obtener_nodo(posicion);
    return auxiliar->obtener_dato();
}

template <class Tipo_dato>
Nodo<Tipo_dato>* Lista<Tipo_dato>::obtener_nodo(int posicion){
    Nodo<Tipo_dato>* auxiliar = primero;
    int contador = 1;
    while (contador < posicion){
        auxiliar = auxiliar->obtener_siguiente();
        contador++;
    }
    return auxiliar;
}

template <class Tipo_dato>
Lista<Tipo_dato>::~Lista(){
    while(!esta_vacia()){
        eliminar_elemento(1);
    }
}

template <class Tipo_dato>
void Lista<Tipo_dato>::insertar_final(Tipo_dato nuevo_dato){
    Nodo<Tipo_dato> *nuevo_nodo = new Nodo<Tipo_dato>(nuevo_dato);
    Nodo<Tipo_dato> *auxiliar = primero;

    if (!primero){
        primero = nuevo_nodo;
    } else {
        while (auxiliar->siguiente != nullptr){
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevo_nodo;
    }
    cantidad++;
}

#endif 