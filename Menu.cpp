#include "Menu.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;

Menu::Menu() {
    srand(time(nullptr));
    opcionElegida = 0;
}

Menu::~Menu() = default;

//------------------OPCION MENU DIGITADA---------------------

void Menu::definirOpcion() {
    cout << "\nOpcion numero (->) ";
    cin >> opcionElegida;
}

void Menu::opcionValida(int cantidadOpciones){
    bool opcion_valida = opcionElegida > 0 && opcionElegida <= cantidadOpciones;
    while(!opcion_valida) {
        cout << "\nEl numero de opcion elegido no corresponde con los mostrados en pantalla." << endl
             << "Por favor, vuelva a intentarlo." << endl;
        definirOpcion();
        opcion_valida = opcionElegida > 0 && opcionElegida <= cantidadOpciones;
    }
}

int Menu::obtenerOpcion() {
    return opcionElegida;
}

//-------------------------MENU PRINCIPAL----------------------------

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

void Menu::procesarOpcionMenuPrincipal(Vertice* listaVertices,DiccionarioDeEdificios *diccionario,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador) {
    switch (opcionElegida) {
        case 1:
            modificarEdificio(diccionario);
            break;
        case 2:
            diccionario->recorridoInOrden(diccionario->obtenerNodoRaiz());
            break;
        case 3:
            mostrarMapa(listaVertices,baseDeDatos.obtenerCasilleros(),baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
            break;
        case 4:
            comenzarPartida(listaVertices,baseDeDatos,primerJugador,segundoJugador);
            break;
        case 5:
            diccionario->guardarDatosDiccionario(diccionario->obtenerNodoRaiz());
            cout << "\nProgreso guardado correctamente.\n";
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
    if (realizarOperacion() == 'S'){
        cout << "Ingrese la nueva cantidad de " << nombreMaterial << ":" << endl;
        cin >> cantidadNuevaMaterial;
        while (cantidadNuevaMaterial < 0 || cantidadNuevaMaterial > 50000) {
            cout << "No se puede ingresar mas de 50000 unidades ni menos que 0, intente nuevamente. \n";
            cout << "Ingrese la nueva cantidad de " << nombreMaterial << ":" << endl;
            cin >> cantidadNuevaMaterial;
        }
    }
    else
        cantidadNuevaMaterial = cantidadMaterialOriginal;
    return cantidadNuevaMaterial;
}

//------------------------MENU PRINCIPAL ---> OPCION 3 -----------------------------

void Menu::mostrarMapa(Vertice* listaVertices,Casillero*** casilleros, int cantFilas, int cantColumnas){
    Vertice* verticeActual;
    cout << "\n--MATERIALES Y EDIFICIOS--\nX: sin elementos" << endl;
    for(int i=0; i<cantFilas;i++) {
        for (int j = 0; j < cantColumnas; j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices,i,j);
            if ((verticeActual->obtenerCasilla() == 'T' && verticeActual->obtenerCasilleroConstruible()->edificioConstruido()))
                cout << verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombreClave() << " ";
            else if((verticeActual->obtenerCasilla() == 'C' || verticeActual->obtenerCasilla() == 'M' || verticeActual->obtenerCasilla() == 'B') && verticeActual->obtenerCasilleroTransitable()->materialPresente())
                cout << verticeActual->obtenerCasilleroTransitable()->obtenerMaterial()-> obtenerNombreClave() << " ";
            else
                cout << "X ";
        }
        cout << "\n";
    }
    cout << "\n--MAPA TERRENOS--" << endl;
    for(int i = 0; i < cantFilas; i++) {
        for (int j = 0; j < cantColumnas; j++) {
            cout << casilleros[i][j] -> obtenerInicial();
            cout << " ";
        }
        cout << "\n";
    }
}

//---------------FUNCIONES PRE-PARTIDA----------------

void Menu::comenzarPartida(Vertice* listaVertices,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador) {
    cout << "\n>--COMENZAR PARTIDA--<" << endl;
    eleccionJugador(primerJugador, segundoJugador);
    designarTurnos(primerJugador, segundoJugador);
    //lluviaRecursos(listaVertices, baseDeDatos);
}

void Menu::eleccionJugador(Jugador *primerJugador,Jugador *segundoJugador){
    cout << "\n--Elija nombre de jugador--\n1. Jugador 1\n2. Jugador 2" << endl;
    definirOpcion();
    opcionValida(2);
    if (opcionElegida == 1){
        cout << "Ha elegido ser Jugador 1. El otro jugador sera el Jugador 2." << endl;
        primerJugador->asignarNombre("Jugador 1");
        segundoJugador->asignarNombre("Jugador 2");
    }
    else{
        cout << "Ha elegido ser Jugador 2. El otro jugador sera el Jugador 1." << endl;
        primerJugador->asignarNombre("Jugador 2");
        segundoJugador->asignarNombre("Jugador 1");
    }
}

void Menu::designarTurnos(Jugador *primerJugador,Jugador *segundoJugador){
    int sorteoDeTurno = rand() % (1);
    cout << "\nDesignacion de turnos." << endl;
    if (sorteoDeTurno == 0){
        primerJugador->asignarTurno(1);
        segundoJugador->asignarTurno(2);
        cout << "->" << primerJugador->obtenerNombreJugador() << "inicia turno \2\n->Lo sigue "
        << segundoJugador->obtenerNombreJugador() << endl;
    }
    else{
        segundoJugador->asignarTurno(1);
        primerJugador->asignarTurno(2);
        cout << "->" << segundoJugador->obtenerNombreJugador() << " inicia turno \2\n ->Lo sigue "
        << primerJugador->obtenerNombreJugador() <<  endl;
    }
}

void Menu::gestionDeTurnos(Grafo vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador *jugadorActual, DatosLeidos baseDeDatos){
    bool finalizarTurno = false;
    cout << "| TURNO DE: " << jugadorActual -> obtenerNombreJugador() << " |" << endl;
    while(!jugadorActual -> jugadorSinEnergias() || !finalizarTurno) {
        mostrarMenuJugador();
        definirOpcion();
        opcionValida(13);
        procesarOpcionMenuJugador(vertices, diccionarioDeEdificios, jugadorActual, baseDeDatos, finalizarTurno);
    }
}

void Menu::lluviaRecursos(Vertice* listaVertices,DatosLeidos baseDeDatos) {
    int generacionPiedra = 1 + rand() % (2 - 1);
    int generacionMadera = rand() % (3);
    int generacionMetal = 2 + rand() % (4 - 2);
    int generacionAndycoins = rand() % (1);
    int totalGenerado = generacionPiedra + generacionMadera + generacionMetal + generacionAndycoins;
    seleccionarCoordenadasAleatoriamente(listaVertices,"piedra",generacionPiedra,100,baseDeDatos);
    seleccionarCoordenadasAleatoriamente(listaVertices,"madera",generacionMadera,50,baseDeDatos);
    seleccionarCoordenadasAleatoriamente(listaVertices,"metal",generacionMetal,50,baseDeDatos);
    seleccionarCoordenadasAleatoriamente(listaVertices,"andycoins",generacionAndycoins,250,baseDeDatos);
    cout << "Se han generado " << totalGenerado << " recursos materiales a lo largo del mapa." << endl
         << "| Piedra: " << generacionPiedra << " | Madera: " << generacionMadera
         << " | Metal: " << generacionMetal << " | Andycoins: " << generacionAndycoins << " |" <<  endl;
    mostrarMapa(listaVertices,baseDeDatos.obtenerCasilleros(),baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
}

void Menu::seleccionarCoordenadasAleatoriamente(Vertice* listaVertices,string nombreMaterial,int generacionMaterial,int equivalenciaUnitaria,DatosLeidos baseDeDatos) {
    int posicionX, posicionY;
    int contadorCiclos;
    bool sinCasillerosTransitables = false;
    Vertice *verticeBuscado;
    char casilla;
    for(int i=0; i<generacionMaterial;i++) {
        posicionX = rand() % (baseDeDatos.obtenerCantidadFilas()-1);
        posicionY = rand() % (baseDeDatos.obtenerCantidadColumnas()-1);
        verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices, posicionX, posicionY);
        casilla = verticeBuscado->obtenerCasilla();
        while ((casilla != 'C' && casilla != 'M' && casilla != 'B') ||
               verticeBuscado->obtenerCasilleroTransitable()->materialPresente()) {
            posicionX = rand() % (baseDeDatos.obtenerCantidadFilas()-1);
            posicionY = rand() % (baseDeDatos.obtenerCantidadColumnas()-1);
            verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices, posicionX, posicionY);
            casilla = verticeBuscado->obtenerCasilla();
            contadorCiclos++;
            if (contadorCiclos == 50)
                sinCasillerosTransitables = true;
        }
        verticeBuscado->obtenerCasilleroTransitable()->generarMaterial(nombreMaterial,
                                                                       generacionMaterial * equivalenciaUnitaria,
                                                                       baseDeDatos.obtenerCasilleros(), posicionX,
                                                                       posicionY);
        contadorCiclos = 0;
    }
}

//------------------------MENU JUGADOR-----------------------------

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

void Menu::procesarOpcionMenuJugador(Grafo vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador* jugador, DatosLeidos baseDeDatos, bool &finalizarTurno){
    switch(opcionElegida){
        case 1:
            construirEdificio(diccionarioDeEdificios,vertices,jugador,baseDeDatos);
            break;
        case 2:
            diccionarioDeEdificios->listarConstruidos(diccionarioDeEdificios->obtenerNodoRaiz(),jugador->obtenerNombreJugador());
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
            jugador->mostrarMateriales();
            break;
        case 9:
            jugador->mostrarMateriales();
            break;
        case 10:
            recolectarRecursos(vertices.obtenerListaVertices(),jugador,baseDeDatos);
            break;
        case 11:
            jugador->obtenerListaMateriales()->imprimirLista();
            break;
        case 12:
            finalizarTurno = true;
            break;
        case 13:
            guardarMapa(baseDeDatos);
            //guardarUbicaciones(vertices.obtenerListaVertices(),jugador,baseDeDatos);
            break;
    }
}

//------------------------MENU JUGADOR ---> OPCION 1 -----------------------------

void Menu::construirEdificio(DiccionarioDeEdificios* diccionario,Grafo vertices,Jugador *jugador,DatosLeidos baseDeDatos) {
    string nombreEdificio;
    int coordenadaX, coordenadaY;
    bool respetaMaximaCantidad;
    cout << ">--Construir un edificio--<\n\nIngrese el nombre del edificio que desea construir: ";
    cin >> nombreEdificio;
    nombreEdificio = validarEdificio(diccionario, nombreEdificio);
    respetaMaximaCantidad = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,"maxima permitido") - diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,"construidos "+jugador->obtenerNombreJugador()) > 0;
    if (materialesSuficientes(diccionario,jugador,nombreEdificio)){
        if(respetaMaximaCantidad) {
            if(jugador->suficienteEnergia(15)) {
                cout << "\nEs posible construir un/una " << nombreEdificio
                     << ". Desea continuar?\n| Coste de energia: 15 |";
                if (realizarOperacion() == 'S') {
                    cout << "\nIngrese las coordenadas donde sea construir el edificio." << endl;
                    leerCoordenadas(coordenadaX, coordenadaY, baseDeDatos.obtenerCantidadFilas(),
                                    baseDeDatos.obtenerCantidadColumnas());
                    if (coordenadaConstruible(vertices.obtenerListaVertices(), diccionario, coordenadaX, coordenadaY,
                                              jugador,
                                              nombreEdificio, baseDeDatos.obtenerCasilleros())) {
                        jugador->restarEnergia(15);
                        cout << "Edificio construido correctamente en coordenada (" << coordenadaX << "," << coordenadaY
                             << ")"
                             << endl;
                        restarMateriales(diccionario, jugador, nombreEdificio, 1);
                    } else
                        cout << "El terreno de la coordenada (" << coordenadaX << "," << coordenadaY
                             << ") no es construible. No se le han restado energías.";
                }
                else
                    cout << "Ha abortado la construccion del edificio. No se le restaron energias." << endl;
            }else
                cout << "No puede construir este edificio porque no cuenta con las energias suficientes." << endl;
        }else
            cout << "No puede construir este tipo de edificio porque se ha alcanzado el maximo permitido." << endl;
    }
    else cout <<"No cuenta con los materiales suficientes para construir este edificio." << endl;
}

bool Menu::materialesSuficientes(DiccionarioDeEdificios* diccionario,Jugador *jugador,string nombreEdificio){
    bool suficientePiedra = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"piedra");
    bool suficienteMadera = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"madera");
    bool suficienteMetal = realizarDiferenciaMateriales(diccionario,jugador,nombreEdificio,"metal");
    return suficientePiedra && suficienteMadera && suficienteMetal;
}

bool Menu::realizarDiferenciaMateriales(DiccionarioDeEdificios* diccionario,Jugador *jugador, string nombreEdificio,string nombreMaterial){
    //cantidad materiales del jugador - cantidad materiales en diccionario de edificios
    int diferenciaMateriales = jugador->obtenerListaMateriales()->extraerCantidadMaterial(nombreMaterial) - diccionario->extraerDato(diccionario->obtenerNodoRaiz(),nombreEdificio,nombreMaterial);
    return diferenciaMateriales >= 0;
}

bool Menu::coordenadaConstruible(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,int coordenadaX, int coordenadaY, Jugador *jugador,string nombreEdificio, Casillero*** casilleros){
    Vertice* verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,coordenadaX,coordenadaY);
    bool esPosibleConstruir;
    if (verticeBuscado->obtenerCasilla() == 'T' && !verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido()) {
        esPosibleConstruir = true;
        verticeBuscado->construirEdificio(nombreEdificio,casilleros,coordenadaX,coordenadaY);
        verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->declararPropietario(jugador->obtenerNombreJugador());
        diccionario->modificacionEnConstruidos(diccionario->obtenerNodoRaiz(),jugador->obtenerNombreJugador(),verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre(),true);
    }
    else
        esPosibleConstruir = false;
    return esPosibleConstruir;
}

//------------------------MENU JUGADOR ---> OPCION 3 -----------------------------

void Menu::demolerEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionario, Jugador *jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << ">--Demoler un edificio--<\nIngrese las coordenadas del edificio a demoler." << endl;
    leerCoordenadas(posicionX,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilla() == 'T') {
        if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido() &&
            verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() ==
            jugador->obtenerNombreJugador()) {
            if(jugador->suficienteEnergia(15)) {
                nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
                cout << "Usted posee un/una " << nombreEdificio
                     << " en la coordenada (" << posicionX << "," << posicionY << ")\nDesea demoler este edificio?"
                     << "\n| Coste de energia: 15 |" << endl;
                if (realizarOperacion() == 'S') {
                    verticeBuscado->demolerEdificio(baseDeDatos.obtenerCasilleros());
                    diccionario->modificacionEnConstruidos(diccionario->obtenerNodoRaiz(),
                                                           jugador->obtenerNombreJugador(),
                                                           nombreEdificio, false);
                    devolverMateriales(diccionario, jugador, nombreEdificio);
                    jugador->restarEnergia(15);
                    cout << "Edificio demolido exitosamente." << endl;
                } else
                    cout << "Ha decidido abortar la demolicion. No se le han restado energias." << endl;
            }else
                cout << "No es posible demoler debido a que no cuenta con las energias suficientes." << endl;
        } else
            cout << "No hay ningun edificio construido de su propiedad en estas coordenadas." << endl;
    }
    else
        cout << "El terreno donde desea demoler no es del tipo construible." << endl;

}

void Menu::devolverMateriales(DiccionarioDeEdificios* diccionario,Jugador *jugador, string nombreEdificio){
    int devolucionPiedra = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"piedra",nombreEdificio) / 2;
    int devolucionMadera = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"madera",nombreEdificio) / 2;
    int devolucionMetal = diccionario->extraerDato(diccionario->obtenerNodoRaiz(),"metal",nombreEdificio) / 2;
    jugador->obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionPiedra,true);
    jugador->obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionMadera,true);
    jugador->obtenerListaMateriales()->modificarNodo(nombreEdificio,devolucionMetal,true);
}

//------------------------MENU JUGADOR ---> OPCION 4 -----------------------------

void Menu::atacarEdificio(Vertice* listaVertices,Jugador *jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << "\n\t\t>--Atacar edificio!--<\n\n| Coste de energia: 30 |\nIngrese las coordenadas del edificio que desea atacar." << endl;
    leerCoordenadas(posicionX,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido()) {
        if (verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() !=
            jugador->obtenerNombreJugador()) {
            nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
            if(nombreEdificio == "mina oro" || nombreEdificio == "mina" || nombreEdificio == "fabrica")
                verticeBuscado->obtenerCasilleroConstruible()->edificiosReparables(false,baseDeDatos.obtenerCasilleros());
            else{
                verticeBuscado->demolerEdificio(baseDeDatos.obtenerCasilleros());
                cout << "Edificio atacado y destruido exitosamente." << endl;
            }
            jugador->restarEnergia(30);
        } else
            cout << "Usted es el propietario del edificio en esta coordenada." << endl;
    }
    else
        cout << "No hay un edificio construido en las coordenadas (" << posicionX << "," << posicionY << ")" << endl;
}

//------------------------MENU JUGADOR ---> OPCION 5 -----------------------------

void Menu::repararEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,Jugador *jugador,DatosLeidos baseDeDatos){
    int posicionX, posicionY;
    Vertice* verticeBuscado;
    string nombreEdificio;
    cout << ">--Reparar edificio!--<\n| Coste de energia: 25 |\nIngrese las coordenadas del edificio que desea reparar." << endl;
    leerCoordenadas(posicionY,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido() && materialesSuficientes(diccionario,jugador,nombreEdificio))
        if (verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() ==
            jugador->obtenerNombreJugador()) {
            nombreEdificio = verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre();
            if(nombreEdificio == "mina oro" || nombreEdificio == "mina" || nombreEdificio == "fabrica"){
                verticeBuscado->obtenerCasilleroConstruible()->edificiosReparables(true,baseDeDatos.obtenerCasilleros());
                restarMateriales(diccionario,jugador,nombreEdificio,0.25);
                jugador->restarEnergia(25);
            }else
                cout << "Este edificio no es reparable." << endl;
        } else
            cout << "Usted NO es el propietario del edificio en esta coordenada." << endl;
    else
        cout << "No hay un edificio construido en las coordenadas (" << posicionX << "," << posicionY << ")" << endl;
}

//------------------------MENU JUGADOR ---> OPCION 6 -----------------------------

void Menu::comprarBombas(Jugador *jugador){
    int compraSolicitada;
    int cantidadAndycoinsActuales = jugador->obtenerListaMateriales()->extraerCantidadMaterial("andycoins");
    int cantidadBombasActuales = jugador->obtenerListaMateriales()->extraerCantidadMaterial("bombas");
    int disponibilidadDeCompra = cantidadAndycoinsActuales/100;
    cout << "\t\t>--Comprar bombas--<\n\nPrecio por unidad: 100 andycoins." << endl;
    cout << "->Usted dispone de: " << cantidadAndycoinsActuales << " andycoins.\nPuede comprar hasta: "
         << disponibilidadDeCompra << " bombas.\n\n| Coste de energia: 5 |\n->Ingrese la cantidad de bombas que desea adquirir: ";
    cin >> compraSolicitada;
    if (compraSolicitada <= disponibilidadDeCompra){
        if(jugador->suficienteEnergia(5)) {
            jugador->obtenerListaMateriales()->modificarNodo("andycoins", compraSolicitada*100, false);//false = restar
            jugador->obtenerListaMateriales()->modificarNodo("bombas",compraSolicitada,true);
            jugador->restarEnergia(5);
            cout << "Ha adquirido " << compraSolicitada << " bombas exitosamente.";
            cout << " Saldo de andycoins actual: "
                 << jugador->obtenerListaMateriales()->extraerCantidadMaterial("andycoins");
        }
        else
            cout << "Ha fracasado la compra debido a que no cuenta con las energias necesarias para realizar esta opcion" << endl;
    }
    else
        cout << "Ha fracasado la compra debido a que no cuenta con los andycoins suficientes para adquirir "
         << compraSolicitada << " bombas.";

    cout << "\nDesea volver a realizar una compra?" << endl;
    if (realizarOperacion() == 'S')
        comprarBombas(jugador);
}

//------------------------MENU JUGADOR ---> OPCION 7 -----------------------------

void Menu::consultarCoordenada(Vertice* listaVertices,DatosLeidos baseDeDatos) {
    int posicionX, posicionY;
    char tipoCasilla;
    Vertice* verticeBuscado;
    cout << ">--Consultar coordenada--<\n\n| Coste de energia: 0 |" << endl;
    leerCoordenadas(posicionX,posicionY,baseDeDatos.obtenerCantidadFilas(),baseDeDatos.obtenerCantidadColumnas());
    verticeBuscado = listaVertices->buscarVerticePorPosicion(listaVertices,posicionX,posicionY);
    tipoCasilla = verticeBuscado->obtenerCasilla();
    if (tipoCasilla == 'T') {
        cout << "\n->Ha encontrado un casillero construible." << endl;
        if (verticeBuscado->obtenerCasilleroConstruible()->edificioConstruido())
            cout << "Hay un/una " << verticeBuscado->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre()
                 << " construido/a en este casillero.";
        else
            cout << "No hay edificios construidos en este casillero." << endl;
    }
    else if(tipoCasilla == 'C' || tipoCasilla == 'M' || tipoCasilla == 'B'){
        cout << "\nHa encontrado un casillero transitable." << endl;
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
        if(verticeBuscado -> obtenerCasilleroTransitable() -> materialPresente())
            cout << "Hay "<< verticeBuscado -> obtenerCasilleroTransitable() -> obtenerMaterial()-> obtenerCantidad()
                 << " de " << verticeBuscado -> obtenerCasilleroTransitable() -> obtenerMaterial() -> obtenerNombre()
                 << " presente en este casillero. " << endl;
        else
            cout << "No hay materiales en este casillero." << endl;
    }
    else
        cout << "\nHa encontrado un casillero inaccesible." << endl;
}

//------------------------MENU JUGADOR ---> OPCION 9 -----------------------------

//------------------------MENU JUGADOR ---> OPCION 10 -----------------------------

void Menu::recolectarRecursos(Vertice* listaVertices,Jugador *jugador,DatosLeidos baseDeDatos) {
    Vertice *verticeActual;
    string nombreMaterialGenerable;
    cout << ">--Recolectar recursos--<\n| Coste de energia: 20 |";
    int cantidadMaterialGenerable;
    for (int i = 0; i < baseDeDatos.obtenerCantidadFilas(); i++)
        for (int j = 0; j < baseDeDatos.obtenerCantidadColumnas(); j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices, i, j);
            if (verticeActual->obtenerCasilleroConstruible()->edificioConstruido() &&
                verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerPropietario() ==
                jugador->obtenerNombreJugador()) {
                nombreMaterialGenerable = verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombreMaterialGenerable();
                cantidadMaterialGenerable = verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerCantidadMaterialGenerable();
                jugador->obtenerListaMateriales()->modificarNodo(nombreMaterialGenerable, cantidadMaterialGenerable,true);
                jugador->restarEnergia(20);
                cout << "->Se han recolectado " << cantidadMaterialGenerable << " de " << nombreMaterialGenerable
                     << " en "
                     << verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre()
                     << " en coordenada (" << i << "," << j << ")" << endl;
            }
        }
}

//------------------------MENU JUGADOR ---> OPCION 11 -----------------------------

void Menu::guardarMapa(DatosLeidos baseDeDatos) {
    ofstream arcMapa("mapa.txt");
    arcMapa << baseDeDatos.obtenerCantidadFilas() << " " << baseDeDatos.obtenerCantidadColumnas() << endl;
    for (int i = 0; i < baseDeDatos.obtenerCantidadFilas(); i++) {
        for (int j = 0; j < baseDeDatos.obtenerCantidadColumnas(); j++) {
            arcMapa << baseDeDatos.obtenerCasilleros()[i][j]->obtenerInicial() << " ";
        }
        arcMapa << "\n";
    }
    arcMapa.close();
}


void Menu::guardarUbicaciones(Vertice* listaVertices,Jugador *primerJugador,Jugador *segundoJugador,DatosLeidos baseDeDatos){
    ofstream archivoUbicaciones("ubicaciones.txt");
    guardarMaterialesDelMapa(archivoUbicaciones,listaVertices,baseDeDatos);
    guardarEdificiosJugador(archivoUbicaciones,listaVertices,primerJugador,baseDeDatos);
    guardarEdificiosJugador(archivoUbicaciones,listaVertices,segundoJugador,baseDeDatos);
}

void Menu::guardarMaterialesDelMapa(ofstream& archivoUbicaciones,Vertice* listaVertices,DatosLeidos baseDeDatos){
    char tipoCasilla;
    Vertice* verticeActual;
    for (int i=0;i<baseDeDatos.obtenerCantidadFilas();i++)
        for (int j=0;j<baseDeDatos.obtenerCantidadColumnas();j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices, i, j);
            tipoCasilla = verticeActual->obtenerCasilla();
            if((tipoCasilla == 'M' || tipoCasilla == 'C' || tipoCasilla == 'B') && verticeActual->obtenerCasilleroTransitable()->materialPresente()){
                archivoUbicaciones << verticeActual->obtenerCasilleroTransitable()->obtenerMaterial()->obtenerNombre()
                                   << " (" << i << "," << ")" << endl;
            }
        }
}

void Menu::guardarEdificiosJugador(ofstream& archivoUbicaciones,Vertice* listaVertices,Jugador *jugador,DatosLeidos baseDeDatos) {
    Vertice *verticeActual;
    if (jugador->obtenerNombreJugador() == "Jugador 1")
        archivoUbicaciones << "1 (";
    else
        archivoUbicaciones << "2 (";
    //archivoUbicaciones << jugador.obtenerPosicionX() << "," << jugador.obtenerPosicionY() << endl;
    for (int i = 0; i < baseDeDatos.obtenerCantidadFilas(); i++)
        for (int j = 0; j < baseDeDatos.obtenerCantidadColumnas(); j++) {
            verticeActual = listaVertices->buscarVerticePorPosicion(listaVertices, i, j);
            if (verticeActual->obtenerCasilla() == 'T' &&
                verticeActual->obtenerCasilleroConstruible()->edificioConstruido() &&
                verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre() ==
                jugador->obtenerNombreJugador())
                archivoUbicaciones << verticeActual->obtenerCasilleroConstruible()->obtenerEdificio()->obtenerNombre()
                                   << " (" << i << "," << ")" << endl;
        }
}
/*
void Menu::guardarMateriales(Jugador primerJugador,Jugador segundoJugador ){
    ofstream archivoMateriales("materiales.txt");
    primerJugador.obtenerListaMateriales().

}*/

//-----------------------------FUNCIONES DE USO MULTIPLE------------------------------

char Menu::realizarOperacion() {
    string respuesta;
    char inicialRespuesta;
    cout << "\n(s/n)-> ";
    cin >> respuesta;
    while (respuesta != "S" && respuesta != "s" && respuesta != "N" && respuesta != "n"){
        cout << "Respuesta invalida, debe ingresar (s/n):";
        cin >> respuesta;
    }
    inicialRespuesta = toupper(respuesta[0]);
    return inicialRespuesta;
}

string Menu::validarEdificio(DiccionarioDeEdificios* diccionarioDeEdificios, string nombreEdificio) {
    while (!diccionarioDeEdificios->nodoEnArbol(diccionarioDeEdificios -> obtenerNodoRaiz(), nombreEdificio)) {
        cout << nombreEdificio << " no se encuentra registrado. ¿Desea ver los edificios en registro?";
        if (realizarOperacion() == 'S')
            diccionarioDeEdificios->recorridoInOrden(diccionarioDeEdificios->obtenerNodoRaiz());
        cout << "\nReingrese el nombre del edificio: " << endl;
        cin >> nombreEdificio;
    }
    return nombreEdificio;
}

void Menu::leerCoordenadas(int &x, int &y, int maxFilas, int maxColumnas) {
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

void Menu::restarMateriales(DiccionarioDeEdificios* diccionario, Jugador *jugador, string nombreEdificio, double porcentajeRestable) {
    int piedraRestable = diccionario->extraerDato(diccionario -> obtenerNodoRaiz(), "piedra", nombreEdificio);
    int maderaRestable = diccionario->extraerDato(diccionario -> obtenerNodoRaiz(), "madera", nombreEdificio);
    int metalRestable = diccionario->extraerDato(diccionario -> obtenerNodoRaiz(), "metal", nombreEdificio);
    jugador->obtenerListaMateriales()->modificarNodo("piedra", piedraRestable*porcentajeRestable, false);
    jugador->obtenerListaMateriales()->modificarNodo("madera", maderaRestable*porcentajeRestable, false);
    jugador->obtenerListaMateriales()->modificarNodo("metal", metalRestable*porcentajeRestable, false);
}