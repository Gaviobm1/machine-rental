/******************************************************************************
 * Interfaz de módulo: AlquilerMaquina
 *                                                                                                   
 *  Este módulo define el tipo abstracto Alquiler capaz 
 *  de almanecar los datos de un alquiler y contiene las 
 *  funciones y procedimientos para generar y añadir los 
 *  datos de un alquiler a una secuncia enlazadakm
 * .........................
 * 
******************************************************************************/

#pragma once
#include "EditarMaquina.h"
#include "EditarFinca.h"
#include "CalendarioMes.h"


typedef struct TipoAlquiler {
    TipoCalendario CAL_Alquiler;
    TipoFinca FincaAlquilada;
    TipoMaquina MaquinaAlquilada;
    TipoFinca FincaActual;
    int n;
    int idAlquilo;
    int idFinal = CAL_Alquiler.fechaCal.dia + (CAL_Alquiler.fechaCal.mes * 100) + (CAL_Alquiler.fechaCal.anno * 100);
    int idCosecha;
    int idTraslado =CAL_Alquiler.fechaTrasCal.dia + (CAL_Alquiler.fechaTrasCal.mes*100) + (CAL_Alquiler.fechaTrasCal.anno*100);
    char disponible;

    void GetMaquina();
    void GetFinca();
    void GetFechaFinal();
    int GetDuracionCosecha();
    float GetDistanciaFincas();
    void GetDiaTraslado();
    void BuscarFinca(TipoListaFinca v);
    void ActualizarUbicacion();
};

typedef struct TipoNodo {
    TipoAlquiler detallesAlquiler;
    TipoNodo *siguiente;
};

typedef TipoNodo * TipoSecuencia;
typedef TipoNodo * TipoPuntNodo;
extern TipoCalendario nuevoCalendario;
extern TipoAlquiler nuevoAlquilo;
extern TipoSecuencia secuencia;
extern TipoPuntNodo cursor, anterior, nuevo;


void PonerEnSecuencia(TipoAlquiler a);
void GetNuevoAlquilo(TipoAlquiler a, TipoListaMaquina m, TipoListaFinca f);