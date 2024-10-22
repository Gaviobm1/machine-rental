/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include "EditarMaquina.h"

char MAQ_espacio = ' ';
char MAQ_tecla;
TipoListaMaquina ListaMaquinas;
TipoMaquina nuevoMaq;



void TipoMaquina::GetId() {
    printf( "Identificador (número enter 1 y 10)? ");
    scanf( " %d", &id);
}

void TipoMaquina::GetNombre() {
    printf( "Nombre (entre 1 y 20 caracteres)? ");
    scanf( " %s", &nombre);
}

void TipoMaquina::GetType() {
    printf( "Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)? " );
    scanf( " %c", &MAQ_tecla);
    if (MAQ_tecla == 'G' || MAQ_tecla == 'U' || MAQ_tecla == 'A') {
        tipo = MAQ_tecla;
    }
}

void TipoMaquina::GetCapacity() {
    printf( "Capacidad (héctares/día)? ");
    scanf( " %d", &hecdia);
}

void TipoMaquina::GetUbilat() {
    printf( "Ubicación inicial (Latitud)? ");
    scanf( " %f", &ubilat);
}

void TipoMaquina::GetUbilong() {
    printf( "Ubicación inicial (Longitud)? ");
    scanf( " %f", &ubilong);
}

void insertStruct(TipoMaquina a, TipoListaMaquina v) {
    v[a.id - 1] = a;
}


void GuardarOBorrar(TipoMaquina a, TipoListaMaquina v) {
    printf( "\nIMPORTANTE: Esta opción borra los datos anteriores.\n Son Correctos los nuevos datos (S/N)? ");
    scanf( " %c", &MAQ_tecla);
    if (MAQ_tecla == 'S') {
        insertStruct(a, v);
    } else {
       return; 
    }
}

void EditarMaquina(TipoMaquina a, TipoListaMaquina v) {
    printf( "\n");
    printf( "Editar máquina:\n\n");
    printf("%6c", MAQ_espacio);
    a.GetId();
    printf("%6c", MAQ_espacio);
    a.GetNombre();
    printf("%6c", MAQ_espacio);
    a.GetType();
    if (MAQ_tecla != 'G' && MAQ_tecla != 'U' && MAQ_tecla != 'A') {
        return;
    }
    printf("%6c", MAQ_espacio);
    a.GetCapacity();
    printf("%6c", MAQ_espacio);
    a.GetUbilat();
    printf("%6c", MAQ_espacio);
    a.GetUbilong();
    GuardarOBorrar(a, v);
}





