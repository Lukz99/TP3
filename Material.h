#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H
#include <string>

using namespace std;

class Material {
private:
    string nombre = "";
    char nombreClave;
    int cantidad;
public:
    Material();
    Material(string,int);
    void cargarDatos(string,int);
    ~Material();
    void setNombreClave();
    string getNombre();
    char getNombreClave();
    int getCantidad();
    void sumar(int);
    void restar(int);
};

#endif //UNTITLED_MATERIAL_H
