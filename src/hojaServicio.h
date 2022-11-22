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
	int idHoja; // propío clave primaria
	int idVehiculo; // busco c. foranea
	char Descripcion[LEN_DES];
	float precio;
	eFechas fecha;
	int isEmpty;
}eHojaServicio;

int HOJA_ArrayInit(eHojaServicio*arrayHoja,int limitHoja);
int HOJA_GetEmptyIndex(eHojaServicio*arrayHoja,int limitHoja);
int HOJA_CargarHOJA(eHojaServicio*arrayHoja,int limitHoja,int index,int*idHoja);
int HOJA_Alta(eHojaServicio*arrayHoja,int limitHoja,int*idHoja);
eHojaServicio HOJA_SearchByFecha(eHojaServicio*arrayHoja,int limitHoja,int dia,int mes,int anio);
eHojaServicio HOJA_SearchTipo(eHojaServicio*arrayHoja,int limitHoja,int idVehi);
int HOJA_PrintUno(eHojaServicio*arrayHoja);
int HOJA_PrintAll(eHojaServicio*arrayHoja,int limitHoja);
int HOJA_FechasDisponibles(eHojaServicio*arrayHoja,int limitHoja);

int HOJA_AltaForzada(eHojaServicio*arrayHoja,int limit,int indice,int*id,int idVehiculo,char*descripcion,float precio,int dia,int mes,int anio);
int HOJA_precioById(eHojaServicio*arrayHoja,int limitHoja,float*result,int idVehiculo);
int HOJA_acumularPrecio(eHojaServicio*arrayHoja,int limitHoja,float*result);
int HOJA_ALTAS(eHojaServicio*arrayHoja,int limitHoja,int*idHoja);

#endif /* HOJASERVICIO_H_ */
