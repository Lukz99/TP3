#include "Material.h"
#include <string>

using namespace std;

Material::Material() = default;

Material::Material(string n, int c){
    nombre = n;
    cantidad = c;
    setNombreClave();
}

Material::~Material() = default;

void Material::cargarDatos(string n,int c){
    nombre = n;
    cantidad = c;
    setNombreClave();
}

void Material::setNombreClave() {
    if (nombre == "piedra")
        nombreClave = 'S';
    if (nombre == "madera")
        nombreClave = 'W';
    if (nombre == "metal")
        nombreClave = 'I';
}

string Material::getNombre() {
    return nombre;
}

char Material::getNombreClave(){
    return nombreClave;
}

int Material::getCantidad() {
    return cantidad;
}

void Material::sumar(int adicional){
    cantidad += adicional;
}

void Material::restar(int utilizado){
    cantidad -= utilizado;
}
