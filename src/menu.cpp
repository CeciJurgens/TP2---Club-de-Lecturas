#include "menu.h"

//const int SALIR = 12;

Menu::Menu(){
    abierto = true;
}

void Menu::mostrar_opciones(){
    system ("clear");                                
    cout << VISUAL_MENU;
}

int Menu::pedir_numero_por_consola(){
    
    int numero_ingresado;
    cout << "Escriba una opcion: ";
    cin >> numero_ingresado;
    
    while (numero_ingresado < 1 || numero_ingresado > 12){
        cout << "Opcion incorrecta. Por favor, vuelva a ingresar una opcion (1 al 12)" << endl;
        cin >> numero_ingresado;
    }
    return numero_ingresado;
}

void Menu::volver_menu() {
    cout << '\n';
    cin.ignore();
    cout << "Presione ENTER para volver al menu. ";
    cin.get();

}


void Menu::elegir_opcion(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas){
    
    Opciones_menu opcion(lista_escritores, lista_lecturas);

    int valor_ingresado = pedir_numero_por_consola();

    system ("clear");
    switch (valor_ingresado) {
        case 1: 
            opcion.agregar_lectura();
            volver_menu();
            break;
        case 2: 
            opcion.quitar_lectura();
            volver_menu();
            break;
        case 3: 
            opcion.agregar_escritor();
            volver_menu();
            break;
        case 4: 
            opcion.cambiar_fecha_fallecimiento_escritor();
            volver_menu();
            break;
        case 5: 
            opcion.listar_escritores();
            volver_menu();
            break;
        case 6: 
            opcion.sortear_lecturas();
            volver_menu();
            break;
        case 7: 
            opcion.listar_lecturas();
            volver_menu();
            break;
        case 8: 
            opcion.listar_lecturas_por_anios();
            volver_menu();
            break;
        case 9: 
            opcion.listar_lecturas_escritor();
            volver_menu();
            break;
        case 10: 
            opcion.listar_novelas_genero();
            volver_menu();
            break;
        case 11: 
            opcion.proxima_lectura_a_leer();
            volver_menu();
            break;
        case 12: 
            opcion.salir_menu();
            abierto = false; 
            break;
    }
}

int Menu::ejecutar(Lista<Escritor*>& lista_escritores, Lista<Lectura*>& lista_lecturas){
    while(abierto){    
        mostrar_opciones();
        elegir_opcion(lista_escritores, lista_lecturas);
    }
    return 0;
}
