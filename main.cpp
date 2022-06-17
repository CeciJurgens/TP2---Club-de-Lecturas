#include <iostream>
#include <fstream>

#include "src/club_lectura.h"


using namespace std;

const string path_lecturas = "archivos/lecturas.txt";
const string path_escritores = "archivos/escritores.txt";

int main(){ 
    
    Club_lectura club (path_lecturas, path_escritores);

    return  club.cargar_menu();

}
