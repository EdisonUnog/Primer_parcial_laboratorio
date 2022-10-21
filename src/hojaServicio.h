/*
 * hojaServicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
#define LEN_DES 50
typedef struct{
	int dia;
	int mes;
	int anio;
}eFechas;

typedef struct{
	int idHoja;
	int idVehiculo;
	char Descripcion[LEN_DES];
	float precio;
	eFechas fecha;
	int isEmpty;
}eHojaServicio;

int HOJA_ArrayInit(eHojaServicio*arrayHoja,int limitHoja);
int HOJA_GetEmptyIndex(eHojaServicio*arrayHoja,int limitHoja);
int HOJA_CargarHOJA(eHojaServicio*arrayHoja,int limitHoja,int index,int*idHoja);
int HOJA_Alta(eHojaServicio*arrayHoja,int limitHoja,int*idHoja);
eHojaServicio VOU_SearchByFecha(eHojaServicio*arrayHoja,int limitHoja,int dia,int mes,int anio);
eHojaServicio VOU_SearchTipo(eHojaServicio*arrayHoja,int limitHoja,int idVehi);
int HOJA_PrintUno(eHojaServicio*arrayHoja);
int HOJA_PrintAll(eHojaServicio*arrayHoja,int limitHoja);

#endif /* HOJASERVICIO_H_ */