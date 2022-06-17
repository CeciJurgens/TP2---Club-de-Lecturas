#include "poema.h"

void Poema::setear_versos(string versos){
    this->versos = stoi(versos);
}


void Poema::mostrar(){
    mostrar_datos_comunes();
    cout << "- Cantidad de versos: " << versos << endl;
    cout << endl;
}

void Poema::mostrar_novela(int genero){
}

Poema::~Poema(){    
}