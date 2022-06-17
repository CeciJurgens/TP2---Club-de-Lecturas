#include <iostream>
#include <fstream>

#include "club_lectura.h"


Club_lectura::Club_lectura(const string path_lecturas, const string path_escritores) {
    archivo_lecturas = ifstream(path_lecturas);
    archivo_escritores = ifstream(path_escritores);
    crear_lista_escritores();
    crear_lista_lecturas();
}


bool Club_lectura::archivos_abiertos(){
    return archivo_lecturas.is_open() && archivo_escritores.is_open();
}


Club_lectura::~Club_lectura(){

    for(int i = 1; i <= lista_escritores.obtener_cantidad(); i++)
        delete lista_escritores.buscar(i);
    
    for(int i = 1; i <= lista_lecturas.obtener_cantidad(); i++)
        delete lista_lecturas.buscar(i);


    if(archivo_lecturas.is_open())
        archivo_lecturas.close();

    if (archivo_escritores.is_open())
        archivo_escritores.close();

}


bool Club_lectura::listas_creadas(){
    return !lista_escritores.esta_vacia() && !lista_lecturas.esta_vacia();
}


bool Club_lectura::hay_errores_al_inicializar(){
    if(!archivos_abiertos()){
        cout << "¡ERROR! (⌣́_⌣̀)" << endl; 
        cout << "No se pudieron abrir los archivos." << endl;
        return true;
    }

    if(!listas_creadas()){
        cout << "¡ERROR! (⌣́_⌣̀)" << endl; 
        cout << "Hay un problema con el formato de los archivos." << endl;
        return true;
    }
    return false;
}


int Club_lectura::cargar_menu(){

    if (hay_errores_al_inicializar())
        return -1;
    
    Menu menu;
    return menu.ejecutar(lista_escritores, lista_lecturas);
}


void Club_lectura::crear_lista_escritores(){

    Lector_escritor lector;
    
    while (!archivo_escritores.eof()){    
        Escritor* escritor = lector.leer_por_archivo(archivo_escritores);
        if (escritor)
            lista_escritores.insertar_final(escritor);
    }
}


int Club_lectura::buscar_posicion(Lectura* lectura_a_agregar){
    
    if(lista_lecturas.esta_vacia()){
        return 1;
    }

    bool encontrada = false;
    int posicion = lista_lecturas.obtener_cantidad();

    for (int i = 1; i <= lista_lecturas.obtener_cantidad() && !encontrada; i++){
        if(lista_lecturas.buscar(i)->comparar(lectura_a_agregar) == MAYOR){
            encontrada = true;
            posicion = i;
        }
    } 
    return posicion;  
}


void Club_lectura::crear_lista_lecturas(){

    Lector_lectura lector;

    while (!archivo_lecturas.eof()){
        Lectura* lectura = lector.leer_por_archivo(archivo_lecturas, lista_escritores);
        if(lectura){
            int posicion = buscar_posicion(lectura);            
            lista_lecturas.insertar_elemento(lectura, posicion);
        }
    }
}
