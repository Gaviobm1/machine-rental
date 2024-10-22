/**************************************************************************
 * Programa: Gestionar el Alquiler de Maquinaria 
 * Agrícola (GesAMA)
 * 
 * Descripción: 
 *    Este programa gestiona el alquiler de máquinas
 *    cosechadoras. Permite la introducción de sus datos,
 *    los datos de las fincas, realizar un alquiler y ver la
 *    planficación mensual de las máquinas.
 * 
 * Fecha de su última modificación: 22/12/23
****************************************************************************/

#include <stdio.h>
#include "ElegirFuncion.h"
#include "PresentarOpciones.h"
#include "EditarMaquina.h"
#include "EditarFinca.h"
#include "AlquilerMaquina.h"

int main() {
   presentarOpciones();
   HacerEleccion();
}