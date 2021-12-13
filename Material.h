#ifndef UNTITLED_MATERIAL_H
#define UNTITLED_MATERIAL_H
#include <string>

using namespace std;

class Material {
private:
    string nombreMaterial = "";
    char nombreClave;
    int cantidadMaterial;
public:
    Material();
    Material(string, int);
    ~Material();
    void cargarDatos(string, int);
    void mostrarMaterial();
    void setNombreClave();
    string obtenerNombre();
    char getNombreClave();
    int getCantidad();
    void sumar(int);
    void restar(int);
};

#endif //UNTITLED_MATERIAL_H
