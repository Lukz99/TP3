//
// Created by juamp on 12/12/2021.
//

#ifndef TP3_OBJETIVOS_H
#define TP3_OBJETIVOS_H

#include <string>
using namespace std;


class Objetivos {
private:
    string listaObjetivos[4];
    int objetivosCumplidos = 0;
    bool ganar;

public:
    Objetivos();
    string generarObjetivo();
    void asignarObjetivo();
    void mostrarObjetivos();
    void confirmarObjetivos(int numeroObjetivo);
    void confirmarVictoria();

};


#endif //TP3_OBJETIVOS_H
