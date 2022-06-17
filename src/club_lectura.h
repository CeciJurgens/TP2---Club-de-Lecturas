#ifndef _CLUB_LECTURA_H_
#define _CLUB_LECTURA_H_

#include <iostream>
#include <fstream>

#include "lista.h"
#include "lector_lectura.h"
#include "lector_escritor.h"
#include "menu.h"

using namespace std;

class Club_lectura
{
private:
    ifstream archivo_lecturas;
    ifstream archivo_escritores;
    Lista<Escritor*> lista_escritores;  
    Lista<Lectura*> lista_lecturas;

    //Pre: Recibe archivos validos
    //Post: Devuelve true si los archivos de escritores y lecturas estan abiertos
    bool archivos_abiertos();

    //Pre: Recibe las listas de lecturas y escritores.
    //Post: Devuelve true si las listas de escritores y lecturas no estan vacias
    bool listas_creadas();

    //Pre: Recibe un archivo valido de escritores
    //Post: Devuelve la lista de escritores
    void crear_lista_escritores();

    //Pre: Recibe un archivo valido de lecturas
    //Post: Devuelve la lista de lecturas
    void crear_lista_lecturas();

    //Pre: 
    //Post: devuelve true si no se pudieron abrir los archivos y las listas no se crearon
    bool hay_errores_al_inicializar();

    //Pre: Recibe el dato lectura que se quiere agregar a la lista y recibe lista_lectura
    //Post: Devuelve la posicion a la cual debe insertar en la lista de lecturas.
    int buscar_posicion(Lectura* lectura_a_agregar);

public:

    //Pre: - 
    //Post: constructor de club lectura
    Club_lectura(const string path_lecturas, const string path_escritores);

    //Pre: Las listas den estar cargadas
    //Post: Devuelve -1 si hay problemas para inicializar sino devuelve 0 si se ejecuta el menu.
    int cargar_menu();

    //Destructor
    ~Club_lectura();
};

#endif