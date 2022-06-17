#ifndef _NOVELA_H_
#define _NOVELA_H_

#include <string.h>

#include "lectura.h"

using namespace std;

enum class Generos {
    COMEDIA,
    DRAMA,
    FICCION,
    HISTORICA,
    ROMANTICA,
    SUSPENSO,
    TERROR
};

const string generos[7] = {"COMEDIA", "DRAMA", "FICCION", "HISTORICA", "ROMANTICA", "SUSPENSO", "TERROR"};

class Novela: public Lectura
{
protected:
    Generos genero;
 
public:

    //Pre: Recibe un string genero
    //Post: Actualiza el genero con el argumento pasado
    virtual void setear_genero(string genero); 
    
    //Pre:
    //Post: Retorna el genero
    enum Generos obtener_genero();
    
    //Pre:
    //Post: Muestra por pantalla los datos de la novela
    void mostrar();
    
    //Pre:
    //Post: Muestra por pantalla el genero de la novela
    void mostrar_novela(int genero);
    
    //Pre:
    //Post: Destructor
    virtual ~Novela();
};


#endif