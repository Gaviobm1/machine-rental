/*************************************
 * Interfaz de módulo: 
**************************************/

#pragma once

typedef struct TipoCalFecha {
    int dia;
    int mes;
    int anno;
};

typedef struct TipoCalendario {
    TipoCalFecha fechaCal;
    TipoCalFecha fechaFinCal;
    TipoCalFecha fechaTrasCal;

    bool GetBisiesto();
    void ImprimirDias(int dias);
    void GetFecha();
    void NombreDias();
    void ImprimirMes();
    int GetNumDias();
    int GetNumDiasTras();

};