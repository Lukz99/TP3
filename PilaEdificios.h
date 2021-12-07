//
// Created by ekizu on 3/12/2021.
//

#ifndef INC_3MOSQUETEROS_PILAEDIFICIOS_H
#define INC_3MOSQUETEROS_PILAEDIFICIOS_H
#include <string>
#include "NodoPila.h"

using namespace std;

class PilaEdificios {
private:
    NodoPila *nodoInicial;
public:
    PilaEdificios();
    ~PilaEdificios();
    void insertarNodo(string,int);
    void imprimirPila();
    void modificarNodo(string,int,bool);
};


#endif //INC_3MOSQUETEROS_PILAEDIFICIOS_H
