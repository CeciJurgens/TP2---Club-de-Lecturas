#include "lectura.h"


void Lectura::setear_titulo(string titulo){
    this->titulo = titulo;
}


void Lectura::setear_tiempo_lectura(string tiempo_lectura){
    this->tiempo_lectura = stoi(tiempo_lectura);
}


void Lectura::setear_anio_publicacion(string anio_publicacion){
    this->anio_publicacion = stoi(anio_publicacion);
}


int Lectura::obtener_anio_publicacion(){
    return anio_publicacion;
}


string Lectura::obtener_titulo(){
    return titulo;
}


string Lectura::obtener_nombre_autor(){
    if(autor)
        return autor->obtener_nombre();
    return ANONIMO;
}


int Lectura::obtener_tiempo_lectura(){
    return tiempo_lectura;
}


void Lectura::setear_autor(string id_escritor, Lista<Escritor*>& lista_escritores){

    if(id_escritor == ANONIMO) {
        this->autor = nullptr;
        return;
    } 

    const char* id = id_escritor.c_str();
    int numero;
    sscanf(id, "(%i)", &numero);

    if (!lista_escritores.esta_vacia())
        this->autor = lista_escritores.buscar(numero);
}


int Lectura::comparar(Lectura* lectura_a_comparar){
    if(this->anio_publicacion < lectura_a_comparar->obtener_anio_publicacion())
        return MENOR;
    else if (this->anio_publicacion > lectura_a_comparar->obtener_anio_publicacion())
        return MAYOR;
    else
        return IGUAL;
}


int Lectura::comparar(int tiempo_lectura){
    if(this->tiempo_lectura < tiempo_lectura)
        return MENOR;
    else if (this->tiempo_lectura > tiempo_lectura)
        return MAYOR;
    else
        return IGUAL;
}


void Lectura::mostrar_datos_comunes(){
    cout << "- Título: " << titulo << endl;
    cout << "- Tiempo de lectura: " << tiempo_lectura << endl;
    cout << "- Año de publicación: " << anio_publicacion << endl;
    if(autor == nullptr)
        cout << "- Autor: ANONIMO" << endl;
    else 
        cout << "- Autor: " << autor->obtener_nombre() << endl;
}

Lectura::~Lectura(){    
}