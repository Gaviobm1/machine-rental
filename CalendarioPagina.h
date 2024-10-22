/*************************************
 * Interfaz de módulo: 
**************************************/

#pragma once 
#include "AlquilerMaquina.h"

const int NumFilasCorto = 5;
const int NumFilasLargo = 6;
const int NumFilasFebCorto = 4;
const int NumColumnas = 7;

typedef char month[11];
typedef int TipoMatrizLargo[NumFilasLargo][NumColumnas];
typedef int TipoMatrizCorto[NumFilasCorto][NumColumnas];
typedef int TipoMatrizFebCorto[NumFilasFebCorto][NumColumnas];

typedef struct TipoMesPagina {
    int MOS_mes;
    int MOS_anno;
    int MOS_maq;
    int MOS_dias;
    char MOS_tecla;
    month nombreMes;
    month MOS_NombreMes;
    TipoMaquina ALQ_Maquina;
    

 int BuscarIncreDias();
 int BuscarPrimerDia();
 void BuscarFecha();
 void BuscarDias();
 void BuscarMes();
 void ImprimirCabecera();
 void CrearMatrizLargo(TipoMatrizLargo m);
 void CrearMatrizCorto(TipoMatrizCorto m);
 void CrearMatrizFebCorto(TipoMatrizFebCorto m);
 void ImprimirMatrizLargo(TipoMatrizLargo m);
 void ImprimirMatrizCorto(TipoMatrizCorto m);
 void ImprimirMatrizFebCorto(TipoMatrizFebCorto m);
 void CrearMes();
 void OrdenCosecha();
};

extern TipoMesPagina MesPagina;

bool EsBisiesto(int y);
void GetPagina(TipoMesPagina a);

