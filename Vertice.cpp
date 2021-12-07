#include "Vertice.h"

Vertice::Vertice(char tipoTerreno, int x, int y) {
    if (tipoTerreno == 'C' || tipoTerreno == 'M' || tipoTerreno == 'B') {
        transitable = new CasilleroTransitable(tipoTerreno, x, y);
        construible = nullptr;
        inaccesible = nullptr;
    }
    else if(tipoTerreno == 'T') {
        construible = new CasilleroConstruible(tipoTerreno, x, y);
        transitable = nullptr;
        inaccesible = nullptr;
    }
    else{ // tipoTerreno == 'L'
        inaccesible = new CasilleroInaccesible(tipoTerreno, x, y);
        construible = nullptr;
        inaccesible = nullptr;
    }
}