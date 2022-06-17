#ifndef _ESCRITOR_H_
#define _ESCRITOR_H_

#include <iostream>
#include <string>

using namespace std;

const string AUTOR_ANONIMO = "ANONIMO";
const string DESCONOCIDA = "¿?";
const int DESCONOCIDO = -1;

class Escritor
{
private:
    string nombre_completo;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

public:

    //Pre: - 
    //Post: Constructor de la clase
    Escritor();

    //Pre: Recibo un string valido
    //Post: Actualiza el nombre completo con el argumento pasado
    void setear_nombre_completo(string nombre_completo);
    
    //Pre: Recibo un string valido
    //Post: Actualiza la nacionalidad con el argumento pasado
    void setear_nacionalidad(string nacionalidad);

    //Pre: Recibo un entero valido
    //Post: Actualiza el año de nacimiento con el argumento pasado 
    void setear_anio_nacimiento(string anio_nacimiento);

    //Pre: Recibo un entero valido
    //Post: Actualiza el año de fallecimiento con el argumento pasado
    void setear_anio_fallecimiento(string anio_fallecimiento);

    //Pre:
    //Post: Devuelvo el string  nombre completo
    string obtener_nombre();

    //Pre: Recibo datos validos
    //Post: Muestro por pantalla los datos del escritor
    void mostrar();

    //Pre:
    //Post: Destructor
    ~Escritor();
};


#endif