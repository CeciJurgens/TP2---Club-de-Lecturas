#include "lector_novela_historica.h"


Lectura* Lector_novela_historica::cargar_datos(string* linea, Lista<Escritor*>& lista){
    
    Novela_historica* novela_historica = new Novela_historica;

    novela_historica->setear_titulo(linea[1]);
    novela_historica->setear_tiempo_lectura(linea[2]);
    novela_historica->setear_anio_publicacion(linea[3]);
    novela_historica->setear_genero();
    novela_historica->setear_tema(linea[5]);
    novela_historica->setear_autor(linea[6], lista);

    return novela_historica;
}


Lectura* Lector_novela_historica::cargar_datos(Lista<Escritor*>& lista){
    string linea[7];

    solicitar_datos_comunes(linea, lista);
    linea[6] = linea[5];

    cout << "Ingrese el tema: ";
    getline(cin, linea[5]);
    
    return cargar_datos(linea, lista);
}