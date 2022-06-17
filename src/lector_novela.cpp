#include "lector_novela.h"


Lectura* Lector_novela::cargar_datos(string* linea, Lista<Escritor*>& lista){
    if(linea[4] == HISTORICA)
        return nullptr;
    
    Novela* novela = new Novela;

    novela->setear_titulo(linea[1]);
    novela->setear_tiempo_lectura(linea[2]);
    novela->setear_anio_publicacion(linea[3]);
    novela->setear_genero(linea[4]);
    novela->setear_autor(linea[5], lista);

    return novela;    
}

Lectura* Lector_novela::cargar_datos(Lista<Escritor*>& lista){
    string linea[7];

    cout << "Generos disponibles:" << endl;
    cout << "DRAMA - COMEDIA - FICCION - HISTORICA - ROMANTICA - SUSPENSO - TERROR" << endl;

    cout << "Ingrese el genero: ";
    getline(cin, linea[4]);
    
    
    if(linea[4] == HISTORICA)
        return nullptr;
    
    solicitar_datos_comunes(linea, lista);
    
    return cargar_datos(linea, lista);

}