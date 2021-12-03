#include "Menu.h"
#include <iostream>
#include "DatosLeidos.h"
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include "Jugador.h"


using namespace std;

Menu::Menu(int cantOpciones) {
    srand(time(nullptr));
}

Menu::~Menu() = default;

void designarTurnos(){
    int primerTurno = rand() % (1);
    if (primerTurno == 0)
        primerJugador = new Jugador(primerTurno);
    else
        segundoJugador = new Jugador(primerTurno);
}

void Menu::mostrarMenuPrincipal() {
    cout << "\n\t\t\t|----------------------------------|" << endl
         << "\n\t\t\t|         .: BIENVENIDO :.         |" << endl
         << "\n\t\t\t|----------------------------------|" << endl
         << "\nPara continuar, ingrese el numero correspondiente a la opcion que desea seleccionar: " << endl
         << "\n1. Modificar edificio por nombre." << endl
         << "2. Listar todos los edificios." << endl
         << "3. Mostrar mapa." << endl
         << "4. Comenzar partida." << endl
         << "5. Guardar y salir." << endl;
}

void Menu::mostrarMenuJugador() {
    //cout << "\n\t\t\t.: TURNO DE: "<< primerJugador->nombreJugador
    cout << "\nPara continuar, ingrese el numero correspondiente a la opcion que desea seleccionar:" << endl
         << "\n1. Construir un edificio por nombre." << endl
         << "2. Listar edificios construidos por jugador." << endl
         << "3. Demoler un edificio por coordenada." << endl
         << "4. Atacar por coordenada." << endl
         << "5. Reparar edificio por coordenada." << endl
         << "6. Comprar bombas." << endl
         << "7. Consultar coordenada. "<< endl
         << "8. Mostrar inventario." << endl
         << "9. Mostrar objetivos." << endl
         << "10. Recolectar recursos producidos." << endl
         << "11. Movilizarse." << endl
         << "12. Guardar y salir." << endl;
}

void Menu::setOpcion() {
    cout << "\nOpcion numero (->) ";
    cin >> opcionElegida;
}

void Menu::opcionValida(){
    bool opcion_valida = opcionElegida > 0 && opcionElegida <= cantidadOpciones;
    while(!opcion_valida){
        cout << "\nEl numero de opcion elegido no corresponde con los mostrados en pantalla." << endl
             << "Por favor, vuelva a internarlo." << endl;
        setOpcion();
        opcion_valida = opcionElegida > 0 && opcionElegida <= cantidadOpciones;
    }
}

int Menu::getOpcion() {
    return opcionElegida;
}

void Menu::mostrarMapa(Casillero*** casilleros, int cantFilas, int cantColumnas){
    cout << "\n";
    for(int i=0; i<cantFilas;i++) {
        for (int j = 0; j < cantColumnas; j++) {
            casilleros[i][j]->mostrar();
            cout << " ";
        }
        cout << "\n";
    }
}

void Menu::listarMateriales(Material** materiales, int cantidadMateriales){
    for (int i=0; i<cantidadMateriales;i++){
        cout << "\n->MATERIAL: " << materiales[i]->getNombre() << endl
             << "Cantidad: " << materiales[i]->getCantidad() << endl;
    }
}

void Menu::listarEdificios(Edificio ** edificios, int cantidadEdificios) {
    for (int i=0;i<cantidadEdificios;i++){
        cout << "\n->EDIFICIO: " << edificios[i]->getNombre() << endl
             << "Construidos: " << edificios[i]->getCostruidos() << endl
             << "Permitidos: " << edificios[i]->getMaximaCantidad() << endl
             << "Materiales necesarios: | " << edificios[i]->getPiedra()
             << " de piedra | " << edificios[i]->getMadera() << " de madera | "
             << edificios[i]->getMetal() << " de metal |" << endl;
    }
}

void Menu::listarConstruidos(Edificio** edificios, int cantidadEdificios){
    for (int i=0;i<cantidadEdificios;i++)
        cout << "\n->" << edificios[i]->getNombre() << ": " << edificios[i]->getCostruidos() << endl;
}

void Menu::consultarCoordenada(Casillero*** casilleros, int maxFilas, int maxColumnas, CasilleroConstruible** construibles, int cantidadConstruibles, CasilleroTransitable** transitables, int cantidadTransitables) {
    int x, y;
    char tipoCasilla;
    cout << "\nConsultar coordenada" << endl;
    leerCoordenadas(x,y,maxFilas,maxColumnas);
    tipoCasilla = casilleros[x][y]->getInicial();
    if(tipoCasilla == 'T'){
        cout << "Ha encontrado un casillero construible." << endl;
        int posicion = posicionConstruible(x,y,construibles,cantidadConstruibles);
        if (construibles[posicion]->getEdificio()->getNombre() != "")
            cout << "Hay un " << construibles[posicion]->getEdificio()->getNombre() << " construido en este casillero." << endl;
        else
            cout << "No hay edificios construidos en este casillero." << endl;
    }
    if(tipoCasilla == 'C'){
        cout << "Ha encontrado un casillero transitable." << endl;
        int posicion = posicionTransitable(x,y,transitables,cantidadTransitables);
        if (transitables[posicion]->getMaterial()->getNombre() != "") {
            cout << "Hay " << transitables[posicion]->getMaterial()->getCantidad()
                 << " de " << transitables[posicion]->getMaterial()->getNombre() << " en este casillero." << endl;
        }
        else
            cout << "No hay materiales en este casillero." << endl;
    }
    if(tipoCasilla == 'I'){
        cout << "Ha encontrado un casillero inaccesible." << endl;
    }
}

void Menu::leerCoordenadas(int &x, int &y, int maxFilas, int maxColumnas){
    cout << "Convencion de coordenadas ->(X,Y)" << endl;
    cout << "| Rango X: 0-" << maxFilas - 1 << " | Rango Y: 0-" << maxColumnas - 1 << " |" << endl;
    cout << "X -> ";
    cin >> x;
    while (x < 0 || x > maxFilas) {
        cout << "Ha ingresado una coordenada X fuera de rango. Lea las indicaciones y vuelva a intentarlo." << endl;
        cout << "X-> ";
        cin >> x;
    }
    cout << "Y -> ";
    cin >> y;
    while (y < 0 || y > maxColumnas) {
        cout << "Ha ingresado una coordenada Y fuera de rango. Lea las indicaciones y vuelva a intentarlo." << endl;
        cout << "Y-> ";
        cin >> y;
    }
    cout << "Ha digitado las coordenadas ->(" << x << "," << y << ")" << endl;
}

int Menu::posicionConstruible(int x, int y, CasilleroConstruible** construibles, int cantidadConstruibles) {
    for (int i = 0; i < cantidadConstruibles; i++)
        if (construibles[i]->getFila() == x && construibles[i]->getColumna() == y) return i;
    return -1;
}

int Menu::posicionTransitable(int x, int y, CasilleroTransitable** transitables, int cantidadTransitables) {
    for (int i = 0; i < cantidadTransitables; i++)
        if (transitables[i]->getFila() == x && transitables[i]->getColumna() == y) return i;
    return -1;
}


void Menu::recolectarRecursos(CasilleroConstruible** construibles, int cantidadConstruibles, Material** materiales, int cantidadMateriales){
    int posicionMaterial, acumuladorPiedra = 0, acumuladorMadera = 0, acumuladorMetal = 0;
    for (int i = 0; i< cantidadConstruibles; i++)
        if (construibles[i]->getEdificio()->getNombre() != ""){
            string nombreEdificio = construibles[i]->getEdificio()->getNombre();
            if (nombreEdificio == "mina") {
                posicionMaterial = buscarMaterial("piedra", materiales, cantidadMateriales);
                materiales[posicionMaterial]->sumar(15);
                acumuladorPiedra += 15;
            }
            if (nombreEdificio == "aserradero"){
                posicionMaterial = buscarMaterial("madera", materiales, cantidadMateriales);
                materiales[posicionMaterial]->sumar(25);
                acumuladorMadera += 25;
            }
            if (nombreEdificio == "fabrica"){
                posicionMaterial = buscarMaterial("metal",materiales,cantidadMateriales);
                materiales[posicionMaterial]->sumar(40);
                acumuladorMetal += 40;
            }
        }
    cout << "Has recolectado:\n->" << acumuladorPiedra << " piedras.\n->" << acumuladorMadera << " maderas." << endl
         << "->" << acumuladorMetal << " metales." << endl;
}

int Menu::buscarMaterial(string material, Material** materiales, int cantidadMateriales){
    for (int i=0;i<cantidadMateriales;i++){
        if (material == materiales[i]->getNombre()) return i;
    }
    return -1;
}

void Menu::lluviaRecursos(CasilleroTransitable** transitables, int cantidadTransitables, Casillero*** casilleros) {
    int generacionPiedra = 1 + rand() % (4 - 1);
    int generacionMadera = rand() % (2);
    int generacionMetal = 2 + rand() % (5 - 2);
    int totalGenerado = generacionPiedra + generacionMadera + generacionMetal;
    generamientos("piedra",generacionPiedra,transitables,cantidadTransitables,casilleros);
    generamientos("madera",generacionMadera,transitables,cantidadTransitables,casilleros);
    generamientos("metal",generacionMetal,transitables,cantidadTransitables,casilleros);
    cout << "Se han generado " << totalGenerado << " materiales a lo largo del mapa." << endl
         << "| Piedra: " << generacionPiedra << " | Madera: " << generacionMadera << " | Metal: " << generacionMetal << " |" << endl;
}

void Menu::generamientos(string material, int cantidadMaterial, CasilleroTransitable** transitables, int cantidadTransitables, Casillero*** casilleros){
    for (int i = 0; i < cantidadMaterial; i++) {
        int casilleroGenerador = rand() % (cantidadTransitables);
        while(transitables[casilleroGenerador]->getMaterial()->getNombre() != "")
            casilleroGenerador = rand() % cantidadTransitables;
        transitables[casilleroGenerador]->generarMaterial(material, 1, casilleros);
    }
}

void Menu::construirEdificio(CasilleroConstruible** construibles, Casillero*** casilleros, int cantidadConstruibles, Material** materiales, Edificio** edificios, int cantidadEdificios, int cantidadMateriales, int maxFilas,int maxColumnas){
    string nombreEdificio;
    int x,y, posConstruible;
    cout << "Ingrese el nombre de un edificio: ";
    cin >> nombreEdificio;
    int posEdificio = posicionEdificio(nombreEdificio, edificios, cantidadEdificios);
    if (posEdificio != -1){
        if(materialesSuficientes(materiales,edificios,cantidadMateriales,posEdificio)){
            if (edificios[posEdificio]->getCostruidos() < edificios[posEdificio]->getMaximaCantidad()) {
                cout << "Es posible construir el edificio" << endl;
                leerCoordenadas(x,y,maxFilas,maxColumnas);
                posConstruible = posicionConstruible(x,y,construibles,cantidadConstruibles);
                if (posConstruible != -1 && !haySuperposicion(construibles,posConstruible)){
                    construibles[posConstruible]->construirEdificio(nombreEdificio,edificios[posEdificio]->getPiedra(),edificios[posEdificio]->getMadera(),edificios[posEdificio]->getMetal(),edificios[posEdificio]->getMaximaCantidad(),casilleros);
                    edificios[posEdificio]->sumarEdificio();
                    cout << "Edificio construido exitosamente." << endl;
                    restarMateriales(materiales,edificios,cantidadMateriales,posEdificio);
                }
                else
                    cout << "No se puede construir en las coordenadas ingresadas." << endl;
            }
            else
                cout << "No se puede construir el edificio porque la maxima cantidad ha sido alcanzada." << endl;
        }
        else
            cout << "No tenes materiales suficientes para construir el edificio." << endl;
    }
    else
        cout << "El edificio ingresado no existe." << endl;
}

int Menu::posicionEdificio(string edificio, Edificio** edificios, int cantidadEdificios) {
    for (int i = 0; i < cantidadEdificios; i++){
        string edificioBase = edificios[i]->getNombre();
        if (edificio == edificioBase) return i;
    }
    return -1;
}

bool Menu::haySuperposicion(CasilleroConstruible** construibles,int posConstruible){
    return construibles[posConstruible]->getEdificio()->getNombre() != "";
}

bool Menu::materialesSuficientes(Material** materiales, Edificio** edificios, int cantidadMateriales, int posicionEdificio){
    int posPiedra = buscarMaterial("piedra",materiales,cantidadMateriales);
    int posMadera =buscarMaterial("madera",materiales,cantidadMateriales);
    int posMetal = buscarMaterial("metal",materiales,cantidadMateriales);
    bool sufPiedra = materiales[posPiedra]->getCantidad() >= edificios[posicionEdificio]->getPiedra();
    bool sufMadera = materiales[posMadera]->getCantidad() >= edificios[posicionEdificio]->getMadera();
    bool sufMetal = materiales[posMetal]->getCantidad() >= edificios[posicionEdificio]->getMetal();
    return sufPiedra && sufMadera && sufMetal;
}

void Menu::restarMateriales(Material** materiales, Edificio** edificios, int cantidadMateriales, int posicionEdificio){
    int posPiedra = buscarMaterial("piedra",materiales,cantidadMateriales);
    int posMadera =buscarMaterial("madera",materiales,cantidadMateriales);
    int posMetal = buscarMaterial("metal",materiales,cantidadMateriales);
    materiales[posPiedra]->restar(edificios[posicionEdificio]->getPiedra());
    materiales[posMadera]->restar(edificios[posicionEdificio]->getMadera());
    materiales[posMetal]->restar(edificios[posicionEdificio]->getMetal());
}

void Menu::demolerEdificio(Casillero*** casilleros, CasilleroConstruible** construibles, int cantidadConstruibles, Material** materiales,int cantidadMateriales, Edificio** edificios,int cantidadEdificios, int cantFilas, int cantColumnas){
    int x,y, posEdificio;
    leerCoordenadas(x,y,cantFilas,cantColumnas);
    int posConstruible = posicionConstruible(x,y,construibles,cantidadConstruibles);
    if (posConstruible != -1){
        posEdificio = posicionEdificio(construibles[posConstruible]->getEdificio()->getNombre(),edificios,cantidadEdificios);
        construibles[posConstruible]->demolerEdificio(casilleros);
        edificios[posEdificio]->restarEdificio();
        devolverMateriales(materiales,cantidadMateriales,edificios,posEdificio);
        cout << "Se ha demolido " << edificios[posEdificio]->getNombre() << " en las coordenadas ("<< x << "," << y << ")" << endl;
    }
    else
        cout << "No hay nada que demoler en esta coordenada." << endl;
}

void Menu::devolverMateriales(Material** materiales, int cantidadMateriales, Edificio** edificios, int posEdificio){
    int posPiedra = buscarMaterial("piedra",materiales,cantidadMateriales);
    int posMadera = buscarMaterial("madera",materiales,cantidadMateriales);
    int posMetal = buscarMaterial("metal",materiales,cantidadMateriales);
    materiales[posPiedra]->sumar(edificios[posEdificio]->getPiedra() / 2);
    materiales[posMadera]->sumar(edificios[posEdificio]->getMadera() / 2);
    materiales[posMetal]->sumar(edificios[posEdificio]->getMadera() / 2);
}

void Menu::guardarMateriales(Material** materiales, int cantidadMateriales){
    ofstream arcMateriales("materiales.txt");
    for (int i=0;i<cantidadMateriales;i++)
        arcMateriales << materiales[i]->getNombre() << " " << materiales[i]->getCantidad() << endl;
    arcMateriales.close();
}

void Menu::guardarUbicaciones(CasilleroConstruible** construibles, int cantidadConstruibles){
    ofstream arcUbicaciones("ubicaciones.txt");
    for (int i=0; i<cantidadConstruibles;i++)
        if(construibles[i]->getEdificio()->getNombre() != "") {
            arcUbicaciones << construibles[i]->getEdificio()->getNombre() << " ("
                           << construibles[i]->getFila() << "," << construibles[i]->getColumna() << ")" << endl;
        }
    arcUbicaciones.close();
}

void Menu::guardarMapa(Casillero*** casilleros, int filas, int columnas) {
    ofstream arcMapa("mapa.txt");
    arcMapa << filas << " " << columnas << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            arcMapa << casilleros[i][j]->getInicial() << " ";
        }
        arcMapa << "\n";
    }
    arcMapa.close();
}

void Menu::menuJugador(Casillero*** casilleros,int cantFilas, int cantColumnas,CasilleroConstruible** construibles, int cantidadConstruibles, CasilleroTransitable** transitables, int cantidadTransitables, Material** materiales, int cantidadMateriales, Edificio** edificios,int cantidadEdificios){
    switch(opcionElegida){
        case 1:
            //construirEdificio(construibles,cantidadConstruibles,materiales,edificios,cantidadEdificios,cantidadMateriales,cantFilas,cantColumnas); // se borró parametro casilleros
            break;
        case 2:
            listarConstruidos(edificios,cantidadEdificios);
            break;
        case 3:
            demolerEdificio(casilleros,construibles,cantidadConstruibles,materiales,cantidadMateriales,edificios,cantidadEdificios,cantFilas,cantColumnas);
            break;
        case 4:
            //atacarEdificio();
            break;
        case 5:
            //repararEdificio();
            break;
        case 6:
            //comprarBombachas();
            break;
        case 7:
            consultarCoordenada(casilleros,cantFilas,cantColumnas,construibles,cantidadConstruibles,transitables,cantidadTransitables);
            break;
        case 8:
            mostrarObjetivos();
            break;
        case 9:
            listarMateriales(materiales,cantidadMateriales);
            break;
        case 10:
            recolectarRecursos(construibles,cantidadConstruibles,materiales,cantidadMateriales);
            break;
        case 11:
            moverse();
            break;
        case 12:
            finalizarTurno();
            break;
        case 13:
            guardarMateriales(materiales,cantidadMateriales);
            guardarMapa(casilleros,cantFilas,cantColumnas);
            guardarUbicaciones(construibles,cantidadConstruibles);
            break;
    }
}

void Menu::menuPrincipal(Casillero*** casilleros, Edificio** edificios, int cantidadEdificios, int cantFilas, int cantColumnas) {
    modificacionRealizada = false;
    switch (opcionElegida) {
        case 1:
            //modificarEdificio();
            modificacionRealizada = true;
            break;
        case 2:
            listarEdificios(edificios,cantidadEdificios);
            break;
        case 3:
            mostrarMapa(casilleros,cantFilas,cantColumnas);
            break;
        case 4:
            //designarObjetivos();
            //lluviaRecursos(transitables,cantidadTransitables,casilleros);
            menuJugador(Casillero*** casilleros,int cantFilas, int cantColumnas,CasilleroConstruible** construibles, int cantidadConstruibles, CasilleroTransitable** transitables, int cantidadTransitables, Material** materiales, int cantidadMateriales, Edificio** edificios,int cantidadEdificios);
            break;
        case 5:
            if (modificacionRealizada)
                guardarEdificios(edificios,cantidadEdificios);
            break;
    }
}