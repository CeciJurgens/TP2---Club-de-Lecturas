#ifndef _LECTURA_H_
#define _LECTURA_H_

#include "lista.h"
#include "escritor.h"

const string ANONIMO = "ANONIMO";
const int MENOR = -1;
const int MAYOR = 1;
const int IGUAL = 0;
const int DISTINTO = 1;

class Lectura
{
protected:
    string titulo;
    int tiempo_lectura;
    int anio_publicacion;
    Escritor* autor;

public:
    //Pre:Recibe un string valido
    //Post: Actualiza el titulo con el argumento pasado
    void setear_titulo(string titulo);
    
    //Pre: Recibo un string valido
    //Post: Actualiza el tiempo de lectura con el argumento pasado
    void setear_tiempo_lectura(string tiempo_lectura);
    
    //Pre: Recibo un string valido
    //Post:Actualiza el año de publicacion con el argumento pasado
    void setear_anio_publicacion(string anio_publicacion);
    
    //Pre: Recibe un string valido y una lista de escritores validos
    //Post:Actualiza el autot con el argumento pasado
    void setear_autor(string id_escritor, Lista<Escritor*>& lista_escritores);

    //Pre:
    //Post: Muestra por pantalla los datos comunes entre las clases hijas
    void mostrar_datos_comunes();

    //Pre:
    //Post: metodo virtual
    virtual void mostrar() = 0;

    //Pre:
    //Post:Retorna el titulo
    string obtener_titulo();
     
    //Pre:
    //Post: Retorna el año de publicacion
    int obtener_anio_publicacion();
    
    //Pre:
    //Post: Retorna el tiempo de lectura
    int obtener_tiempo_lectura();
    
    //Pre:
    //Post: Retorna el nombre del autor
    string obtener_nombre_autor();
    
    //Pre: Recibe un dato lectura valido
    //Post: Devuelve 1 si el año de publicacion es mayor, 0 si es igual o -1 si es menor
    int comparar(Lectura* lectura_a_comparar);
    
    //Pre: Recibe el dato de tiempo de lectura
    //Post: Devuelve 1 si el tiempo de lectura es mayor, 0 si es igual o -1 si es menor
    int comparar(int tiempo_lectura);
    
    //Pre:
    //Post:
    virtual void mostrar_novela(int genero) = 0;
    
    //Pre:
    //Post: Destructor
    virtual ~Lectura();
};

#endif
