/*************************************
 * Interfaz de módulo: 
**************************************/

#pragma once
const int MAQ_lista = 10;

typedef char MAQ_TipoNombre[21];

typedef struct TipoMaquina {
    void GetType();
    void GetId();
    void GetNombre();
    void GetCapacity();
    void GetUbilat();
    void GetUbilong();
    
    int id, hecdia;
    float ubilat, ubilong;
    MAQ_TipoNombre nombre;
    char tipo;
};


typedef TipoMaquina TipoListaMaquina[MAQ_lista];

extern TipoListaMaquina ListaMaquinas;
extern TipoMaquina nuevoMaq;

void EditarMaquina(TipoMaquina a, TipoListaMaquina v);



