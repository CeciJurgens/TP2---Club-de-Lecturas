#ifndef COLA_H_
#define COLA_H_

#include "nodo.h"

template <class Tipo_Dato>
class Cola{
    private:
        Nodo<Tipo_Dato>* primero;
        Nodo<Tipo_Dato>* ultimo;
        
    public:
        
        //Construye una cola vacia.
        Cola();
        
        //Agrega un elemento al final de la cola.
        void encolar(Tipo_Dato  dato);
        
        //Elimina el pŕimer elemento de la cola.
        void desencolar();

        //Devuelve el dato consultado.
        Tipo_Dato buscar();
        
        //Devuelve true si la cola esta vacia.
        bool esta_vacia();
       
        ~Cola();
};

template <class Tipo_Dato>
Cola<Tipo_Dato>::Cola(){
    this->primero = nullptr;
    this->ultimo = nullptr;
}

template <class Tipo_Dato>
void Cola<Tipo_Dato>::encolar(Tipo_Dato dato){
    Nodo<Tipo_Dato>* nuevo = new Nodo<Tipo_Dato>(dato);
    if(primero){
        ultimo->cambiar_siguiente(nuevo);
    } else {
        primero = nuevo;
    }
    ultimo = nuevo;
}

template <class Tipo_Dato>
void Cola<Tipo_Dato>::desencolar(){
    Nodo<Tipo_Dato>* borrar = primero;
    primero = primero->obtener_siguiente();

    if (!primero)
        ultimo = nullptr;
    
    delete borrar; 
}

template <class Tipo_Dato>
Tipo_Dato Cola<Tipo_Dato>::buscar(){
    return primero->obtener_dato();
}

template <class Tipo_Dato>
bool Cola<Tipo_Dato>::esta_vacia(){
    return (ultimo == nullptr || primero == nullptr);
}

template <class Tipo_Dato>
Cola<Tipo_Dato>::~Cola(){
    while(!esta_vacia()){
        desencolar();
    }
}

#endif /* _COLA_H_ */
