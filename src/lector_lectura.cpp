#include "lector_lectura.h"


Lectura* Lector_lectura::cargar_lectura(string* linea, Lista<Escritor*>& lista_escritores){
    
    Lectura* lectura = nullptr;

    if(linea[0] == NOVELA){
        Lector_novela lector;
        lectura = lector.cargar_datos(linea, lista_escritores);
        if (lectura == nullptr){
            Lector_novela_historica lector;
            lectura = lector.cargar_datos(linea, lista_escritores);
        }
    } else if(linea[0] == CUENTO){
        Lector_cuento lector;
        lectura = lector.cargar_datos(linea, lista_escritores);
    } else if(linea[0] == POEMA){
        Lector_poema lector;
        lectura = lector.cargar_datos(linea, lista_escritores);
    } else {
        lectura = nullptr;
    }

    return lectura;
}


Lectura* Lector_lectura::leer_por_archivo(ifstream& archivo, Lista<Escritor*>& lista_escritores){
    
    string linea[MAXIMO_A_LEER];
    int cantidad_leidas = 0;
    bool linea_leida = true;

    while(cantidad_leidas < MAXIMO_A_LEER && !archivo.eof() && linea_leida){
        getline(archivo, linea[cantidad_leidas]);
        if (linea[cantidad_leidas].empty())
            linea_leida = false;
        else
            cantidad_leidas++;
    }

    if (cantidad_leidas < MINIMOS_PARAMETROS || cantidad_leidas == MAXIMO_A_LEER){
        return nullptr;
    }     
    return cargar_lectura(linea, lista_escritores);
}




Lectura* Lector_lectura::leer_por_consola(Lista<Escritor*>& lista_escritores){
    
    string caracter;
    getchar();   
    cout << "Ingrese el el tipo de lectura (C = cuento, P = poema o N = novela): " << endl;;
    getline(cin, caracter, '\n');

    while(caracter != CUENTO && caracter!= POEMA && caracter != NOVELA){
        cout << "Ingresó una opción inválida. Por favor, ingrese el el tipo de lectura\
( C = cuento, P = poema o N = novela): " << endl;
        getline(cin, caracter, '\n');
    }
    cout << endl;

    Lectura* lectura = nullptr;
    if(caracter == NOVELA){
        Lector_novela lector;
        lectura = lector.cargar_datos(lista_escritores); 
        if(!lectura){
            Lector_novela_historica lector;
            lectura = lector.cargar_datos(lista_escritores);
        }
    } else if (caracter == POEMA){
        Lector_poema lector;
        lectura = lector.cargar_datos(lista_escritores);
    } else{
        Lector_cuento lector;
        lectura = lector.cargar_datos(lista_escritores);
    }

    return lectura;
}



