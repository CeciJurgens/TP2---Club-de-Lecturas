#ifndef _CUENTO_H_
#define _CUENTO_H_

#include "lectura.h"

using namespace std;

class Cuento: public Lectura
{
private:
    string libro;    
public:

    //Pre: Recibe titulo del libro 
    //Post: Actualiza el titulo del libro con el argumento pasado
    void setear_libro(string libro);

    //Pre: Recibo un dato valido
    //Post: Muestro por pantalla los datos del cuento
    void mostrar();

    //Pre:-
    //Post: -
    void mostrar_novela(int genero);

    //Pre:
    //Post: Destructor
    ~Cuento();
};

#endif