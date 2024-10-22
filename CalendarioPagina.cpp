/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include <string.h>
#include "CalendarioPagina.h"


TipoMatrizLargo DiasMesLargo;
TipoMatrizCorto DiasMesCorto;
TipoMatrizFebCorto DiasMesFebCorto;
TipoMesPagina MesPagina;
int cosechaContador = 1;
int contadorTraslados = 0;
int contadorEspera = 0;
int contadorCosechas = 0;



/*================================
Funci�n que devuelve si un a�o es
bisiesto o no
=================================*/

bool EsBisiesto(int y) {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        return true;
    } else  {
        return false;
    }
}

/*============================================
Funci�n que devuelve un numero para ayudar en
determinar el primer d�a de cualquiera�o a
traves de sumar el n�mero de diasde diferencia
desde un punto de partido,en este caso 1601.
==============================================*/

int TipoMesPagina::BuscarIncreDias() {
    int IncreDias = 0;
    for(int i = 1601; i <= MOS_anno; i++) {
        if (EsBisiesto(i- 1) && i != 1601) {
            IncreDias = IncreDias + 2;
        } else if (i != 1601) {
            IncreDias++;
        }
    }
    return IncreDias % 7;
}

/*===========================================
Funci�n que utiliza un n�mero que representa
el primer d�a del a�o para devolver un n�mero
que ayudar� en construir una matriz para
representar cualquier mes.
============================================*/

int TipoMesPagina::BuscarPrimerDia() {
    int PrimerDia = BuscarIncreDias();
    int SubeDias;
    for (int i = 1; i < MOS_mes; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            SubeDias = 31 % 7;
            PrimerDia = PrimerDia + SubeDias;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            SubeDias = 30 % 7;
            PrimerDia = PrimerDia + SubeDias;
        } else if (EsBisiesto(MOS_anno) && i == 2){
            SubeDias = 29 % 7;
            PrimerDia = PrimerDia + SubeDias;
        }
    }
    if (PrimerDia < 7) {
        return PrimerDia - 1;
    } else {
        return (PrimerDia % 7) - 1;
    }
}

/*================================
Procedimiento para pedir un usuario
los datos del mes y a�o que quiere
imprimir.
==================================*/

void TipoMesPagina::BuscarFecha() {
    printf("Plan Mensual Máquina:\n");
    printf( "Identificador máquina? ");
    scanf( "%d", &MOS_maq);
    printf( "Selección Mes? ");
    scanf( "%d", &MOS_mes);
    printf( "Selección Año? ");
    scanf( "%d", &MOS_anno);
    printf( "\n" );
}

/*==================================
Procedimineto para determinar el
tama�o, en d�as, del mes selecionado
por el usuario.
===================================*/

void TipoMesPagina::BuscarDias() {
    switch(MOS_mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            MOS_dias = 30;
        break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            MOS_dias = 31;
        break;
        case 2:
            if (EsBisiesto(MOS_anno)) {
                MOS_dias = 29;
            } else {
                MOS_dias = 28;
            }
        break;
    }
}

/*=========================================
Procedimientos para construir una matriz
utilizando los datos conseguidos de las
funciones BuscarIncreDias y BuscarPrimerDia
==========================================*/

void TipoMesPagina::CrearMatrizLargo(TipoMatrizLargo m) {  /* Matriz de 6 filas */
    int k;
    for(int i = 0; i < NumFilasLargo; i++) {
        for(int j = 0; j < NumColumnas; j++) {
            if (j < BuscarPrimerDia()) {
                m[i][j] = 0;            /* Marcador de posici�n del simbolo '.' */
                                        /* al principio del calendario */
                } else {
                    m[i][j] = j - BuscarPrimerDia();
                }
            if (i > 0) {
                k = (j + 1) + m[i-1][NumColumnas - 1];
                if (k <= MOS_dias) {
                    m[i][j] = k;
                } else {
                    m[i][j] = 0;           /* Marcador de posici�n del simbolo '.' */
                                       /* al final del calendario */
                }
            }
        }
    }
}

void TipoMesPagina::CrearMatrizCorto(TipoMatrizCorto m) { /* Matriz de 5 filas */
    int k;
    for(int i = 0; i < NumFilasCorto; i++) {
        for(int j = 0; j < NumColumnas; j++) {
            if (j < BuscarPrimerDia()) {
                m[i][j] = 0;            /* Marcador de posici�n del simbolo '.' */
                                        /* al principio del calendario */
            } else {
                 m[i][j] = j - BuscarPrimerDia();
            }
            if (i > 0) {
                k = (j + 1) + m[i-1][NumColumnas - 1];
                if (k <= MOS_dias) {
                    m[i][j] = k;
                } else {
                    m[i][j] = 0;           /* Marcador de posici�n del simbolo '.' */
                                       /* al final del calendario */
                }
            }
        }
    }
}

void TipoMesPagina::CrearMatrizFebCorto(TipoMatrizFebCorto m) { /* Matriz de 4 filas */
    int k;
    for(int i = 0; i < NumFilasFebCorto; i++) {
        for(int j = 0; j < NumColumnas; j++) {
            if (j < BuscarPrimerDia()) {
                m[i][j] = 0;            /* Marcador de posici�n del simbolo '.' */
                                        /* al principio del calendario */
            } else {
                 m[i][j] = j - BuscarPrimerDia();
            }
            if (i > 0) {
                k = (j + 1) + m[i-1][NumColumnas - 1];
                if (k <= MOS_dias) {
                    m[i][j] = k;
                } else {
                    m[i][j] = 0;           /* Marcador de posici�n del simbolo '.' */
                                       /* al final del calendario */
                }
            }
        }
    }
}

/*=======================================
Procedimientos para imprimir en la pantalla
la matriz creado por el procedimiento
CrearMatriz
=========================================*/

void TipoMesPagina::ImprimirMatrizLargo(TipoMatrizLargo m) {
    cosechaContador = 1;
    contadorTraslados = 0;
    contadorEspera = 0;
    contadorCosechas = 0;
    if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id  && (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.anno == MOS_mes + MOS_anno || cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.anno == MOS_mes + MOS_anno)) {
        for(int i = 0; i < NumFilasLargo; i++) {
            printf( "\n");
            for (int l = 0; l < 20; l++) {
            printf(" ");
            }
            for(int j = 0; j < NumColumnas; j++) {
                if(j == 4) {
                    if (m[i][j] == 0) {
                        printf(" . ");
                        printf( " " );
                    } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                        printf("%2s  ", "Tr");
                        contadorTraslados = contadorTraslados + 1;
                    } else if ( m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                        printf("%c%d  ", 'C', cosechaContador);
                        contadorCosechas = contadorCosechas + 1;
                        if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                            cursor = cursor->siguiente;
                            cosechaContador = cosechaContador + 1;
                        }
                    } else {
                        printf( "%2d  ", m[i][j]);
                        contadorEspera = contadorEspera + 1;
                } 
                } else if (m[i][j] == 0) {
                    printf(" . ");
                    printf( " ");
                } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                    printf("%2s  ", "Tr");
                    contadorTraslados = contadorTraslados + 1;
                } else if (m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                    printf("%c%d  ", 'C', cosechaContador);
                    contadorCosechas = contadorCosechas + 1;
                    if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                        cursor = cursor->siguiente;
                        cosechaContador = cosechaContador + 1;
                    }
                } else { 
                    printf( "%2d  ", m[i][j]);
                    contadorEspera = contadorEspera + 1;
                }
    } for (int l = 0; l < 20; l++) {
        printf(" ");
    }
    printf( "\n" );
    }
    } else {
        if (cursor == NULL) {
            printf("\n\n Sin alquilos en ese mes\n\n");
            return;
        }
        cursor = cursor->siguiente;
        ImprimirMatrizLargo(m);
    }
}              
            


void TipoMesPagina::ImprimirMatrizCorto(TipoMatrizCorto m) {    
    cosechaContador = 1;
    contadorTraslados = 0;
    contadorEspera = 0;
    contadorCosechas = 0;
    if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id  && (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.anno == MOS_mes + MOS_anno || cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.anno == MOS_mes + MOS_anno)) {
        for(int i = 0; i < NumFilasCorto; i++) {
            printf( "\n");
            for (int l = 0; l < 20; l++) {
            printf(" ");
            }
            for(int j = 0; j < NumColumnas; j++) {
                if(j == 4) {
                    if (m[i][j] == 0) {
                        printf(" . ");
                        printf( " " );
                    } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                        printf("%2s  ", "Tr");
                        contadorTraslados = contadorTraslados + 1;
                    } else if ( m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                        printf("%c%d  ", 'C', cosechaContador);
                        contadorCosechas = contadorCosechas + 1;
                        if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                            cursor = cursor->siguiente;
                            cosechaContador = cosechaContador + 1;
                        }
                    } else {
                        printf( "%2d  ", m[i][j]);
                        contadorEspera = contadorEspera + 1;
                } 
                } else if (m[i][j] == 0) {
                    printf(" . ");
                    printf( " ");
                } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                    printf("%2s  ", "Tr");
                    contadorTraslados = contadorTraslados + 1;
                } else if (m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                    printf("%c%d  ", 'C', cosechaContador);
                    contadorCosechas = contadorCosechas + 1;
                    if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                        cursor = cursor->siguiente;
                        cosechaContador = cosechaContador + 1;
                    }
                } else { 
                    printf( "%2d  ", m[i][j]);
                    contadorEspera = contadorEspera + 1;
                }
    } for (int l = 0; l < 20; l++) {
        printf(" ");
    }
    printf( "\n" );
    }
    } else {
        if (cursor == NULL) {
            printf("\n\n Sin alquilos en ese mes\n\n");
            return;
        }
        cursor = cursor->siguiente;
        ImprimirMatrizCorto(m);
    }
} 

/*=======================================
Procedimiento para imprimir el mes de
febrero cuando el primer dia es lunes
y no es bisiesto debido a que el numero
de filas es 4 en vez de 5 o 6
=========================================*/

void TipoMesPagina::ImprimirMatrizFebCorto(TipoMatrizFebCorto m) {
    cosechaContador = 1;
    contadorTraslados = 0;
    contadorEspera = 0;
    contadorCosechas = 0;
    if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id  && (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.anno == MOS_mes + MOS_anno || cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.anno == MOS_mes + MOS_anno)) {
        for(int i = 0; i < NumFilasFebCorto; i++) {
            printf( "\n");
            for (int l = 0; l < 20; l++) {
            printf(" ");
            }
            for(int j = 0; j < NumColumnas; j++) {
                if(j == 4) {
                    if (m[i][j] == 0) {
                        printf(" . ");
                        printf( " " );
                    } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                        printf("%2s  ", "Tr");
                        contadorTraslados = contadorTraslados + 1;
                    } else if ( m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                        printf("%c%d  ", 'C', cosechaContador);
                        contadorCosechas = contadorCosechas + 1;
                        if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                            cursor = cursor->siguiente;
                            cosechaContador = cosechaContador + 1;
                        }
                    } else {
                        printf( "%2d  ", m[i][j]);
                        contadorEspera = contadorEspera + 1;
                } 
                } else if (m[i][j] == 0) {
                    printf(" . ");
                    printf( " ");
                } else if (MOS_mes == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.mes && m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaTrasCal.dia) {
                    printf("%2s  ", "Tr");
                    contadorTraslados = contadorTraslados + 1;
                } else if (m[i][j] + MOS_mes * 100 <= cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia + (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes * 100) && (m[i][j] + MOS_mes * 100) >= (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.dia + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes * 100)) {
                    printf("%c%d  ", 'C', cosechaContador);
                    contadorCosechas = contadorCosechas + 1;
                    if (m[i][j] == cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.dia && cursor->siguiente != NULL) {
                        cursor = cursor->siguiente;
                        cosechaContador = cosechaContador + 1;
                    }
                } else { 
                    printf( "%2d  ", m[i][j]);
                    contadorEspera = contadorEspera + 1;
                }
    } for (int l = 0; l < 20; l++) {
        printf(" ");
    }
    printf( "\n" );
    }
    } else {
        if (cursor == NULL) {
            printf("\n\n Sin alquilos en ese mes\n\n");
            return;
        }
        cursor = cursor->siguiente;
        ImprimirMatrizFebCorto(m);
    }
} 

/*=====================================
Procedimiento para asignar una cadena
a la variable MOS_NombreMes segun el n�mero
del mes que selecion� el usuario
======================================*/

void TipoMesPagina::BuscarMes() {
    switch (MOS_mes) {
        case 1:
            strcpy(MOS_NombreMes, "Enero");
            break;
        case 2:
            strcpy(MOS_NombreMes, "Febrero");
            break;
        case 3:
            strcpy(MOS_NombreMes, "Marzo");
            break;
        case 4:
            strcpy(MOS_NombreMes, "Abril");
            break;
        case 5:
            strcpy(MOS_NombreMes, "Mayo");
            break;
        case 6:
            strcpy(MOS_NombreMes, "Junio");
            break;
        case 7:
            strcpy(MOS_NombreMes, "Julio");
            break;
        case 8:
            strcpy(MOS_NombreMes, "Agosto");
            break;
        case 9:
            strcpy(MOS_NombreMes, "Septiembre");
            break;
        case 10:
            strcpy(MOS_NombreMes, "Octubre");
            break;
        case 11:
            strcpy(MOS_NombreMes, "Noviembre");
            break;
        case 12:
            strcpy(MOS_NombreMes, "Diciembre");
            break;
    }
}

/*=================================
Procedimiento para imprimir en la
pantalla la cabecera del calendario
==================================*/

void TipoMesPagina::ImprimirCabecera() {
    while (cursor != NULL) {
        if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id) {
            for (int i = 0; i < 25; i++) {
                printf(" ");
            }
            printf( "Plan Máquina: %s\n\n", cursor->detallesAlquiler.MaquinaAlquilada.nombre);
            break;
        }
        cursor = cursor->siguiente;
    }   
    for (int i = 0; i < 20; i++) {
        printf(" ");
    }
    printf( "%-17s", MOS_NombreMes);
    printf( "%10d\n", MOS_anno);
    printf( "\n\n");
    for (int i = 0; i < 20; i++) {
        printf(" ");
    }
    printf( " L   M   X   J   V   S   D");
    printf( "\n");
    for (int i = 0; i < 20; i++) {
        printf(" ");
    }
    for (int i = 0; i < 27; i++) {      /* Imprimir border inferior */
        printf( "=");
    }
}

/*==========================================
Procedimiento para crear y imprimir la hoja
del calendario
============================================*/

void TipoMesPagina::CrearMes() {
    CrearMatrizFebCorto(DiasMesFebCorto);
    if ((MOS_anno >= 1601 && MOS_anno <= 3000) && (MOS_mes >= 1 && MOS_mes <= 12)) {
        if ((MOS_dias == 31 && (BuscarPrimerDia() == 4 || BuscarPrimerDia() == 5)) || (MOS_dias == 30 && BuscarPrimerDia() == 5)) {
            ImprimirCabecera();
            CrearMatrizLargo(DiasMesLargo);
            ImprimirMatrizLargo(DiasMesLargo);
        } else if (!EsBisiesto(MOS_anno) && DiasMesFebCorto[0][0] == 1 && MOS_dias == 28){
            ImprimirCabecera();
            ImprimirMatrizFebCorto(DiasMesFebCorto);
        } else {
            ImprimirCabecera();
            CrearMatrizCorto(DiasMesCorto);
            ImprimirMatrizCorto(DiasMesCorto);
        }
        OrdenCosecha();
        printf("\nTiempo de trasaldos (Tr): %d días\n", contadorTraslados);
        printf("Tiempo de esperas: %d días\n", contadorEspera);
        cursor = secuencia;
        while (cursor != NULL) {
            if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id && ((MOS_mes + MOS_anno) == (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.anno) || (MOS_mes + MOS_anno) == (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.anno))) {
                printf("Cosecha C%d: finca %s\n", cursor->detallesAlquiler.idCosecha, cursor->detallesAlquiler.FincaAlquilada.nombre);
        }
            cursor = cursor->siguiente;
    }
        printf("Tiempo total de cosechas (C#): %d días\n", contadorCosechas);
    }
}

void TipoMesPagina::OrdenCosecha() {
    int contadorIdCos = 1;
    cursor = secuencia;
    while (cursor !=NULL) {
        if (MOS_maq == cursor->detallesAlquiler.MaquinaAlquilada.id && ((MOS_mes + MOS_anno) == (cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaFinCal.anno) || (MOS_mes + MOS_anno) == (cursor->detallesAlquiler.CAL_Alquiler.fechaCal.mes + cursor->detallesAlquiler.CAL_Alquiler.fechaCal.anno))) {
            cursor->detallesAlquiler.idCosecha = contadorIdCos++;
            cursor = cursor->siguiente;
        } else {
            cursor = cursor->siguiente;
        }
    }
}

void GetPagina(TipoMesPagina a) {
    cursor = secuencia;
    a.BuscarFecha();
    a.BuscarDias();
    a.BuscarPrimerDia();
    a.BuscarMes();
    a.CrearMes();
    printf("\n\n");
    printf( "Mostrar otro mes (S/N)? ");
    scanf (" %c", &a.MOS_tecla);
    if (a.MOS_tecla == 'S') {
        GetPagina(a);
    } 
}

