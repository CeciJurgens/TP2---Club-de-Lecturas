#include "opciones_menu.h"


Opciones_menu::Opciones_menu(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas){
    this->lista_escritores = &lista_escritores;
    this->lista_lecturas = &lista_lecturas;
}


void Opciones_menu::listar_escritores() {

    if (lista_escritores->esta_vacia()){
        cout << "La lista de escritores se encuentra vacia. \n" << endl;
        return;
    }

    cout << "La lista de escritores es: " << endl;
    for (int i = 1; i <= lista_escritores->obtener_cantidad(); i++)
        cout << "\t\t Escritor " << i << ": " << lista_escritores->buscar(i)->obtener_nombre() << endl;
    cout << endl;
}


void Opciones_menu::listar_lecturas(){
    if (lista_lecturas->esta_vacia()){
        cout << "La lista de lecturas se encuentra vacia. \n" << endl;
        return;
    }

    cout << "La lista de lecturas es: " << endl;
    for (int i = 1; i <= lista_lecturas->obtener_cantidad(); i++){
        cout << "Lectura " << i << ": " << endl;
        lista_lecturas->buscar(i)->mostrar();
    }

    cout << endl;
}


void Opciones_menu::agregar_escritor(){
    
    Lector_escritor lector;
    Escritor* escritor = lector.leer_por_consola();
    
    lista_escritores->insertar_final(escritor);
    cout << "El escritor ha sido agregado con éxito a la lista.";
}


void Opciones_menu::quitar_lectura(){
    if(lista_lecturas->esta_vacia()){
        cout << "No hay lecturas en la lista." << endl;
        return;
    }

    listar_lecturas();
    int numero;
    int cantidad_lecturas = lista_lecturas->obtener_cantidad();

    cout << "Elija el numero de la lectura a eliminar (de 1 a " << cantidad_lecturas << "): ";
    cin >> numero;
    cout << endl;

    while (numero < 1 || numero > cantidad_lecturas){
        cout << "Opcion incorrecta. Elija un numero del 1 al " << cantidad_lecturas << ": ";
        cin >> numero;
    }
    cout << endl;

    delete lista_lecturas->buscar(numero);
    lista_lecturas->eliminar_elemento(numero);
    cout << "La lectura fue eliminada con éxito." << endl;
}


void Opciones_menu::sortear_lecturas(){

    srand(static_cast<unsigned int>(time(nullptr)));
    int lectura_random = 1 + rand() % lista_lecturas->obtener_cantidad();
    cout << "La lectura elegida es: " << endl;
    cout << endl;
    lista_lecturas->buscar(lectura_random)->mostrar();
}


void Opciones_menu::listar_lecturas_por_anios(){

    int anio_minimo;
    int anio_maximo;

    cout << "Ingrese el año minimo: " << endl;
    cin >> anio_minimo;

    cout << "Ingrese el año maximo: " << endl;
    cin >> anio_maximo;

    int cantidad_lecturas = lista_lecturas->obtener_cantidad();

    for (int i = 1; i <= cantidad_lecturas; i++){
        if (lista_lecturas->buscar(i)->obtener_anio_publicacion() > anio_minimo &&
        lista_lecturas->buscar(i)->obtener_anio_publicacion() < anio_maximo)
            cout << "Lectura " << i << "- " << lista_lecturas->buscar(i)->obtener_titulo() << endl; 
    }

}


void Opciones_menu::listar_lecturas_escritor(){
    
    int numero_escritor; 
    listar_escritores();
    int cantidad_lecturas = lista_lecturas->obtener_cantidad();

    cout << "Ingrese el autor que desea filtrar en la lista de lecturas (del 1 al " 
    << lista_escritores->obtener_cantidad() <<")" << endl;
    cin >> numero_escritor;
    cout << endl;
    string nombre_escritor = lista_escritores->buscar(numero_escritor)->obtener_nombre();
    
    for (int i = 1; i <= cantidad_lecturas; i++){
        if (nombre_escritor == lista_lecturas->buscar(i)->obtener_nombre_autor())
            cout << "Lectura " << i << "- " << lista_lecturas->buscar(i)->obtener_titulo() << endl;        
    }
}


void Opciones_menu::listar_novelas_genero(){

    cout << "Estos son todos los generos posibles de las novelas leidas:" << endl;
    cout << "\t\t\t0- COMEDIA " << endl;
    cout << "\t\t\t1- DRAMA " << endl;
    cout << "\t\t\t2- FICCION " << endl;
    cout << "\t\t\t3- HISTORICA " << endl;
    cout << "\t\t\t4- ROMANTICA " << endl;
    cout << "\t\t\t5- SUSPENSO " << endl;
    cout << "\t\t\t6- TERROR " << endl;
    
    int genero_ingresado;
    int cantidad_lecturas = lista_lecturas->obtener_cantidad();
    cout << "Elija un genero y a continuacion se mostrara todas las lecturas de ese genero." << endl;
    cin >> genero_ingresado;
    int contador = 0;
    for (int i = 1; i <= cantidad_lecturas; i++){
        lista_lecturas->buscar(i)->mostrar_novela(genero_ingresado);
        contador++;
    }

    if (contador == 0)
        cout << "No hay lecturas de ese genero en la lista." << endl;
}


void Opciones_menu::salir_menu() {
    cout << "\n¡Gracias por visitar el club de lecturas!" << endl;
}


void Opciones_menu::cambiar_fecha_fallecimiento_escritor(){

    listar_escritores();
    int numero_escritor;
    string nueva_fecha_fallecimiento;

    int cantidad_escritores = lista_escritores->obtener_cantidad();
    
    cout << "Ingrese el numero del escritor que desea cambiar la fecha de fallecimiento \
(del 1 al " << cantidad_escritores  << "). "<< endl;
    cin >> numero_escritor;
    
    while (numero_escritor < 1 || numero_escritor > cantidad_escritores){
        cout << "Numero Incorrecto. Ese escritor no existe. Por favor, vuelva a intentarlo." << endl;
        cin >> numero_escritor;
    }
  
    Escritor* escritor = lista_escritores->buscar(numero_escritor); 

    cout << "Los datos del escritor son: " << endl;
    escritor->mostrar();

    cout << "Ingrese la fecha de fallecimiento del escritor" << endl;
    cin >> nueva_fecha_fallecimiento;

    escritor->setear_anio_fallecimiento(nueva_fecha_fallecimiento);
    
    cout << "Los nuevos datos del escritor son: " << endl;
    escritor->mostrar();
}


int Opciones_menu::buscar_posicion(Lectura* lectura_a_agregar){
    
    if(lista_lecturas->esta_vacia()){
        return 1;
    }

    bool encontrada = false;
    int cantidad_lecturas = lista_lecturas->obtener_cantidad();
    int posicion = cantidad_lecturas+1; //revisar

    for (int i = 1; i <= cantidad_lecturas && !encontrada; i++){
        if(lista_lecturas->buscar(i)->comparar(lectura_a_agregar) == MAYOR){
            encontrada = true;
            posicion = i;
        }
    } 
    return posicion;  
}


void Opciones_menu::agregar_lectura(){
    Lector_lectura lector;

    Lectura* lectura = lector.leer_por_consola(*lista_escritores);
    int posicion = buscar_posicion(lectura);            
    lista_lecturas->insertar_elemento(lectura, posicion);

    cout << "La lectura ha sido agregada con éxito a la lista." << endl;
}


int Opciones_menu::buscar_posicion(Lectura* lectura_a_agregar, Lista<Lectura*>* lista){
    
    if(lista->esta_vacia()){
        return 1;
    }

    bool encontrada = false;
    int cantidad_lecturas = lista->obtener_cantidad();
    int posicion = cantidad_lecturas+1;

    for (int i = 1; i <= cantidad_lecturas && !encontrada; i++){
        if(lista->buscar(i)->comparar(lectura_a_agregar->obtener_tiempo_lectura()) == MAYOR){
            encontrada = true;
            posicion = i;
        }
    } 
    return posicion;  
}


void Opciones_menu::armar_cola_lecturas(){
    if(lista_escritores->esta_vacia())
        return;

    Lista<Lectura*>* lista_auxiliar = new Lista<Lectura*>;
    int cantidad_lecturas = lista_lecturas->obtener_cantidad();

    for(int i = 1; i <= cantidad_lecturas; i++){
        Lectura* lectura_a_agregar = lista_lecturas->buscar(i);
        int posicion = buscar_posicion(lectura_a_agregar, lista_auxiliar);
        lista_auxiliar->insertar_elemento(lectura_a_agregar, posicion);
    }

    for(int i = 1; i <= cantidad_lecturas; i++){
        Lectura* lectura = lista_auxiliar->buscar(i);
        cola_lecturas.encolar(lectura);
    }

    delete lista_auxiliar;    
}


void Opciones_menu::proxima_lectura_a_leer(){

    armar_cola_lecturas();
    char rta = 'S';
    
    while(rta == 'S' && !cola_lecturas.esta_vacia()){
        cout << "La lectura de menor tiempo de lectura es:" << endl;
        cola_lecturas.buscar()->mostrar();
        cout << "¿Ya la leyó? ¿Quiere eliminarla? Aprete S para sí, otra letra para NO: ";
        cin >> rta;
        if(rta == 'S')
            cola_lecturas.desencolar();
    }

    if(cola_lecturas.esta_vacia())
        cout << "Ya no quedan más lecturas.";
}
    