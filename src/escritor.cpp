#include "escritor.h"


Escritor::Escritor(){
    nombre_completo = AUTOR_ANONIMO;
    nacionalidad = DESCONOCIDA;
    anio_nacimiento = DESCONOCIDO;
    anio_fallecimiento = DESCONOCIDO;
}


void Escritor::setear_nombre_completo(string nombre_completo){
    this->nombre_completo = nombre_completo;
}


void Escritor::setear_nacionalidad(string nacionalidad){
    if(nacionalidad.empty())
        return;
    this->nacionalidad = nacionalidad;
}


void Escritor::setear_anio_nacimiento(string anio_nacimiento){
    if(anio_nacimiento.empty())
        return;
    this->anio_nacimiento = stoi(anio_nacimiento); //donde hago la verificacion del año?
}


void Escritor::setear_anio_fallecimiento(string anio_fallecimiento){
    if(anio_fallecimiento.empty())
        return;
    this->anio_fallecimiento = stoi(anio_fallecimiento);
}


string Escritor::obtener_nombre(){
    return nombre_completo;
    
}


void Escritor::mostrar(){

    cout << "- Nombre y apellido: " << nombre_completo << endl;
    
    if (nacionalidad == DESCONOCIDA)
        cout << "- Nacionalidad: Desconocida" << endl;
    else
        cout << "- Nacionalidad: " << nacionalidad << endl;
    
    if (anio_nacimiento == DESCONOCIDO)
        cout << "- Año de nacimiento: Desconocido" << endl;
    else
        cout << "- Año de nacimiento: " << anio_nacimiento << endl;
    
    if (anio_fallecimiento == DESCONOCIDO)
        cout << "- Año de fallecimiento: Desconocido" << endl;
    else
        cout << "- Año de fallecimiento: " << anio_fallecimiento << endl;

    cout << endl;
}


Escritor::~Escritor(){
    
}