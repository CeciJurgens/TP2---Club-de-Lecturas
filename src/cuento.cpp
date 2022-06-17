#include "cuento.h"

void Cuento::setear_libro(string libro){
    this->libro = libro;
}

void Cuento::mostrar(){
    mostrar_datos_comunes();
    cout << "- Título del libro: " << libro << endl;
    cout << endl;
}

void Cuento::mostrar_novela(int genero){
}

Cuento::~Cuento(){
}