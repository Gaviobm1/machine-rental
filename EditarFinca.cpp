/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include "EditarFinca.h"

char FIN_espacio = ' ';
char FIN_tecla;
TipoListaFinca ListaFincas;
TipoFinca nuevoFinca;

void TipoFinca::GetId() {
    printf( "Identificador (número enter 1 y 10)? ");
    scanf( " %d", &id);
}

void TipoFinca::GetNombre() {
    printf( "Nombre (entre 1 y 20 caracteres)? ");
    scanf( " %s", &nombre);
}

void TipoFinca::GetType() {
    printf( "Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)? " );
    scanf( " %c", &FIN_tecla);
    if (FIN_tecla == 'G' || FIN_tecla == 'U' || FIN_tecla == 'A') {
        tipo = FIN_tecla;
    }
}

void TipoFinca::GetTamano() {
    printf( "Tamaño (héctares)? ");
    scanf( " %d", &hectam);
}

void TipoFinca::GetUbilat() {
    printf( "Ubicación (Latitud)? ");
    scanf( " %f", &ubilat);
}

void TipoFinca::GetUbilong() {
    printf( "Ubicación (Longitud)? ");
    scanf( " %f", &ubilong);
}

void InsertStruct(TipoFinca a, TipoListaFinca v) {
    v[a.id - 1] = a;
}

void GuardarOBorrar(TipoFinca a, TipoListaFinca v) {
    printf( "\nIMPORTANTE: Esta opción borra los datos anteriores.\n Son Correctos los nuevos datos (S/N)? ");
    scanf( " %c", &FIN_tecla);
    if (FIN_tecla == 'S') {
        InsertStruct(a, v);
    } else {
       return; 
    }
}

void EditarFinca(TipoFinca a, TipoListaFinca v) {
    printf( "\n");
    printf( "Editar finca:\n\n");
    printf("%6c", FIN_espacio);
    a.GetId();
    printf("%6c", FIN_espacio);
    a.GetNombre();
    printf("%6c", FIN_espacio);
    a.GetType();
    if (FIN_tecla != 'G' && FIN_tecla != 'U' && FIN_tecla != 'A') {
        return;
    }
    printf("%6c", FIN_espacio);
    a.GetTamano();
    printf("%6c", FIN_espacio);
    a.GetUbilat();
    printf("%6c", FIN_espacio);
    a.GetUbilong();
    GuardarOBorrar(a, v);
}





