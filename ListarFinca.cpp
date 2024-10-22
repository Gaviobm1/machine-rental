/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include "ListarFinca.h"
#include "EditarFinca.h"

void PrintListaFincas(TipoFinca a, TipoListaFinca v, char t) {
    printf( "\n");
    printf( "Tipo de fincas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)? ");
    scanf( " %c", &t);  
    printf( "\n");
    printf( " Id     Nombre     Tipo       Tamaño            Latitud     Longitud\n\n");
    for (int i = 0; i < FIN_lista; i++) {
        if (t == 'G' && v[i].tipo == 'G') {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Grano      ");
            printf("%2d hectáreas", v[i].hectam);
            if (v[i].hectam >= 100) {
                printf( "     ");
            } else {
                printf( "      ");
            }
            printf( "%.3f      ", v[i].ubilat);
            printf( "%.3f\n", v[i].ubilong);
        } else if (t == 'U' && v[i].tipo == 'U') {
           printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Uva        ");
            printf("%2d hectáreas", v[i].hectam);
            if (v[i].hectam >= 100) {
                printf( "     ");
            } else {
                printf( "      ");
            }
            printf( "%.3f      ", v[i].ubilat);
            printf( "%.3f\n", v[i].ubilong);
        } else if (t == 'A' && v[i].tipo == 'A') {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Aceituna   ");
            printf("%2d hectáreas", v[i].hectam);
            if (v[i].hectam >= 100) {
                printf( "     ");
            } else {
                printf( "      ");
            }
            printf( "%.3f      ", v[i].ubilat);
            printf( "%.3f\n", v[i].ubilong);
        } else if (t == 'T') {
            if (v[i].id != 0) {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            if (v[i].tipo == 'G') {
                printf( "Grano      ");
            } else if (v[i].tipo == 'U') {
                printf( "Uva        ");
            } else if (v[i].tipo == 'A') {
                printf( "Aceituna   ");
            }
            printf("%2d hectáreas", v[i].hectam);
            if (v[i].hectam >= 100) {
                printf( "     ");
            } else {
                printf( "      ");
            }
            printf( "%.3f      ", v[i].ubilat);
            printf( "%.3f\n", v[i].ubilong);
            }
        }
    }
}