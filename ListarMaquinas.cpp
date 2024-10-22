/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include "ListarMaquinas.h"
#include "EditarMaquina.h"

void PrintListaMaquinas(TipoMaquina a, TipoListaMaquina v, char t) {
    printf( "\n");
    printf( "Tipo de máquinas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)? ");
    scanf( " %c", &t);  
    printf( "\n");
    printf( " Id     Nombre     Tipo       Capacidad\n\n");
    for (int i = 0; i < MAQ_lista; i++) {
        if (t == 'G' && v[i].tipo == 'G') {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Grano      ");
            printf("%-3d hectáreas/día\n", v[i].hecdia);
        } else if (t == 'U' && v[i].tipo == 'U') {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Uva        ");
            printf("%-3d hectáreas/día\n", v[i].hecdia);
        } else if (t == 'A' && v[i].tipo == 'A') {
            printf( " %-7d", v[i].id);
            printf( "%-11s", v[i].nombre);
            printf( "Aceituna   ");
            printf("%-3d hectáreas/día\n", v[i].hecdia);
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
            printf("%2d hectáreas/día\n", v[i].hecdia);
            }
        }
    }
}