/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include "PresentarOpciones.h"

char OPT_espacio = ' ';

void presentarOpciones() {
printf("\n");
    printf( "GesAMA: Gestion de Alquiler de Máquinas Agrícolas\n");
    printf( "\n" );
    printf( "%5c Editar Máquina %16c (Pulsar M)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Editar Finca %18c (Pulsar F)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Listar Máquinas %15c (Pulsar L)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Estado Fincas %17c (Pulsar E)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Alquiler Máquina %14c (Pulsar A)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Plan Mensual Máquina %10c (Pulsar P)\n", OPT_espacio, OPT_espacio);
    printf( "%5c Salir %25c (Pulsar S)\n", OPT_espacio, OPT_espacio);
    printf("\n");

}

