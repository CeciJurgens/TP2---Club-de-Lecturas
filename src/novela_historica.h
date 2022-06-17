#ifndef _NOVELA_HISTORICA_H_
#define _NOVELA_HISTORICA_H_

#include "novela.h"

using namespace std;

class Novela_historica: public Novela
{
private:
    char* tema;
public:

    //Pre: - 
    //Post: Actualiza el genero historica con el argumento pasado
    void setear_genero();
    
    //Pre: Recibe un string valido
    //Post: Actualiza el tema con el argumento pasado
    void setear_tema(string tema);
    
    //Pre: -
    //Post: Muestra por pantalla los datos de la novela
    void mostrar();
    
    //Pre:
    //Post: Muestra por pantalla el genero de la novela
    void mostrar_novela(int genero);
    
    //Pre:
    //Post: Destructor
    ~Novela_historica();
};

#endif