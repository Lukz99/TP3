//
// Created by juamp on 12/12/2021.
//

#include "Objetivos.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<time.h>

Objetivos::Objetivos() {
    srand (time(NULL));
}

string Objetivos::generarObjetivo() {

    int numero;
    string objetivo;

    numero = rand() % 10 + 1;

    switch (numero) {
        case 1:
            objetivo = "Comprar Andypolis";
            break;
        case 2:
            objetivo = "Edad de piedra";
            break;
        case 3:
            objetivo = "Bombardero";
            break;
        case 4:
            objetivo = "Energetico";
            break;
        case 5:
            objetivo = "Letrado";
            break;
        case 6:
            objetivo = "Minero";
            break;
        case 7:
            objetivo = "Cansado";
            break;
        case 8:
            objetivo = "Constructor";
            break;
        case 9:
            objetivo = "Armado";
            break;
        case 10:
            objetivo = "Extremista";
            break;
    }

    return objetivo;
}


void Objetivos::asignarObjetivo() {

    string objetivo1, objetivo2, objetivo3;

    objetivo1 = generarObjetivo();
    objetivo2 = generarObjetivo();
    objetivo3 = generarObjetivo();

    while(objetivo1 == objetivo2 or objetivo1 == objetivo3 or objetivo2 == objetivo3){
        objetivo2 = generarObjetivo();
        objetivo3 = generarObjetivo();
    }


    listaObjetivos[0] = "Mas alto que las nubes";
    listaObjetivos[1] = objetivo1;
    listaObjetivos[2] = objetivo2;
    listaObjetivos[3] = objetivo3;


}

void Objetivos::mostrarObjetivos() {

    for(int i = 0; i < 4; i++ ){
        cout << listaObjetivos[i] << endl;
    }
}

void Objetivos::confirmarObjetivos(int numeroObjetivo, Jugador J1) {

    string objetivo = listaObjetivos[numeroObjetivo];

    if (objetivo == "Comprar andypolis"){
        //acumuladorAndycoins
        objetivosCumplidos += 1;

    }
    else if (objetivo == "Edad de piedra"){
        int cantPiedra = J1.obtenerListaMateriales()->extraerCantidadMaterial("piedra");
        if (cantPiedra == 5000){
            objetivosCumplidos += 1;
        }
    }
    else if (objetivo == "Bombardero"){
        //bombasUsadas
        objetivosCumplidos += 1;


    }
    else if (objetivo == "Energetico"){
        if (J1.obtenerEnergia() == 100){
            objetivosCumplidos += 1;

        }
    }
    else if (objetivo == "Letrado"){
        
        objetivosCumplidos += 1;


    }
    else if (objetivo == "Minero"){
        //ConstruirTodasMinas
        objetivosCumplidos += 1;


    }
    else if (objetivo == "Cansado"){

        objetivosCumplidos += 1;


    }
    else if (objetivo == "Constructor"){
            //construidoTodosEdificios
        objetivosCumplidos += 1;


    }
    else if (objetivo == "Armado"){

        objetivosCumplidos += 1;


    }
    else if (objetivo == "Extremista"){
        //bombrasCompradas
        objetivosCumplidos += 1;


    }
        //obelisco
    else{
        objetivosCumplidos = 2;

    }
}

/*
void Objetivos::confirmarVictoria(){
    if (objetivosCumplidos >= 2){
        ganar = true;
    }
}

*/