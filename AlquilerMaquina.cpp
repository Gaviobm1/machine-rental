/********************************************************************************
 * Módulo: AlquilerMaquina
 * 
 *  Este módulo define el tipo abstracto Alquiler capaz 
 *  de almanecar los datos de un alquiler y contiene las 
 *  funciones y procedimientos para generar y añadir los 
 *  datos de un alquiler a una secuncia enlazada
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <Math.h>
#include "AlquilerMaquina.h"
#include "PresentarOpciones.h"

TipoAlquiler nuevoAlquilo;
TipoCalendario nuevoCalendario;
TipoSecuencia secuencia = NULL;
TipoPuntNodo cursor, anterior, nuevo;
WordType nave = "Nave empresarial";
char ALQ_tecla;
float ladox, ladoy, ladoz, distancia;

void TipoAlquiler::GetFinca() {
    printf( "      Identificador de finca (número enter 1 y 20)? ");
    scanf( " %d", &n);
    for (int i = 0; i < FIN_lista; i++) {
        if (ListaFincas[i].id != n) {
            continue;
        } else {
            FincaAlquilada = ListaFincas[i];
        }
    }
}

void TipoAlquiler::GetMaquina() {
    printf( "      Identificador de máquina(número entre 1 y 10)? ");
    scanf( " %d", &n);
    for (int i =0; i < MAQ_lista; i++) {
        if (ListaMaquinas[i].id != n) {
            continue;
        } else {
            MaquinaAlquilada = ListaMaquinas[i];
        }
    }
}

float TipoAlquiler::GetDistanciaFincas() {
    ladox = (FincaActual.ubilat - FincaAlquilada.ubilat);
    ladoy = (FincaActual.ubilong - FincaAlquilada.ubilong);
    ladoz = (ladox * ladox) + (ladoy * ladoy);
    distancia = sqrt(ladoz) * 110;
    return distancia;
}

int TipoAlquiler::GetDuracionCosecha() {
    float tamano = FincaAlquilada.hectam;
    float capacidad = MaquinaAlquilada.hecdia;
    float duracion = tamano/capacidad;
    return ceil(duracion);
}

void TipoAlquiler::GetFechaFinal() {
    int num = CAL_Alquiler.fechaCal.dia + GetDuracionCosecha();
    int numDias = 0;
    if (num > CAL_Alquiler.GetNumDias()) {
    while (num > numDias) {
        numDias = CAL_Alquiler.GetNumDias();
        num = num - numDias;
        CAL_Alquiler.fechaFinCal.mes = CAL_Alquiler.fechaCal.mes + 1;
        CAL_Alquiler.fechaFinCal.anno = CAL_Alquiler.fechaCal.anno;
        if (CAL_Alquiler.fechaFinCal.mes > 12) {
            CAL_Alquiler.fechaFinCal.mes = 1;
            CAL_Alquiler.fechaFinCal.anno = CAL_Alquiler.fechaCal.anno + 1;
        }
    }
    CAL_Alquiler.fechaFinCal.dia = num - 1;
    } else {
        CAL_Alquiler.fechaFinCal.dia = CAL_Alquiler.fechaCal.dia + GetDuracionCosecha() - 1;
        CAL_Alquiler.fechaFinCal.mes = CAL_Alquiler.fechaCal.mes;
        CAL_Alquiler.fechaFinCal.anno = CAL_Alquiler.fechaCal.anno;
    }
}

void TipoAlquiler::GetDiaTraslado() {
    if (CAL_Alquiler.fechaCal.dia == 1) {
        if (CAL_Alquiler.fechaCal.mes == 1) {
            CAL_Alquiler.fechaTrasCal.dia = 31;
            CAL_Alquiler.fechaTrasCal.mes = 12;
            CAL_Alquiler.fechaTrasCal.anno = CAL_Alquiler.fechaCal.anno - 1;
        } else {
            CAL_Alquiler.fechaTrasCal.mes = CAL_Alquiler.fechaCal.mes - 1;
            CAL_Alquiler.fechaTrasCal.dia = CAL_Alquiler.GetNumDiasTras();
            CAL_Alquiler.fechaTrasCal.anno = CAL_Alquiler.fechaCal.anno;
        }
    } else {
        CAL_Alquiler.fechaTrasCal.mes = CAL_Alquiler.fechaCal.mes;
        CAL_Alquiler.fechaTrasCal.dia = CAL_Alquiler.fechaCal.dia -1;
        CAL_Alquiler.fechaTrasCal.anno = CAL_Alquiler.fechaCal.anno;
    }
}

void TipoAlquiler::ActualizarUbicacion() {
    idFinal = CAL_Alquiler.fechaFinCal.dia + (CAL_Alquiler.fechaFinCal.mes *100)+ (CAL_Alquiler.fechaFinCal.anno * 100);
    strcpy(FincaActual.nombre, nave);
    FincaActual.id = 0;
    FincaActual.ubilat = MaquinaAlquilada.ubilat;
    FincaActual.ubilong = MaquinaAlquilada.ubilong;
    cursor = secuencia;
    while (cursor != NULL) {
    if (MaquinaAlquilada.id == cursor->detallesAlquiler.MaquinaAlquilada.id && idFinal > cursor->detallesAlquiler.idFinal) {
       strcpy( FincaActual.nombre, cursor->detallesAlquiler.FincaAlquilada.nombre);
       FincaActual.id= cursor->detallesAlquiler.FincaAlquilada.id;
       FincaActual.ubilat = cursor->detallesAlquiler.FincaAlquilada.ubilat;
       FincaActual.ubilong = cursor->detallesAlquiler.FincaAlquilada.ubilong;
    }
    anterior = cursor;
    cursor = cursor->siguiente;
}
}

void PonerEnSecuencia(TipoAlquiler a) {
    a.idFinal = a.CAL_Alquiler.fechaFinCal.dia + (a.CAL_Alquiler.fechaFinCal.mes *100)+ (a.CAL_Alquiler.fechaFinCal.anno * 100);
    cursor = secuencia;
    anterior = NULL;
    nuevo = new TipoNodo;
    nuevo->detallesAlquiler = a ;

    while (cursor != NULL && cursor->detallesAlquiler.idAlquilo < a.idAlquilo) {
        anterior = cursor;
        cursor = cursor->siguiente;
    }
    if (anterior == NULL) {
        nuevo->siguiente = secuencia;
        secuencia = nuevo;
    } else {
    nuevo->siguiente = anterior->siguiente;
    anterior->siguiente = nuevo;
    }
}

void TipoAlquiler::BuscarFinca(TipoListaFinca v) {
    strcpy(FincaActual.nombre, nave);
    FincaActual.id = 0;
    for ( int i = 0; i < FIN_lista; i++) {
        if (MaquinaAlquilada.ubilat == v[i].ubilat && MaquinaAlquilada.ubilong == v[i].ubilong) {
            strcpy(FincaActual.nombre, v[i].nombre);
            FincaActual.id = v[i].id;
            break;
        } else {
            continue;
        }
    }
}

void ComprobarDisponibilidad(TipoAlquiler a, TipoListaMaquina m, TipoListaFinca f) {
    a.idFinal = a.CAL_Alquiler.fechaFinCal.dia + (a.CAL_Alquiler.fechaFinCal.mes *100)+ (a.CAL_Alquiler.fechaFinCal.anno * 100);
    a.idAlquilo = a.CAL_Alquiler.fechaCal.dia + (a.CAL_Alquiler.fechaCal.mes * 100) + (a.CAL_Alquiler.fechaCal.anno * 100);
    cursor = secuencia;
    a.idTraslado = a.CAL_Alquiler.fechaTrasCal.dia + (a.CAL_Alquiler.fechaTrasCal.mes*100) + (a.CAL_Alquiler.fechaTrasCal.anno*100);
    a.disponible = 'Y';
    while (cursor != NULL) {
        if (a.idFinal >= cursor->detallesAlquiler.idTraslado && a.idAlquilo <= cursor->detallesAlquiler.idFinal) {
            a.disponible = 'N';
        }
        cursor = cursor->siguiente;
    }
    if (a.disponible != 'N') {
        a.ActualizarUbicacion();
        printf( "\n\n                  Resumen Alquiler:        \n\n");
        printf( "      Máquina alquilada: %s (Id=%d)\n", a.MaquinaAlquilada.nombre, a.MaquinaAlquilada.id);
        printf( "      Finca a cosechar: %s (Id=%d)\n", a.FincaAlquilada.nombre, a.FincaAlquilada.id);
        printf( "      Traslado desde: finca %s (Id=%d)\n", a.FincaActual.nombre, a.FincaActual.id);
        printf( "      Tiempo de traslado: %d/%d/%d (1 día)\n", a.CAL_Alquiler.fechaTrasCal.dia, a.CAL_Alquiler.fechaTrasCal.mes, a.CAL_Alquiler.fechaTrasCal.anno);
        printf( "      Fecha comienzo: %d/%d/%d\n", a.CAL_Alquiler.fechaCal.dia, a.CAL_Alquiler.fechaCal.mes, a.CAL_Alquiler.fechaCal.anno);
        printf( "      Distancia entre fincas: %.0f km en línea recta\n", a.GetDistanciaFincas());
        printf( "      Duración cosecha: %d\n", a.GetDuracionCosecha());
        printf( "      Fecha finalización: %d/%d/%d\n", a.CAL_Alquiler.fechaFinCal.dia, a.CAL_Alquiler.fechaFinCal.mes, a.CAL_Alquiler.fechaFinCal.anno);
        printf( "\n\nEs correcta la operación (S/N)? ");
        scanf( " %c", &ALQ_tecla);
    
        if (ALQ_tecla == 'N') {
            GetNuevoAlquilo(a , m, f);
        } else {
            PonerEnSecuencia(a);
            return;
        }
    } else {
        printf("\n\nMáquina no disponible en la fecha indicada.\n\n");
        GetNuevoAlquilo(a, m, f);
    } 
}

void GetNuevoAlquilo(TipoAlquiler a, TipoListaMaquina m, TipoListaFinca f) {
    printf( "\n");
    printf("Alquiler Máquina:\n\n");
    a.CAL_Alquiler.GetFecha();
    a.GetFinca();
    a.GetMaquina();
    a.GetFechaFinal();
    a.GetDiaTraslado();
    ComprobarDisponibilidad(a, m, f);
}