#ifndef _LECTOR_LECTURA_H_
#define _LECTOR_LECTURA_H_

#include <fstream>

#include "lista.h"
#include "lector_cuento.h"
#include "lector_poema.h"
#include "lector_novela.h"
#include "lector_novela_historica.h"
#include "lectura.h"

const int MAXIMO_A_LEER = 8;
const int MINIMOS_PARAMETROS = 6;
const string NOVELA = "N";
const string CUENTO = "C";
const string POEMA = "P";


class Lector_lectura
{   
private: 

    //Pre: Recibe un vector linea valido. 
    //Post: Carga en Lectura los datos obtenidos del archivo
    Lectura* cargar_lectura(string* linea, Lista<Escritor*>& lista_escritores);

public:

    //Pre: Recibo un archivo valido
    //Post: Cargo a un vector linea los datos del archivo
    Lectura* leer_por_archivo(ifstream& archivo, Lista<Escritor*>& lista_escritores);

    //Pre: - 
    //Post: Cargo a un vector los datos leidos por consola.
    Lectura* leer_por_consola(Lista<Escritor*>& lista_escritores);
};

#endif