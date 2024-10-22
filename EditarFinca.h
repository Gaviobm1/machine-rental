/*************************************
 * Interfaz de módulo: 
**************************************/

#pragma once

const int FIN_lista = 20;
typedef char WordType[21];


typedef struct TipoFinca {
    int id, hectam;
    float ubilat, ubilong;
    WordType nombre;
    char tipo;

    void GetType();
    void GetId();
    void GetNombre();
    void GetTamano();
    void GetUbilat();
    void GetUbilong();
};

typedef TipoFinca TipoListaFinca[FIN_lista];
extern TipoListaFinca ListaFincas;
extern TipoFinca nuevoFinca;

void EditarFinca(TipoFinca a, TipoListaFinca v);