/*
 * informe.h
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#ifndef INFORME_H_
#define INFORME_H_

int INFO_AutoByTipo(eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo);
int INFO_HojasByFecha(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo);
int INFO_ImporteHojaViaje(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo);

int INFO_Informes(eVehiculo*arrayVehi,int limit,eHojaServicio*arrayHoja,int limitHoja,eTipo*arrayTipo,int limitTipo);

#endif /* INFORME_H_ */
