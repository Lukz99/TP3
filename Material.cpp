#include "Material.h"
#include <string>
#include <iostream>

using namespace std;

Material::Material() = default;

Material::Material(string n, int c){
    nombreMaterial = n;
    cantidadMaterial = c;
    setNombreClave();
}

Material::~Material() = default;

void Material::cargarDatos(string n,int c){
    nombreMaterial = n;
    cantidadMaterial = c;
    setNombreClave();
}

void Material::setNombreClave() {
    if (nombreMaterial == "piedra")
        nombreClave = 'S';
    if (nombreMaterial == "madera")
        nombreClave = 'W';
    if (nombreMaterial == "metal")
        nombreClave = 'I';
    if (nombreMaterial == "andycoins")
        nombreClave = 'C';
}

void Material::mostrarMaterial() {
    cout << "\n->" << nombreMaterial << "\nCantidad: " << cantidadMaterial << endl;
}

string Material::obtenerNombre() {
    return nombreMaterial;
}

char Material::getNombreClave(){
    return nombreClave;
}

int Material::getCantidad() {
    return cantidadMaterial;
}

void Material::sumar(int adicional){
    cantidadMaterial += adicional;
}

void Material::restar(int utilizado){
    cantidadMaterial -= utilizado;
}
