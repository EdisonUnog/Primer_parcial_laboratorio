/*
 * hojaServicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Biblioteca.h"
#include "menuM.h"
#include "tipo.h"
#include "vehiculo.h"
#include "hojaServicio.h"

#define VACIO 1
#define LLENO 0

int HOJA_ArrayInit(eHojaServicio*arrayHoja,int limitHoja){
	int iGet=-1;
	int i;
	if(arrayHoja!=NULL && limitHoja>0){
		iGet=0;
		for(i=0;i<limitHoja;i++){
			arrayHoja[i].isEmpty=VACIO;
		}
	}
	return iGet;
}

int HOJA_GetEmptyIndex(eHojaServicio*arrayHoja,int limitHoja){
	int iGet=-1;
	int i;
	if(arrayHoja!=NULL && limitHoja>0){
		for(i=0;i<limitHoja;i++){
			if(arrayHoja[i].isEmpty==VACIO){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int HOJA_CargarHOJA(eHojaServicio*arrayHoja,int limitHoja,int index,int*idHoja){
	int iGet=-1;
	eHojaServicio bufferHoja;
	if(arrayHoja!=NULL && limitHoja>0 && index<limitHoja && index>=0 && idHoja!=NULL){
		get_AlfaNum(bufferHoja.Descripcion,LEN_DES,"\n HOJA DESCRIPCION >> ","\n ERROR..", 2);
		get_numFloat(&bufferHoja.precio," PRECIO DE SERVICIO >> ", "\n ERROR..",10, 90000.00,2);
		get_numInt(&bufferHoja.fecha.dia," FECHA DE VIAJE \n DIA >> "," \n ERROR..",1,30,2);
		get_numInt(&bufferHoja.fecha.mes," MES >> "," \n ERROR..",1,12,2);
		get_numInt(&bufferHoja.fecha.anio," ANIO >> "," \n ERROR..",2022,2023,2);
		get_numInt(&bufferHoja.idVehiculo," SELECCIONA UN VEHICULO >> ","\n ERROR..",1, 10, 2);
		iGet=0;
		bufferHoja.idVehiculo=*idHoja;
		bufferHoja.isEmpty=LLENO;
		arrayHoja[index]=bufferHoja;
		(*idHoja)++;

		HOJA_PrintUno(&bufferHoja);
		printf("\n\n CARGA EXITOSA");

	}
	return iGet;
}

int HOJA_Alta(eHojaServicio*arrayHoja,int limitHoja,int*idHoja){
	int iGet=-1;
	int empty;
	if(arrayHoja!=NULL && limitHoja>0 && idHoja!=NULL){
		empty=HOJA_GetEmptyIndex(arrayHoja, limitHoja);
		if(empty>=0){
			HOJA_CargarHOJA(arrayHoja, limitHoja, empty, idHoja);
			iGet=0;
		}else
			printf("\n ARRAY SIN ESPACIO...");
	}
	return iGet;
}

eHojaServicio HOJA_SearchByFecha(eHojaServicio*arrayHoja,int limitHoja,int dia,int mes,int anio){
	int i;
	eHojaServicio bufferHoja;
	if(arrayHoja!=NULL && limitHoja>0){
		for(i=0;i<limitHoja;i++){
			if(arrayHoja[i].fecha.dia==dia && arrayHoja[i].fecha.mes==mes && arrayHoja[i].fecha.anio==anio){
				bufferHoja=arrayHoja[i];
				break;
			}
		}
	}
	return bufferHoja;
}

eHojaServicio HOJA_SearchTipo(eHojaServicio*arrayHoja,int limitHoja,int idVehi){
	int i;
	eHojaServicio bufferVou;
	if(arrayHoja!=NULL && limitHoja>0){
		for(i=0;i<limitHoja;i++){
			if(arrayHoja[i].isEmpty==LLENO && arrayHoja[i].idVehiculo==idVehi){
				bufferVou=arrayHoja[i];
				break;
			}
		}
	}
	return bufferVou;
}

int HOJA_PrintUno(eHojaServicio*arrayHoja){
	int iGet=-1;
	if(arrayHoja!=NULL){
		printf("\n\n ID HOJA: %d\n DESCRIPCION VOU: %s\n PRECIO VOU: $$ [(%.2f])\n FECHA: %d / %d / %d\n ID VEHICULO: %d",
			arrayHoja->idHoja,arrayHoja->Descripcion,arrayHoja->precio,arrayHoja->fecha.dia,arrayHoja->fecha.mes,arrayHoja->fecha.anio,arrayHoja->idVehiculo);
		iGet=0;
	}
	return iGet;
}

int HOJA_PrintAll(eHojaServicio*arrayHoja,int limitHoja){
	int iGet=-1;
	int i;
	if(arrayHoja!=NULL && limitHoja>0){
		iGet=0;
		for(i=0;i<limitHoja;i++){
			if(arrayHoja[i].isEmpty==LLENO){
				HOJA_PrintUno(&arrayHoja[i]);
			}
		}
	}
	return iGet;
}

int HOJA_FechasDisponibles(eHojaServicio*arrayHoja,int limitHoja){
	int iGet=-1;
	int i;
	if(arrayHoja!=NULL && limitHoja>0){
		iGet=0;
		for(i=0;i<limitHoja;i++){
			if(arrayHoja[i].isEmpty==LLENO){
				printf("\n\n  FECHA: %d / %d / %d",arrayHoja[i].fecha.dia,arrayHoja[i].fecha.mes,arrayHoja[i].fecha.anio);
				iGet=0;
			}
		}
	}
	return iGet;
}







