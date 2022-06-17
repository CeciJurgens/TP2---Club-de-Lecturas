#ifndef _LECTOR_ESCRITOR_H_
#define _LECTOR_ESCRITOR_H_

#include <fstream>

#include "escritor.h"

const int MAXIMO_LEIDO = 6;
const int PARAMETROS_MINIMOS = 2;

class Lector_escritor
{
private:

    //Pre: Recibe un vector linea valido. 
    //Post: Carga en Escritor los datos obtenidos del archivo
    Escritor* cargar_datos_escritor(string* linea);

public:

    //Pre: Recibo un archivo valido
    //Post: Cargo a un vector linea los datos del archivo
    Escritor* leer_por_archivo(ifstream& archivo);
    
    //Pre: - 
    //Post: Cargo a un vector los datos leidos por consola.
    Escritor* leer_por_consola();
};

#endif