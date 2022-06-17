#include "lector_cuento.h"


Lectura* Lector_cuento::cargar_datos(string* linea, Lista<Escritor*>& lista){
    Cuento* cuento = new Cuento;

    cuento->setear_titulo(linea[1]);
    cuento->setear_tiempo_lectura(linea[2]);
    cuento->setear_anio_publicacion(linea[3]);
    cuento->setear_libro(linea[4]);
    cuento->setear_autor(linea[5], lista);
   
    return cuento;
}


Lectura* Lector_cuento::cargar_datos(Lista<Escritor*>& lista){
    string linea[7];

    solicitar_datos_comunes(linea, lista);

    cout << "Ingrese el titulo del libro: ";
    getline(cin, linea[4]);

    return cargar_datos(linea, lista);

}

