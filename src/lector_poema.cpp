#include "lector_poema.h"


Lectura* Lector_poema::cargar_datos(string* linea, Lista<Escritor*>& lista){
    Poema* poema = new Poema;

    poema->setear_titulo(linea[1]);
    poema->setear_tiempo_lectura(linea[2]);
    poema->setear_anio_publicacion(linea[3]);
    poema->setear_versos(linea[4]);
    poema->setear_autor(linea[5], lista);
    
    return poema;
}

Lectura* Lector_poema::cargar_datos(Lista<Escritor*>& lista){
    string linea[7];

    solicitar_datos_comunes(linea, lista);

    cout << "Ingrese la cantidad de versos: ";
    getline(cin, linea[4]);

    return cargar_datos(linea, lista);
}