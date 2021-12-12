#ifndef TP3_OBELISCO_H
#define TP3_OBELISCO_H
#include <string>
#include "Edificio.h"

using namespace std;

class Obelisco : public Edificio {
public:
    Obelisco();
    Obelisco(int piedra ,int madera, int metal, int maximoPermitidos);
};

#endif //TP3_OBELISCO_H
