#ifndef TP3_MATERIAL_H
#define TP3_MATERIAL_H
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
    void definirNombreClave();
    string obtenerNombre();
    char obtenerNombreClave();
    int obtenerCantidad();
    void sumar(int);
    void restar(int);
};

#endif //TP3_MATERIAL_H
