#include "DatosLeidos.h"
#include <fstream>
#include <iostream>

// Constructor
DatosLeidos::DatosLeidos() = default;

// Lectura de datos
bool DatosLeidos::aperturaDeArchivoExitosa(ifstream& archivo,string nombreArchivo) {
    bool archivoAbierto;
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        archivoAbierto = false;
    } else
        archivoAbierto = true;
    return archivoAbierto;
}

void DatosLeidos::cargarListaMateriales(Jugador *primerJugador, Jugador *segundoJugador) {
    ifstream archivoMateriales("materiales.txt");
    if (aperturaDeArchivoExitosa(archivoMateriales,"materiales.txt")) {
        string material, cantidadPrimerJugador, cantidadSegundoJugador;
        while(archivoMateriales >> material) {
            archivoMateriales >> cantidadPrimerJugador;
            archivoMateriales >> cantidadSegundoJugador;
            primerJugador->cargarMaterial(material, stoi(cantidadPrimerJugador));
            segundoJugador->cargarMaterial(material, stoi(cantidadSegundoJugador));
        }
    }
    archivoMateriales.close();
}

void DatosLeidos::cargarDiccionarioDeEdificios(DiccionarioDeEdificios *diccionarioPartida) {
    ifstream archivoEdificios("edificios.txt");
    if (aperturaDeArchivoExitosa(archivoEdificios,"edificios.txt")) {
        string edificio, piedra, madera, metal, maximo, nombreAdicional;

        while (archivoEdificios >> edificio) {
            if (edificio == "planta") {
                archivoEdificios >> nombreAdicional;
                edificio = "planta electrica";
                archivoEdificios >> piedra;
            }
            else if(edificio == "mina") {
                archivoEdificios >> nombreAdicional;
                if (nombreAdicional == "oro") {
                    edificio = "mina oro";
                    archivoEdificios >> piedra;
                }
                else
                    piedra = nombreAdicional;
            }
            else
                archivoEdificios >> piedra;
            archivoEdificios >> madera;
            archivoEdificios >> metal;
            archivoEdificios >> maximo;
            diccionarioPartida -> procesarDatoANodo(edificio, stoi(piedra), stoi(madera), stoi(metal), stoi(maximo));
        }
    }
    archivoEdificios.close();
}

// Lectura del mapa

void DatosLeidos::crearMapa() {
    ifstream archivoMapa("mapa.txt");
    if (aperturaDeArchivoExitosa(archivoMapa,"mapa.txt")){
        definirDimensiones(archivoMapa);
        generarMapa();
        definirMapa(archivoMapa);
    }
    archivoMapa.close();
}

// Lectura de filas y columnas
void DatosLeidos::definirDimensiones(ifstream &arcMapa) {
    string filas,columnas;

    arcMapa >> filas;
    arcMapa >> columnas;
    cantidadFilas = stoi(filas);
    cantidadColumnas = stoi(columnas);
}

// Reserva de memoria previa a carga de datos
void DatosLeidos::generarMapa() {

    casilleros = new Casillero**[cantidadFilas];
    for (int i = 0; i < cantidadFilas; i++)
        casilleros[i] = new Casillero*[cantidadColumnas];

    for (int i = 0; i < cantidadFilas; i++)
        for (int j = 0; j<cantidadColumnas; j++)
            casilleros[i][j] = nullptr;
}

// Carga de la matriz
void DatosLeidos::definirMapa(ifstream &archivoMapa) {
    char terreno;
    int conteoFilas = 0, conteoColumnas = 0;

    while (archivoMapa >> terreno) {
        if (terreno == 'C' || terreno == 'M' || terreno == 'B') {
            casilleros[conteoFilas][conteoColumnas] = new CasilleroTransitable(terreno);
            cantidadTransitables++;
        } else if (terreno == 'T') {
            casilleros[conteoFilas][conteoColumnas] = new CasilleroConstruible(terreno);
            cantidadConstruibles++;
        } else { // terreno == 'L'
            casilleros[conteoFilas][conteoColumnas] = new CasilleroInaccesible(terreno);
            cantidadInaccesibles++;
        }
        conteoColumnas++;

        if (conteoColumnas == 10) {
            conteoFilas++;
            conteoColumnas = 0;
        }
    }
}

// Lectura de ubicaciones.txt
void DatosLeidos::registrarUbicaciones(Vertice* listaVertices,DiccionarioDeEdificios* diccionarioDeEdificios){
    ifstream archivoUbicaciones("ubicaciones.txt");
    string coordenadaX, coordenadaY;
    Vertice* verticeEnPosicionActual;
    if (aperturaDeArchivoExitosa(archivoUbicaciones,"ubicaciones.txt")){
        generarMaterialesEnMapa(archivoUbicaciones,listaVertices,verticeEnPosicionActual,coordenadaX,coordenadaY);
        generarEdificiosJugador(archivoUbicaciones,diccionarioDeEdificios,listaVertices,verticeEnPosicionActual,coordenadaX,coordenadaY);
    }
    archivoUbicaciones.close();
}

void DatosLeidos::generarMaterialesEnMapa(ifstream &archivoUbicaciones,Vertice* listaVertices,Vertice* verticeEnPosicionActual,string coordenadaX,string coordenadaY){
    string nombreMaterial, basura;
    Vertice* verticePosicionBuscada;
    int tipoCasilla;
    getline(archivoUbicaciones,nombreMaterial,' ');
    while (nombreMaterial != "1"){
        getline(archivoUbicaciones, basura, '(');
        getline(archivoUbicaciones, coordenadaX, ',');
        getline(archivoUbicaciones, coordenadaY, ')');
        verticePosicionBuscada = listaVertices->buscarVerticePorPosicion(listaVertices, stoi(coordenadaX), stoi(coordenadaY));
        tipoCasilla = verticePosicionBuscada->obtenerCasilla();
        if ((tipoCasilla == 'T' || tipoCasilla == 'M' || tipoCasilla == 'B') && !verticePosicionBuscada->obtenerCasilleroTransitable()->materialPresente()){
            verticePosicionBuscada->obtenerCasilleroTransitable()->generarMaterial(nombreMaterial,1,casilleros,stoi(coordenadaX),stoi(coordenadaY));
        }
        getline(archivoUbicaciones,nombreMaterial,' ');
        nombreMaterial = nombreMaterial.erase(0, 1);
    }
}

void DatosLeidos::generarEdificiosJugador(ifstream &archivoUbicaciones,DiccionarioDeEdificios* diccionario,Vertice* listaVertices, Vertice* verticeEnPosicionActual,string coordenadaX, string coordenadaY) {
    string nombreJugadorActual = "Jugador 1", nombreEdificio, basura;
    Vertice *verticePosicionBuscada;
    getline(archivoUbicaciones, basura, '(');
    getline(archivoUbicaciones, coordenadaX, ',');
    getline(archivoUbicaciones, coordenadaY, ')');
    while (getline(archivoUbicaciones, nombreEdificio, ' ')) {
        nombreEdificio = nombreEdificio.erase(0, 1);
        if (nombreEdificio == "2") {
            nombreJugadorActual = "Jugador 2";
            getline(archivoUbicaciones, basura, '(');
            getline(archivoUbicaciones, coordenadaX, ',');
            getline(archivoUbicaciones, coordenadaY, ')');
        }else {
            if (nombreEdificio == "planta") {
                archivoUbicaciones >> basura;
                nombreEdificio = "planta electrica";
                getline(archivoUbicaciones, basura, '(');

            } else if (nombreEdificio == "mina") {
                getline(archivoUbicaciones, basura, '(');
                if (basura == "oro ")
                    nombreEdificio = "mina oro";
            } else
                getline(archivoUbicaciones, basura, '(');
            getline(archivoUbicaciones, coordenadaX, ',');
            getline(archivoUbicaciones, coordenadaY, ')');
            verticePosicionBuscada = listaVertices->buscarVerticePorPosicion(listaVertices, stoi(coordenadaX),
                                                                             stoi(coordenadaY));
            if (verticePosicionBuscada->obtenerCasilla() == 'T' &&
                !verticePosicionBuscada->obtenerCasilleroConstruible()->edificioConstruido()) {
                verticePosicionBuscada->construirEdificio(nombreEdificio, casilleros, stoi(coordenadaX),
                                                          stoi(coordenadaY));
                verticePosicionBuscada->obtenerCasilleroConstruible()->obtenerEdificio()->declararPropietario(
                        nombreJugadorActual);
                diccionario->modificacionEnConstruidos(diccionario->obtenerNodoRaiz(),nombreJugadorActual,nombreEdificio,true);
            }
        }

    }
}

// Getters

int DatosLeidos::obtenerCantidadFilas() {
    return cantidadFilas;
}

int DatosLeidos::obtenerCantidadColumnas() {
    return cantidadColumnas;
}

Casillero*** DatosLeidos::obtenerCasilleros() {
    return casilleros;
}

CasilleroConstruible** DatosLeidos::obtenerConstruibles() {
    return construibles;
}

CasilleroTransitable** DatosLeidos::obtenerTransitables() {
    return transitables;
}

CasilleroInaccesible** DatosLeidos::obtenerInaccesibles() {
    return inaccesibles;
}

int DatosLeidos::cantConstruibles() {
    return cantidadConstruibles;
}

int DatosLeidos::cantTransitables() {
    return cantidadTransitables;
}

int DatosLeidos::cantInaccesibles() {
    return cantidadInaccesibles;
}

// Liberacion de memoria

DatosLeidos::~DatosLeidos() {
    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnas; j++) {
            delete casilleros[i][j];
        }
        delete [] casilleros[i];
    }
    delete [] casilleros;
}

