#include "DatosLeidos.h"
#include <fstream>
#include <iostream>

//CONSTRUCTOR
DatosLeidos::DatosLeidos() = default;

//LECTURA DE DATOS
void DatosLeidos::leerArchivo(string nombreArchivo,Jugador primerJugador,Jugador segundoJugador,DiccionarioDeEdificios* diccionarioPartida) {
    ifstream archivo(nombreArchivo);

    if (archivo.fail())
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    else {
        if (nombreArchivo == "materiales.txt")
            cargarListaMateriales(archivo,primerJugador,segundoJugador);
        if (nombreArchivo == "edificios.txt")
            cargarDiccionarioDeEdificios(archivo,diccionarioPartida);
        /*if (nombreArchivo == "ubicaciones.txt")
            //registrarUbicaciones(archivo)*/
        if (nombreArchivo == "mapa.txt") {
            setDimensiones(archivo);
            generarMapa();
            setMapa(archivo);
            separarCasilleros();
        }
    }
    archivo.close();
}

void DatosLeidos::cargarListaMateriales(ifstream &archivo,Jugador primerJugador,Jugador segundoJugador){
    string material, cantidadPrimerJugador, cantidadSegundoJugador;

    while(archivo >> material) {
        archivo >> cantidadPrimerJugador;
        archivo >> cantidadSegundoJugador;
        primerJugador.cargarMaterial(material,stoi(cantidadPrimerJugador));
        segundoJugador.cargarMaterial(material,stoi(cantidadSegundoJugador));
    }
}

//--------------------LECTURA EDIFICIOS--------------------

void DatosLeidos::cargarDiccionarioDeEdificios(ifstream &arcEdificios,DiccionarioDeEdificios *diccionarioPartida) {
    string edificio, piedra, madera, metal, maximo, nombreAdicional;

    while (arcEdificios >> edificio) {
        if (edificio == "planta") {
            arcEdificios >> nombreAdicional;
            edificio = "planta electrica";
        }
        arcEdificios >> piedra;
        arcEdificios >> madera;
        arcEdificios >> metal;
        arcEdificios >> maximo;
        diccionarioPartida->procesarDatoANodo(edificio,stoi(piedra),stoi(madera),stoi(metal),stoi(maximo));
    }
}
/*
void DatosLeidos::cargarEdificios(string edificio, int piedra, int madera, int metal, int maximo) {
    Edificio **copiaEdificios = new Edificio *[cantidadEdificios+1];
    for (int i = 0; i < cantidadEdificios; i++) {
        copiaEdificios[i] = edificios[i];
    }
    copiaEdificios[cantidadEdificios] = new Edificio(edificio,piedra,madera,metal,maximo);

    if (cantidadEdificios != 0)
        delete[] edificios;

    edificios = copiaEdificios;
    cantidadEdificios++;
}
*/

//--------------------LECTURA MAPA--------------------

//Lectura de filas y columnas
void DatosLeidos::setDimensiones(ifstream &arcMapa){
    string filas,columnas;

    arcMapa >> filas;
    arcMapa >> columnas;
    cantidadFilas = stoi(filas);
    cantidadColumnas = stoi(columnas);
}

//Reserva de memoria previa a carga de datos
void DatosLeidos::generarMapa(){

    casilleros = new Casillero**[cantidadFilas];
    for (int i=0;i<cantidadFilas;i++)
        casilleros[i] = new Casillero*[cantidadColumnas];

    for (int i=0;i<cantidadFilas;i++)
        for (int j=0;j<cantidadColumnas;j++)
            casilleros[i][j] = nullptr;
}

//Carga de la matriz
void DatosLeidos::setMapa(ifstream &arcMapa) {
    char terreno;
    int conteoFilas = 0, conteoColumnas = 0;

    while (arcMapa >> terreno) {
        if (terreno == 'C' || terreno == 'M' || terreno == 'B') {
            casilleros[conteoFilas][conteoColumnas] = new CasilleroTransitable(terreno);
            cantidadTransitables++;
        }
        else if (terreno == 'T') {
            casilleros[conteoFilas][conteoColumnas] = new CasilleroConstruible(terreno);
            cantidadConstruibles++;
        }
        else{ // terreno == 'L'
            casilleros[conteoFilas][conteoColumnas] = new CasilleroInaccesible(terreno);
            cantidadInaccesibles++;
        }
        conteoColumnas++;

        if(conteoColumnas == 10) {
            conteoFilas++;
            conteoColumnas = 0;
        }
    }
}

//Carga de arreglos individuales
void DatosLeidos::separarCasilleros() {
    int conteoConstruibles = 0;
    int conteoTransitables = 0;
    int conteoInaccesibles = 0;

    construibles = new CasilleroConstruible*[cantidadConstruibles];
    transitables = new CasilleroTransitable*[cantidadTransitables];
    inaccesibles = new CasilleroInaccesible*[cantidadInaccesibles];

    for (int i=0;i<cantidadFilas;i++)
        for (int j=0;j<cantidadColumnas;j++) {
            char terreno = casilleros[i][j]->getTerreno();
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

//--------------------LECTURA UBICACIONES--------------------
/*
void DatosLeidos::registrarUbicaciones(ifstream& arcUbicaciones){
    string edificio, basura, x, y;
    int contador = 0;

    while (getline(arcUbicaciones, edificio, ' ')) {
        if (edificio == "planta") {
            arcUbicaciones >> basura;
            edificio = "planta electrica";
        }
        getline(arcUbicaciones, basura, '(');
        getline(arcUbicaciones, x, ',');
        getline(arcUbicaciones, y, ')');
        if (contador != 0)
            edificio = edificio.erase(0, 1);
        int posEdificio = posicionEdificio(edificio);
        int posConstruible = posicionConstruible(stoi(x), stoi(y));
        if (posEdificio != -1 && posConstruible != -1 && !haySuperposicion(posConstruible))
            if (edificios[posEdificio]->getCostruidos() < edificios[posEdificio]->getMaximaCantidad()) {
                int piedra = edificios[posEdificio]->getPiedra();
                int madera = edificios[posEdificio]->getMadera();
                int metal = edificios[posEdificio]->getMetal();
                int maximo = edificios[posEdificio]->getMaximaCantidad();
                construibles[posConstruible]->construirEdificio(edificio, piedra, madera, metal, maximo, casilleros);
                edificios[posEdificio]->sumarEdificio();
            }
        contador++;
    }
}

int DatosLeidos::posicionConstruible(int x, int y) {
    for (int i = 0; i < cantidadConstruibles; i++)
        if (construibles[i]->getFila() == x && construibles[i]->getColumna() == y) return i;
    return -1;
}

bool DatosLeidos::haySuperposicion(int posConstruible){
    return construibles[posConstruible]->getEdificio()->getNombre() != "";
}

//--------------------GETTERS--------------------
*/
int DatosLeidos::getCantidadFilas() {
    return cantidadFilas;
}

int DatosLeidos::getCantidadColumnas() {
    return cantidadColumnas;
}

Casillero*** DatosLeidos::getCasilleros() {
    return casilleros;
}

CasilleroConstruible** DatosLeidos::getConstruibles(){
    return construibles;
}

CasilleroTransitable** DatosLeidos::getTransitables(){
    return transitables;
}

CasilleroInaccesible** DatosLeidos::getInaccesibles(){
    return inaccesibles;
}

int DatosLeidos::cantConstruibles(){
    return cantidadConstruibles;
}

int DatosLeidos::cantTransitables(){
    return cantidadTransitables;
}

int DatosLeidos::cantInaccesibles(){
    return cantidadInaccesibles;
}

//--------------------LIBERACION DE MEMORIA--------------------

DatosLeidos::~DatosLeidos() {
    for(int i = 0; i < cantidadConstruibles; i++) {
        if(construibles[i] != nullptr)
            delete construibles[i];
    }
    delete [] construibles;

    for(int i = 0; i < cantidadTransitables; i++) {
        if(transitables[i] != nullptr)
            delete transitables[i];
    }
    delete [] transitables;

    for(int i = 0; i < cantidadInaccesibles; i++) {
        if(inaccesibles[i] != nullptr)
            delete inaccesibles[i];
    }
    delete [] inaccesibles;

    for (int i = 0; i < cantidadFilas; i++) {
        for(int j = 0; j < cantidadColumnas; j++) {
            delete casilleros[i][j];
        }
        delete [] casilleros[i];
    }
    delete [] casilleros;
}

