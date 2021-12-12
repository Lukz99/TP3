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

void DatosLeidos::cargarListaMateriales(Jugador primerJugador, Jugador segundoJugador) {
    ifstream archivoMateriales("materiales.txt");
    if (aperturaDeArchivoExitosa(archivoMateriales,"materiales.txt")) {
        string material, cantidadPrimerJugador, cantidadSegundoJugador;
        while(archivoMateriales >> material) {
            archivoMateriales >> cantidadPrimerJugador;
            archivoMateriales >> cantidadSegundoJugador;
            primerJugador.cargarMaterial(material, stoi(cantidadPrimerJugador));
            segundoJugador.cargarMaterial(material, stoi(cantidadSegundoJugador));
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
            }
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
        separarCasilleros();
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

// Carga de arreglos individuales
void DatosLeidos::separarCasilleros() {
    int conteoConstruibles = 0;
    int conteoTransitables = 0;
    int conteoInaccesibles = 0;

    construibles = new CasilleroConstruible*[cantidadConstruibles];
    transitables = new CasilleroTransitable*[cantidadTransitables];
    inaccesibles = new CasilleroInaccesible*[cantidadInaccesibles];

    for (int i = 0; i < cantidadFilas; i++)
        for (int j = 0; j < cantidadColumnas; j++) {
            char terreno = casilleros[i][j] -> obtenerTerreno();
            if (terreno == 'T') {
                construibles[conteoConstruibles] = new CasilleroConstruible(terreno);
                conteoConstruibles++;
            }
            if (terreno == 'C' || terreno == 'M' || terreno == 'B') {
                transitables[conteoTransitables] = new CasilleroTransitable(terreno);
                conteoTransitables++;
            }
            if (terreno == 'L') {
                inaccesibles[conteoInaccesibles] = new CasilleroInaccesible(terreno);
                conteoInaccesibles++;
            }
        }
}

// Lectura de ubicaciones.txt
void DatosLeidos::registrarUbicaciones(Vertice* verticeInicial){
    ifstream archivoUbicaciones("ubicaciones.txt");
    if (aperturaDeArchivoExitosa(archivoUbicaciones,"ubicaciones.txt")){
        string edificio, basura, x, y;
        int contador = 0;
        Vertice* verticeEnPosicionActual;
        while (getline(archivoUbicaciones, edificio, ' ')) {
            if (edificio == "planta") {
                archivoUbicaciones >> basura;
                edificio = "planta electrica";
            }
            if (contador != 0)
                edificio = edificio.erase(0, 1);
            getline(archivoUbicaciones, basura, '(');
            getline(archivoUbicaciones, x, ',');
            getline(archivoUbicaciones, y, ')');
            verticeEnPosicionActual = verticeInicial->buscarVerticePorPosicion(verticeInicial, stoi(x), stoi(y));
            if (verticeEnPosicionActual->obtenerCasilla() == 'T' && !verticeEnPosicionActual->edificioConstruido())
                verticeEnPosicionActual->construirEdificio(edificio, casilleros);
            contador++;
        }
    }
    archivoUbicaciones.close();
}
/*
int DatosLeidos::posicionConstruible(int x, int y) {
    for (int i = 0; i < cantidadConstruibles; i++)
        if (construibles[i]->getFila() == x && construibles[i]->getColumna() == y) return i;
    return -1;
}

bool DatosLeidos::haySuperposicion(int posConstruible){
    return construibles[posConstruible]->getEdificio()->getNombre() != "";
}
*/

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
    for(int i = 0; i < cantidadConstruibles; i++) {
        if (construibles[i] != nullptr)
            delete construibles[i];
    }
    delete [] construibles;

    for (int i = 0; i < cantidadTransitables; i++) {
        if (transitables[i] != nullptr)
            delete transitables[i];
    }
    delete [] transitables;

    for (int i = 0; i < cantidadInaccesibles; i++) {
        if (inaccesibles[i] != nullptr)
            delete inaccesibles[i];
    }
    delete [] inaccesibles;

    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnas; j++) {
            delete casilleros[i][j];
        }
        delete [] casilleros[i];
    }
    delete [] casilleros;
}

