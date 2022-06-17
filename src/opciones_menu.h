#ifndef _OPCIONES_MENU_H_
#define _OPCIONES_MENU_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "lector_lectura.h"
#include "lector_escritor.h"
#include "lista.h"
#include "cola.h"

class Opciones_menu{
private:
    Lista<Escritor*>* lista_escritores;
    Lista<Lectura*>* lista_lecturas;
    Cola<Lectura*> cola_lecturas;


    //Pre: Recibo un dato valido de lectura
    //Post: devuelve la posicion a insertar el elemento a la lista
    int buscar_posicion(Lectura* lectura_a_agregar);
    
    //Pre: Recibo un dato valido de lectura y una lista valida de lectura
    //Post: devuelve la posicion a insertar el elemento a la lista
    int buscar_posicion(Lectura* lectura_a_agregar, Lista<Lectura*>* lista);
    
    //Pre:
    //Post: Devuelve una cola con las lecturas ordenadas de menor a mayor en tiempo de lectura
    void armar_cola_lecturas();

public:

    //Pre:
    //Post: Constructor
    Opciones_menu(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas);
    
    //Pre: Lista valida de lectura
    //Post: Se agrega una lectura a la lista de lecturas
    void agregar_lectura();
    
    //Pre: Lista valida de lectura
    //Post: Elimina una lectura de la lista
    void quitar_lectura();  

    //Pre: Lista valida de escritor
    //Post: Agrega un escritor a la lista
    void agregar_escritor();  

    //Pre: Lista valida de escritor
    //Post: Cambia la fecha de fallecimiento del escritor 
    void cambiar_fecha_fallecimiento_escritor();  

    //Pre: Lista valida de escritor
    //Post: Muestra por pantalla la lista de escritores
    void listar_escritores();  

    //Pre: Lista valida de lectura
    //Post: Muestra por pantalla una lectura random de la lista
    void sortear_lecturas();  
    
    //Pre: Lista valida de lectura
    //Post: Muestra por pantalla la lista de lecturas
    void listar_lecturas();  
    
    //Pre: Lista valida de lectura
    //Post: Muestra por pantalla las lecturas en un determiando rango de año
    void listar_lecturas_por_anios(); 
    
    //Pre: Lista valida de lectura
    //Post: Muestra por pantalla las lecturas de determiando escritor
    void listar_lecturas_escritor(); 
    
    //Pre: Lista valida de lectura
    //Post: Muestra por pantalla las lecturas de un determinado genero
    void listar_novelas_genero();  // falta
    
    //Pre: Lista valida de lectura
    //Post: Devuelve una cola con las lecturas ordenadas de menor a mayor
    void proxima_lectura_a_leer(); 
    
    //Pre: - 
    //Post:Muestra por pantalla  la salida
    void salir_menu();
};

#endif