#ifndef ARBOLDEEDIFICIOS_H
#define ARBOLDEEDIFICIOS_H


class ArbolDeEdificios {
public:
    //atributo
    Nodo* raiz;
    //metodos
    ArbolDeEdificios();
    void insertarNodo(Nodo*&,string,int,int,int,int);
    void mostrarArbol(Nodo*,int);
    bool modificarNodo(Nodo*,string,int,int,int);
    void recorridoInOrden(Nodo*);
};

#endif //ARBOLDEEDIFICIOS_H
