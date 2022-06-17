#ifndef _LECTOR_LECTURA_BASE_H_
#define _LECTOR_LECTURA_BASE_H_

#include "lista.h"
#include "escritor.h"
#include "lectura.h"

class Lector_lectura_base{
protected:

    //Pre: - 
    //Post: Metodo virtual para cargar datos 
    virtual Lectura* cargar_datos(string* linea, Lista<Escritor*>& lista) = 0;

    //Pre: - 
    //Post: 
    virtual Lectura* cargar_datos(Lista<Escritor*>& lista) = 0;

    //Pre:
    //Post: Ingreso por consola de los datos para cargar a la lista
    void solicitar_datos_comunes(string* linea, Lista<Escritor*>& lista);
};

#endif
