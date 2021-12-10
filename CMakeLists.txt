cmake_minimum_required(VERSION 3.20)
project(TP3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP3
        Aserradero.cpp
        Aserradero.h
        Casillero.cpp
        Casillero.h
        CasilleroConstruible.cpp
        CasilleroConstruible.h
        CasilleroInaccesible.cpp
        CasilleroInaccesible.h
        CasilleroTransitable.cpp
        CasilleroTransitable.h
        DatosLeidos.cpp
        DatosLeidos.h
        DiccionarioDeEdificios.cpp
        DiccionarioDeEdificios.h
        Edificio.cpp
        Edificio.h
        Escuela.cpp
        Escuela.h
        Fabrica.cpp
        Fabrica.h
        Grafo.cpp
        Grafo.h
        Jugador.cpp
        Jugador.h
        ListaMateriales.cpp
        ListaMateriales.h
        main.cpp
        Material.cpp
        Material.h
        Menu.cpp
        Menu.h
        Mina.cpp
        Mina.h
        MinaOro.cpp
        MinaOro.h
        NodoArbol.cpp
        NodoArbol.h
        NodoLista.cpp
        NodoLista.h
        Obelisco.cpp
        Obelisco.h
        PlantaElectrica.cpp
        PlantaElectrica.h
        Vertice.cpp
        Vertice.h)
