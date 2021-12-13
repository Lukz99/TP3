#ifndef CASILLEROTRANSITABLE_H
#define CASILLEROTRANSITABLE_H
#include "Casillero.h"
#include "Material.h"

class CasilleroTransitable : public Casillero {
    // Atributos
private:
    Material* material;

    //Metodos
public:
    // Constructor
    CasilleroTransitable(char tipoTerreno);

    ~CasilleroTransitable();

    // Precondiciones:
    // Postcondiciones: imprime por pantalla el valor del atributo terreno
    void mostrar() override;

    // Precondiciones:
    // Postcondiciones: modifica el valor del atributo terreno
    void modificar(char terreno) override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terreno
    char obtenerTerreno() override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terrenoInicial
    char obtenerInicial() override;

    // Precondiciones: los datos de entrada son validos
    // Postcondiciones: reserva memoria para colocar un material en un casillero transitable
    void generarMaterial(string, int cantidadMaterial, Casillero***, int posicionX, int posicionY);

    // Precondiciones:
    // Postcondiciones:
    void recolectarMaterial(Casillero***);

    // Precondiciones:
    // Postcondiciones:
    int obtenerFila();

    // Precondiciones:
    // Postcondiciones:
    int obtenerColumna();

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo material
    Material* obtenerMaterial();

    // Precondiciones:
    // Postcondiciones: devuelve true o false dependiendo de si hay o no un material en el casillero
    bool materialPresente();
};

#endif //CASILLEROTRANSITABLE_H
