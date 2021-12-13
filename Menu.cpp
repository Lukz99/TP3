#include "Menu.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;

Menu::Menu(int cantOpciones) {
    srand(time(nullptr));
}

Menu::~Menu() = default;

void designarTurnos(Jugador primerJugador,Jugador segundoJugador){
    int sorteoDeTurno = rand() % (1);
    if (sorteoDeTurno == 0){
        primerJugador.asignarTurno(1);
        segundoJugador.asignarTurno(2);
        cout << "->Jugador 1 inicia turno ->Lo sigue Jugador 2" << endl;
    }
    else{
        segundoJugador.asignarTurno(1);
        primerJugador.asignarTurno(2);
        cout << "->Jugador 2 inicia turno ->Lo sigue Jugador 1" << endl;
    }
}

void Menu::gestionarPartida(Grafo vertices,DiccionarioDeEdificios* diccionarioDeEdificios,Jugador jugadorActual,DatosLeidos baseDeDatos){
    bool finalizarTurno = false;
    cout << "| TURNO DE: " << jugadorActual.obtenerNombreJugador() << " |" << endl;
    while(!jugadorActual.jugadorSinEnergias() || !finalizarTurno)
        procesarOpcionMenuJugador(vertices, diccionarioDeEdificios,jugadorActual,baseDeDatos,finalizarTurno);
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

void Menu::mostrarMapa(Vertice* listaVertices,Casillero*** casilleros, int cantFilas, int cantColumnas){
    Vertice* verticeActual;
    cout << "\n";
    cout << "--------MATERIALES Y EDIFICIOS------" << endl;
    for(int i=0; i<cantFilas;i++) {
        for (int j = 0; j < cantColumnas; j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices,i,j);
            if ((verticeActual->obtenerCasilla() == 'T' && verticeActual->obtenerCasilleroConstruible()->edificioConstruido()))
                cout << verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombreClave() << " ";
            else if((verticeActual->obtenerCasilla() == 'C' || verticeActual->obtenerCasilla() == 'M' || verticeActual->obtenerCasilla() == 'B') && verticeActual->obtenerCasilleroTransitable()->materialPresente())
                cout << verticeActual->obtenerCasilleroTransitable()->obtenerMaterial()->getNombreClave() << " ";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "---------MAPA TERRENOS-------" << endl;
    for(int i=0; i<cantFilas;i++) {
        for (int j = 0; j < cantColumnas; j++) {
            cout << casilleros[i][j]->obtenerInicial();
            cout << " ";
        }
        cout << "\n";
    }
}


void Menu::lluviaRecursos(CasilleroTransitable** transitables, int cantidadTransitables, Casillero*** casilleros) {
    int posicionX, posicionY;
    int generacionPiedra = 1 + rand() % (2 - 1);
    int generacionMadera = rand() % (3);
    int generacionMetal = 2 + rand() % (4 - 2);
    int totalGenerado = generacionPiedra + generacionMadera + generacionMetal;



    generamientos("piedra",generacionPiedra,transitables,cantidadTransitables,casilleros);
    generamientos("madera",generacionMadera,transitables,cantidadTransitables,casilleros);
    generamientos("metal",generacionMetal,transitables,cantidadTransitables,casilleros);
    cout << "Se han generado " << totalGenerado << " materiales a lo largo del mapa." << endl
         << "| Piedra: " << generacionPiedra << " | Madera: " << generacionMadera << " | Metal: " << generacionMetal << " |" << endl;
}

void seleccionarCoordenadasAlAzar(Vertice* listaVertices,DatosLeidos baseDeDatos,int &posicionX,int &posicionY){
    Vertice* verticeBuscado;
    posicionX = rand() % (baseDeDatos.obtenerCantidadFilas());
    posicionY = rand() % (baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(posicionX,posicionY);



}


/*
void Menu::guardarMateriales(Material** materiales, int cantidadMateriales){
    ofstream arcMateriales("materiales.txt");
    for (int i=0;i<cantidadMateriales;i++)
        arcMateriales << materiales[i]->obtenerNombre() << " " << materiales[i]->getCantidad() << endl;
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
}*/

void Menu::guardarMapa(Casillero*** casilleros, int filas, int columnas) {
    ofstream arcMapa("mapa.txt");
    arcMapa << filas << " " << columnas << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            arcMapa << casilleros[i][j]->obtenerInicial() << " ";
        }
        arcMapa << "\n";
    }
    arcMapa.close();
}

void Menu::procesarOpcionMenuPrincipal(Vertice* listaVertices,DiccionarioDeEdificios *diccionario,Casillero*** casilleros, int cantFilas, int cantColumnas) {
    switch (opcionElegida) {
        case 1:
            modificarEdificio(diccionario);
            break;
        case 2:
            diccionario->recorridoInOrden(diccionario->obtenerNodoRaiz());
            break;
        case 3:
            mostrarMapa(listaVertices,casilleros,cantFilas,cantColumnas);
            break;
        case 4:
            //designarObjetivos();
            //lluviaRecursos(transitables,cantidadTransitables,casilleros);
            //menuJugador(Casillero*** casilleros,int cantFilas, int cantColumnas,CasilleroConstruible** construibles, int cantidadConstruibles, CasilleroTransitable** transitables, int cantidadTransitables, Material** materiales, int cantidadMateriales, Edificio** edificios,int cantidadEdificios);
            break;
        case 5:
            diccionario->guardarDatosDiccionario(diccionario->obtenerNodoRaiz());
            cout << "\nProgreso guardado correctamente.\n";
            break;

    }
}


void Menu::procesarOpcionMenuJugador(Grafo vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador jugador, DatosLeidos baseDeDatos,bool &finalizarTurno){
    switch(opcionElegida){
        case 1:
            construirEdificio(diccionarioDeEdificios,vertices,jugador,baseDeDatos);
            break;
        case 2:
            diccionarioDeEdificios->listarConstruidos(diccionarioDeEdificios->obtenerNodoRaiz());
            break;
        case 3:
            demolerEdificio(vertices.obtenerListaVertices(),diccionarioDeEdificios,jugador,baseDeDatos);
            break;
        case 4:
            atacarEdificio(vertices.obtenerListaVertices(),jugador,baseDeDatos);
            break;
        case 5:
            repararEdificio(vertices.obtenerListaVertices(),diccionarioDeEdificios,jugador,baseDeDatos);
            break;
        case 6:
            comprarBombas(jugador);
            break;
        case 7:
            consultarCoordenada(vertices.obtenerListaVertices(),baseDeDatos);
            break;
        case 8:
            //mostrarObjetivos();
            break;
        case 9:
            jugador.mostrarMateriales();
            break;
        case 10:
            recolectarRecursos(vertices.obtenerListaVertices(),jugador,baseDeDatos);
            break;
        case 11:
            //moverse();
            break;
        case 12:
            finalizarTurno = true;
            break;
        case 13:
            //guardarMateriales(materiales,cantidadMateriales);
            //guardarMapa(casilleros,cantFilas,cantColumnas);
            //guardarUbicaciones(construibles,cantidadConstruibles);
            break;
    }
}
//------------------------MENU PRINCIPAL ---> OPCION 1 -----------------------------

void Menu::modificarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios) {
    string nombreEdificio;
    int cantidadNuevaPiedra, cantidadNuevaMadera, cantidadNuevaMetal;
    cout << "Ingrese el nombre del edificio a modificar: " << endl;
    cin >> nombreEdificio;
    nombreEdificio = validarEdificio(diccionarioDeEdificios,nombreEdificio);
    if (nombreEdificio == "obelisco") {
        cout << "Este edificio no es modificable." << endl;
    } else {
        cantidadNuevaPiedra = modificarMaterial(diccionarioDeEdificios, "piedra",nombreEdificio);
        cantidadNuevaMadera = modificarMaterial(diccionarioDeEdificios, "madera",nombreEdificio);
        cantidadNuevaMetal = modificarMaterial(diccionarioDeEdificios, "metal",nombreEdificio);
        diccionarioDeEdificios->modificarNodo(diccionarioDeEdificios->obtenerNodoRaiz(), nombreEdificio,
                                              cantidadNuevaPiedra, cantidadNuevaMadera, cantidadNuevaMetal);
    }
}

int Menu::modificarMaterial(DiccionarioDeEdificios* diccionarioDeEdificios,string nombreMaterial,string nombreEdificio){
    int cantidadNuevaMaterial, cantidadMaterialOriginal = diccionarioDeEdificios->extraerDato(diccionarioDeEdificios->obtenerNodoRaiz(),nombreEdificio,nombreMaterial);
    cout << "¿Desea modificar la cantidad de " << nombreMaterial << "? (Actual: " << cantidadMaterialOriginal << ")" << endl;
    if (realizarOperacion() == "S"){
        cout << "Ingrese la nueva cantidad de " << nombreMaterial << "." << endl;
        cin >> cantidadNuevaMaterial;
    }
    else
        cantidadNuevaMaterial = cantidadMaterialOriginal;
    return cantidadNuevaMaterial;
}

//------------------------MENU JUGADOR ---> OPCION 1 -----------------------------

void Menu::construirEdificio(DiccionarioDeEdificios* diccionario,Grafo vertices,Jugador jugador,DatosLeidos baseDeDatos) {
    string nombreEdificio;
    int coordenadaX, coordenadaY;
    bool respetaMaximaCantidad;
    cout << ">--Construir un edificio--<\n\nIngrese el nombre del edificio que desea construir: ";
    cin >> nombreEdificio;
    nombreEdificio = validarEdificio(diccionario, nombreEdificio);
    respetaMaximaCantidad = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,"maxima cantidad") - diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,"construidos") < 0;
    if (materialesSuficientes(diccionario,jugador,nombreEdificio) && respetaMaximaCantidad){
        cout << "\nEs posible construir un/una " << nombreEdificio << ". Desea continuar?\n| Coste de energia: 15 |";

        if (realizarOperacion() == "S"){
            leerCoordenadas(coordenadaX,coordenadaY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
            if (coordenadaConstruible(vertices.obtenerListaVertices(),diccionario,coordenadaX,coordenadaY,jugador,nombreEdificio,baseDeDatos.obtenerCasilleros())) {
                jugador.restarEnergia(15);
                cout << "Edificio construido correctamente en coordenada (" << coordenadaX << "," << coordenadaY << ")"
                     << endl;
                restarMateriales(diccionario,jugador,nombreEdificio,1);
            }
            else
                cout << "El terreno de la coordenada (" << coordenadaX << "," << coordenadaY << ") no es construible. No se le han restado energías.";
        }
    }
    else
        cout << "El edificio ingresado no respeta los requisitos de construccion." << endl;
}

bool Menu::materialesSuficientes(DiccionarioDeEdificios* diccionario,Jugador jugador,string nombreEdificio){
    bool suficientePiedra = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"piedra");
    bool suficienteMadera = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"madera");
    bool suficienteMetal = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"metal");
    return suficientePiedra && suficienteMadera && suficienteMetal;
}

bool Menu::realizarDiferenciaMateriales(DiccionarioDeEdificios* diccionario,Jugador jugador, string nombreEdificio,string nombreMaterial){
    //cantidad materiales del jugador - cantidad materiales en diccionario de edificios
    int diferenciaMateriales = jugador.obtenerListaMateriales()->extraerCantidadMaterial(nombreMaterial) - diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,nombreMaterial);
    return diferenciaMateriales >= 0;
}

bool Menu::coordenadaConstruible(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,int coordenadaX, int coordenadaY, Jugador jugador,string nombreEdificio, Casillero*** casilleros){
    Vertice* verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,coordenadaX,coordenadaY);
    bool esPosibleConstruir;
    if (verticeBuscado->obtenerCasilla() == 'T') {
        esPosibleConstruir = true;
        verticeBuscado->construirEdificio(nombreEdificio,casilleros,coordenadaX,coordenadaY);
        verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->declararPropietario(jugador.obtenerNombreJugador());
        diccionario->modificacionEnConstruidos(diccionario->obtenerNodoRaiz(),verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre(),true);
    }
    else
        esPosibleConstruir = false;
    return esPosibleConstruir;
}

//------------------------MENU JUGADOR ---> OPCION 3 -----------------------------

void Menu::demolerEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionario, Jugador jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << ">--Demoler un edificio--<\nIngrese las coordenadas del edificio a demoler." << endl;
    leerCoordenadas(posicionY,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido()){
        nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
        cout << "Usted posee un/una " << nombreEdificio
             << " en la coordenada (" << posicionX << "," << posicionY << ")\nDesea demoler este edificio?"
             << "\n| Coste de energia: 15 |" << endl;
        if(realizarOperacion() == "S"){
            verticeBuscado->demolerEdificio(baseDeDatos.obtenerCasilleros());
            diccionario->modificacionEnConstruidos(diccionario->obtenerNodoRaiz(),nombreEdificio,false);
            devolverMateriales(diccionario,jugador,nombreEdificio);
            jugador.restarEnergia(15);
            cout << "Edificio demolido exitosamente." << endl;
        }
    }
}

void Menu::devolverMateriales(DiccionarioDeEdificios* diccionario,Jugador jugador, string nombreEdificio){
    int devolucionPiedra = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"piedra",nombreEdificio) / 2;
    int devolucionMadera = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"madera",nombreEdificio) / 2;
    int devolucionMetal = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"metal",nombreEdificio) / 2;
    jugador.obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionPiedra,true);
    jugador.obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionMadera,true);
    jugador.obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionMetal,true);
}

//------------------------MENU JUGADOR ---> OPCION 4 -----------------------------

void Menu::atacarEdificio(Vertice* listaVertices,Jugador jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << ">--Atacar edificio!--<\n| Coste de energia: 30 |\nIngrese las coordenadas del edificio que desea atacar." << endl;
    leerCoordenadas(posicionY,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido()) {
        if (verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() !=
            jugador.obtenerNombreJugador()) {
            nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
            if(nombreEdificio == "mina oro" || nombreEdificio == "mina" || nombreEdificio == "fabrica")
                verticeBuscado->obtenerCasilleroConstruible()->edificiosReparables(false,baseDeDatos.obtenerCasilleros());
            else{
                verticeBuscado->demolerEdificio(baseDeDatos.obtenerCasilleros());
                cout << "Edificio atacado y destruido exitosamente." << endl;
            }
            jugador.restarEnergia(30);
        } else
            cout << "Usted es el propietario del edificio en esta coordenada." << endl;
    }
    else
        cout << "No hay un edificio construido en las coordenadas (" << posicionX << "," << posicionY << ")" << endl;
}

//------------------------MENU JUGADOR ---> OPCION 5 -----------------------------

void Menu::repararEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,Jugador jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << ">--Reparar edificio!--<\n| Coste de energia: 25 |\nIngrese las coordenadas del edificio que desea reparar." << endl;
    leerCoordenadas(posicionY,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido() && materialesSuficientes(diccionario,jugador,nombreEdificio))
        if (verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() ==
            jugador.obtenerNombreJugador()) {
            nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
            if(nombreEdificio == "mina oro" || nombreEdificio == "mina" || nombreEdificio == "fabrica"){
                verticeBuscado->obtenerCasilleroConstruible()->edificiosReparables(true,baseDeDatos.obtenerCasilleros());
                restarMateriales(diccionario,jugador,nombreEdificio,0.25);
                jugador.restarEnergia(25);
            }else
                cout << "Este edificio no es reparable." << endl;
        } else
            cout << "Usted NO es el propietario del edificio en esta coordenada." << endl;
    else
        cout << "No hay un edificio construido en las coordenadas (" << posicionX << "," << posicionY << ")" << endl;
}

//------------------------MENU JUGADOR ---> OPCION 6 -----------------------------

void Menu::comprarBombas(Jugador jugador){
    int compraSolicitada;
    int cantidadAndycoinsActuales = jugador.obtenerListaMateriales()->extraerCantidadMaterial("andycoins");
    int cantidadBombasActuales = jugador.obtenerListaMateriales()->extraerCantidadMaterial("bombas");
    int disponibilidadDeCompra = cantidadAndycoinsActuales/100;
    cout << ">--Comprar bombas--<\nPrecio por unidad: 100 andycoins." << endl;
    cout << "->Usted dispone de: " << cantidadAndycoinsActuales << " andycoins.\nPuede comprar hasta: "
         << disponibilidadDeCompra << " bombas.\n| Coste de energia: 5 |\n->Ingrese la cantidad de bombas que desea adquirir: ";
    cin >> compraSolicitada;
    if (compraSolicitada < disponibilidadDeCompra) {
        jugador.obtenerListaMateriales()->modificarNodo("andycoins",compraSolicitada,false); //false = restar
        jugador.restarEnergia(5);
        cout << "Ha adquirido " << compraSolicitada << " bombas exitosamente.";
        cout << "Saldo de andycoins actual: " << jugador.obtenerListaMateriales()->extraerCantidadMaterial("andycoins");
    }
    else
        cout << "Ha fracasado la compra debido a que no cuenta con los andycoins suficientes para adquirir "
         << compraSolicitada << " bombas.";

    cout << "\nDesea volver a realizar una compra?" << endl;
    if (realizarOperacion() == "S")
        comprarBombas(jugador);
}

//------------------------MENU JUGADOR ---> OPCION 7 -----------------------------

void Menu::consultarCoordenada(Vertice* listaVertices,DatosLeidos baseDeDatos) {
    int posicionX, posicionY;
    char tipoCasilla;
    Vertice* verticeBuscado;
    cout << ">--Consultar coordenada--<\n| Coste de energia: 0 |";
    leerCoordenadas(posicionX,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (tipoCasilla == 'T') {
        cout << "Ha encontrado un casillero construible." << endl;
        if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido())
            cout << "Hay un/una " << verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre()
                 << "construido/a en este casillero.";
        else
            cout << "No hay edificios construidos en este casillero." << endl;
    }
    else if(tipoCasilla == 'C' || tipoCasilla == 'M' || tipoCasilla == 'B'){
        cout << "Ha encontrado un casillero transitable." << endl;
        switch(tipoCasilla){
            case 'C':
                cout << "Tipo: Camino" << endl;
                break;
            case 'M':
                cout << "Tipo: Muelle" << endl;
                break;
            case 'B':
                cout << "Tipo: Betun" << endl;
                break;
        }
        if(verticeBuscado->obtenerCasilleroTransitable()->materialPresente())
            cout << "Hay "<< verticeBuscado->obtenerCasilleroTransitable()->obtenerMaterial()->getCantidad()
                 << " de " << verticeBuscado->obtenerCasilleroTransitable()->obtenerMaterial()->obtenerNombre()
                 << "presente en este casillero. " << endl;
        else
            cout << "No hay materiales en este casillero." << endl;
    }
    else
        cout << "Ha encontrado un casillero inaccesible." << endl;
}

//------------------------MENU JUGADOR ---> OPCION 9 -----------------------------

//------------------------MENU JUGADOR ---> OPCION 10 -----------------------------

void Menu::recolectarRecursos(Vertice* listaVertices,Jugador jugador,DatosLeidos baseDeDatos) {
    Vertice *verticeActual;
    string nombreMaterialGenerable;
    cout << ">--Recolectar recursos--<\n| Coste de energia: 20 |";
    int cantidadMaterialGenerable;
    for (int i = 0; i < baseDeDatos.obtenerCantidadFilas(); i++)
        for (int j = 0; j < baseDeDatos.obtenerCantidadColumnas(); j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices, i, j);
            if (verticeActual->obtenerCasilleroConstruible()->edificioConstruido() &&
                verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() ==
                jugador.obtenerNombreJugador()) {
                nombreMaterialGenerable = verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombreMaterialGenerable();
                cantidadMaterialGenerable = verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerCantidadMaterialGenerable();
                jugador.obtenerListaMateriales()->modificarNodo(nombreMaterialGenerable, cantidadMaterialGenerable,true);
                jugador.restarEnergia(20);
                cout << "->Se han recolectado " << cantidadMaterialGenerable << " de " << nombreMaterialGenerable
                     << " en "
                     << verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre()
                     << " en coordenada (" << i << "," << j << ")" << endl;
            }
        }
}

//-----------------------------FUNCIONES DE USO MULTIPLE------------------------------

string Menu::realizarOperacion(){
    string respuesta;
    cout << "\n(s/n)-> ";
    cin >> respuesta;
    while (toupper(respuesta[0]) != 'S' && toupper(respuesta[0]) != 'N'){
        cout << "Respuesta invalida, debe ingresar s/n";
        cin >> respuesta;
    }
    return respuesta;
}

string Menu::validarEdificio(DiccionarioDeEdificios* diccionarioDeEdificios,string nombreEdificio){
    while (!diccionarioDeEdificios->nodoEnArbol(diccionarioDeEdificios->obtenerNodoRaiz(), nombreEdificio)) {
        cout << nombreEdificio << " no se encuentra registrado. ¿Desea ver los edificios en registro?";
        if (realizarOperacion() == "S")
            diccionarioDeEdificios->recorridoInOrden(diccionarioDeEdificios->obtenerNodoRaiz());
        cout << "\nReingrese el nombre del edificio: " << endl;
        cin >> nombreEdificio;
    }
    return nombreEdificio;
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

void Menu::restarMateriales(DiccionarioDeEdificios* diccionario, Jugador jugador, string nombreEdificio, double porcentajeRestable) {
    int piedraRestable = diccionario->extraerDato(diccionario->obtenerNodoRaiz(), "piedra", nombreEdificio);
    int maderaRestable = diccionario->extraerDato(diccionario->obtenerNodoRaiz(), "madera", nombreEdificio);
    int metalRestable = diccionario->extraerDato(diccionario->obtenerNodoRaiz(), "metal", nombreEdificio);
    jugador.obtenerListaMateriales()->modificarNodo("piedra", piedraRestable*porcentajeRestable, false);
    jugador.obtenerListaMateriales()->modificarNodo("madera", maderaRestable*porcentajeRestable, false);
    jugador.obtenerListaMateriales()->modificarNodo("metal", metalRestable*porcentajeRestable, false);
}