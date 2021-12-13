#ifndef TP3_CASILLEROCONSTRUIBLE_H
#define TP3_CASILLEROCONSTRUIBLE_H
#include "Casillero.h"
#include "Edificio.h"

class CasilleroConstruible : public Casillero {
    // Atributos
private:
    Edificio *edificiacion;

    // Metodos
public:
    // Constructor
    CasilleroConstruible(char tipoTerreno);

    ~CasilleroConstruible();

    // Precondiciones:
    // Postcondiciones: imprime por pantalla el  valor del atributo terreno
    void mostrar() override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terreno
    char obtenerTerreno() override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terrenoInicial
    char obtenerInicial() override;

    // Precondiciones:
    // Postcondiciones: modifica el valor del atributo terreno
    void modificar(char terreno) override;

    // Precondiciones: los datos de entrada son validos
    // Postcondiciones: se reserva memoria para el tipo de edificio que se quiere construir
    void construirEdificio(string, Casillero*** casilleros, int coordenadaX, int coordenadaY);

    // Precondiciones: el edificio existe
    // Postcondiciones: se libera memoria para un edificio
    void demolerEdificio(Casillero*** casilleros);

    // Precondiciones:
    // Postcondiciones:
    int obtenerFila();

    // Precondiciones:
    // Postcondiciones:
    int obtenerColumna();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo edificacion
    Edificio* obtenerEdificio();

    // Precondiciones:
    // Postcondiciones: se repara el edificio de ser posible
    void edificiosReparables(bool repararEdificio, Casillero ***casilleros);

    // Precondiciones:
    // Postcondiciones: devuelve true o false dependiendo de si hay o no un edificio construido
    bool edificioConstruido();

};

#endif //TP3_CASILLEROCONSTRUIBLE_H
