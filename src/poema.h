#ifndef _POEMA_H_
#define _POEMA_H_

#include "lectura.h"

class Poema: public Lectura {
private:
    int versos;
public:

    //Pre: Recibe un string valido
    //Post: Actualiza la cantidad de versos con el argumento pasado
    void setear_versos(string versos);
    
    //Pre:
    //Post: Muestra por pantalla los datos del poema
    void mostrar();
    
    //Pre:
    //Post:
    void mostrar_novela(int genero);
    
    //Pre:
    //Post: destructor
    ~Poema();
};


#endif