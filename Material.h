#ifndef TP3_MATERIAL_H
#define TP3_MATERIAL_H
#include <string>

using namespace std;

class Material {
    // Atributos
private:
    string nombreMaterial = "";
    char nombreClave;
    int cantidadMaterial;

    // Metodos
public:
    // Constructor sin parametros
    Material();

    // Constructor con parametros
    Material(string nombreMaterial, int cantidadMaterial);

    ~Material();

    // Precondiciones:
    // Postcondiciones: define el nombre y cantidad de un material
    void cargarDatos(string nombreMaterial, int cantidadMaterial);

    // Precondiciones:
    // Postcondiciones: imprime por pantalla nombre y cantidad de un material
    void mostrarMaterial();

    // Precondiciones:
    // Postcondiciones: establece el nombreClave de un material teniendo en cuenta su nombre
    void definirNombreClave();

    // Precondiciones:
    // Postcondiciones: devuelve el nombre del material
    string obtenerNombre();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreClave
    char obtenerNombreClave();

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad del material
    int obtenerCantidad();

    // Precondiciones:
    // Postcondiciones: le suma una cantidad de material
    void sumar(int cantidad);

    // Precondiciones:
    // Postcondiciones: le resta una cantidad de material
    void restar(int cantidad);
};

#endif //TP3_MATERIAL_H
