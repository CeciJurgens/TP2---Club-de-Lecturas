#include "novela_historica.h"


void Novela_historica::setear_genero(){
    this->genero = Generos::HISTORICA;
}


void Novela_historica::setear_tema(string tema){
    const size_t tamanio = tema.length()+1;
    char* vector = new char[tamanio];
    for (size_t i = 0; i < tamanio; i++)
        vector[i] = tema[i];
    this->tema = vector;  
}


void Novela_historica::mostrar(){
    mostrar_datos_comunes();
    cout << "- Género correspondiente: " << generos[(int)this->genero] << endl;
    cout << "- Tema: " << tema << endl;
    cout << endl;
}


void Novela_historica::mostrar_novela(int genero){
    if((int)this->genero == genero)
        mostrar();
}

Novela_historica::~Novela_historica(){
    delete [] this->tema;
}