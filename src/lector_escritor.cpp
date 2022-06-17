#include "lector_escritor.h"


Escritor* Lector_escritor::cargar_datos_escritor(string* linea){
    Escritor* escritor = new Escritor;
    
    escritor->setear_nombre_completo(linea[1]);
    escritor->setear_nacionalidad(linea[2]);
    escritor->setear_anio_nacimiento(linea[3]);
    escritor->setear_anio_fallecimiento(linea[4]);

    return escritor;
}


Escritor* Lector_escritor::leer_por_archivo(ifstream& archivo){
    
    string linea[MAXIMO_LEIDO];
    bool linea_leida = true;
    int cantidad_leidas = 0;
    
    while (cantidad_leidas < MAXIMO_LEIDO && !archivo.eof() && linea_leida){
        getline(archivo, linea[cantidad_leidas]);
        if (!linea[cantidad_leidas].empty())
            cantidad_leidas++;
        else
            linea_leida = false;
        
    }

    if(cantidad_leidas < PARAMETROS_MINIMOS || cantidad_leidas == MAXIMO_LEIDO)
        return nullptr;


    return cargar_datos_escritor(linea);
}


Escritor* Lector_escritor::leer_por_consola(){
    
    string linea[MAXIMO_LEIDO];
    getline(cin, linea[0]);
    
    cout << "Ingrese el nombre y apellido del autor: ";
    getline(cin, linea[1], '\n');
    while(linea[1].empty()){
        cout << "No ha ingresado un nombre. ¬_¬" << endl;
        cout << "Ingrese el nombre y apellido del autor: ";
        getline(cin, linea[1], '\n');
    }
    cout << endl;
 
    cout << "Nacionalidad (si no sabe, escriba '¿?' o presione ENTER): ";
    getline(cin, linea[2], '\n');
    cout << endl;

    cout << "Fecha de nacimiento (si no sabe, escriba -1 o presione ENTER): ";
    getline(cin, linea[3], '\n');
    cout << endl;

    cout << "Fecha de Fallecimiento (si no sabe, escriba -1 o presione ENTER): ";
    getline(cin, linea[4], '\n');
    cout << endl;

    return cargar_datos_escritor(linea);
}
