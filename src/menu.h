#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "visual_menu.h"
#include "lector_lectura.h"
#include "lector_escritor.h"
#include "opciones_menu.h"
#include "lista.h"


using namespace std;

class Menu{
private:

    bool abierto;

    //Pre:
    //Post: Muestra por pantalla las opciones del menu
    void mostrar_opciones();
    
    //Pre: Recibe dos lista validas
    //Post: Muestra la opcion elegida
    void elegir_opcion(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas);
    
    //Pre:
    //Post: devuelve un entero por consola y se chequea si es valido
    int pedir_numero_por_consola();
    
    //Pre:
    //Post: Devuleve el menu al finalizar la opcion elegida
    void volver_menu();
    
public:

    //Pre:
    //Post: Constructor
    Menu();

    //Pre:
    //Post:
    int ejecutar(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas);
};

#endif