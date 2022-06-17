#include "novela.h"


void Novela::setear_genero(string genero){

    if(genero == generos[0])
        this->genero = Generos::COMEDIA;
    else if(genero == generos[1])
        this->genero = Generos::DRAMA;
    else if(genero == generos[2])
        this->genero = Generos::FICCION;
    else if(genero == generos[3])
        this->genero = Generos::HISTORICA;
    else if(genero == generos[4])
        this->genero = Generos::ROMANTICA;
    else if(genero == generos[5])
        this->genero = Generos::SUSPENSO;
    else
        this->genero = Generos::TERROR;
}

enum Generos Novela::obtener_genero(){
    return genero;
}

void Novela::mostrar(){
    mostrar_datos_comunes();
    cout << "- Género correspondiente: " << generos[(int)genero] << endl;
    cout << endl;
}

void Novela::mostrar_novela(int genero){
    if((int)this->genero == genero)
        mostrar();
}

Novela::~Novela(){
}