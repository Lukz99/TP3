#ifndef NODOARBOL_H
#define NODOARBOL_H


class NodoArbol {
public:
    //atributos
    string nombreEdificio;
    Edificio* recetaEdificio;
    NodoArbol* derecho;
    NodoArbol* izquierdo;
    //metodos
    NodoArbol(string,int,int,int,int);
    ~NodoArbol();
    void cargarReceta(int,int,int,int);
    Edificio* obtenerReceta();
};


#endif //NODOARBOL_H
