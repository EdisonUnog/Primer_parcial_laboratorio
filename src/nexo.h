/*
 * nexo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#include "vehiculo.h"
#include "hojaServicio.h"

#ifndef NEXO_H_
#define NEXO_H_

int NEXO_CargaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int index,int*idAuto);
int NEXO_AltaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int*idAuto);

int NEXO_Modificar(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int index);
int NEXO_Edit(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo);

int NEXO_BajaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo);
int NEXO_PrintUno(eVehiculo arrayVehi,eTipo*arrayTipo,int limitTipo);
int NEXO_PrintAll(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo);
int NEXO_VehiculoAltaForzada(eVehiculo*arrayVehi,int limitVehi,int indice,int*idAuto,char*descr,int modelo, char*color,int idTipo);

// carga hoja

int NEXO_CargarHoja(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limitVehi,int index,int*idHoja);
int NEXO_AltaHoja(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limitVehi,int*idHoja);

int NEXO_ALTAS(eVehiculo*arrayVehi,int limitVehi,int*idAuto);

#endif /* NEXO_H_ */
