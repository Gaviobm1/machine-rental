/**************************************************
 * Módulo: 
 * 
**************************************************/

#include <stdio.h>
#include <string.h>
#include "CalendarioMes.h"
#include "AlquilerMaquina.h"

bool TipoCalendario::GetBisiesto() {
    if (fechaCal.anno % 4 == 0 && (fechaCal.anno % 100 != 0 || fechaCal.anno % 400 == 0)) {
        return true;
    } else  {
        return false;
    }
}

void TipoCalendario::GetFecha() {
    printf( "      Fecha comienzo cosecha: Día? ");
    scanf ( " %d", &fechaCal.dia);
    printf( "      Fecha comienzo cosecha: Mes? ");
    scanf ( " %d", &fechaCal.mes);
    printf( "      Fecha comienzo cosecha: Año? ");
    scanf ( " %d", &fechaCal.anno);
    
}

void TipoCalendario::ImprimirDias(int dias) {
    for (int i = 1; i <= dias; i++) {
        if (i % 7 == 0) {
            printf( "%3d\n", i);
        } else {
        printf("%3d", i);
        }
    }
}

void TipoCalendario::NombreDias() {
    printf( "MO TU WE TH FR | SA SU");
}

void TipoCalendario::ImprimirMes() {

switch (fechaCal.mes) {
    case(4):
    case(6):
    case(9):
    case(11):
        ImprimirDias(30);
    break;
    case(1):
    case(3):
    case(5):
    case(7):
    case(8):
    case(10):
    case(12):
        ImprimirDias(31);
    break;
    case(2):
        if (GetBisiesto()) {
            ImprimirDias(29);
        } else {
            ImprimirDias(28);
    }
    break;
}
}

int TipoCalendario::GetNumDias() {
    switch (fechaCal.mes) {
        case(4):
        case(6):
        case(9):
        case(11):
            return 30;
        break;
        case(1):
        case(3):
        case(5):
        case(7):
        case(8):
        case(10):
        case(12):
            return 31;
        break;
        case(2):
            if (GetBisiesto()) {
                return 29;
            } else {
                return 28;
            }
        break;
    }
}

int TipoCalendario::GetNumDiasTras() {
    switch (fechaCal.mes - 1) {
        case(4):
        case(6):
        case(9):
        case(11):
            return 30;
            break;
        case(1):
        case(3):
        case(5):
        case(7):
        case(8):
        case(10):
        case(12):
            return 31;
            break;
        case(2):
            if (GetBisiesto()) {
                return 29;
            } else {
                return 28;
            }
        break;
    }
}