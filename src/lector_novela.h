#ifndef _LECTOR_NOVELA_H_
#define _LECTOR_NOVELA_H_

#include "lector_lectura_base.h"
#include "novela.h"

const string HISTORICA = "HISTORICA";

class Lector_novela: public Lector_lectura_base
{
public:

    //Pre: Recibo un vector linea  con los datos del archivo
    //Post: Asigno los datos del archivo al dato Lectura
    Lectura* cargar_datos(string* linea, Lista<Escritor*>& lista);

    //Pre: 
    //Post: cargo los datos ingresados por consola a Lectura
    Lectura* cargar_datos(Lista<Escritor*>& lista);
};


#endif