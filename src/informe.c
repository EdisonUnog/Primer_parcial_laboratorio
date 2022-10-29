/*
 * informe.c
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "menuM.h"
#include "tipo.h"
#include "vehiculo.h"
#include "nexo.h"

#define VACIO 1
#define LLENO 0

int INFO_AutoByTipo(eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int tipoSearch;
	int i;
	eTipo bufferTipo;
	if(arrayVehi!=NULL && limit>0 && arrayTipo!=NULL && limitTipo>0){
		TIP_PrintAll(arrayTipo, limitTipo);

		get_numInt(&tipoSearch,"\n\n INGRESA TIPO DE VEHICULO A IMPRIMIR >> ", " ERROR..",1, 3,2);
		bufferTipo=TIP_SearchTipoId(arrayTipo, limitTipo, tipoSearch);

		printf("\n\n   ============================================");
		printf("\n   --------- TIPO DE VIAJE: %s ---------",bufferTipo.descripcion);
		for(i=0;i<limit;i++){
			if(arrayVehi[i].isEmpty==LLENO && arrayVehi[i].idTipo==tipoSearch){
				printf("\n\n   ID AUTo: %d\n     DESCRIPCION: %s\n     MODELO: %d\n     COLOR: %s\n   ID TIPO: %d -> %s",
						arrayVehi[i].idVehiculo,arrayVehi[i].descripcioVe,arrayVehi[i].modelo,arrayVehi[i].color,
						bufferTipo.idTipo,bufferTipo.descripcion);
				iGet=0;
			}
		}
		printf("\n\n   ============================================");
	}

	return iGet;
}


///========================FUNCION QUE IMPRIME EL VOUCHER POR FECHAS===============================

int INFO_HojasByFecha(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int dia;
	int mes;
	int anio;
	int i;
	int tipoDes;
	eHojaServicio bufferHoja;
	eTipo bufferTipo;
	if(arrayHoja!=NULL && limitHoja>0 ){
		HOJA_FechasDisponibles(arrayHoja, limitHoja);
		get_numInt(&dia,"\n\n FECHA DE VIAJE \n  DIA >> "," \n ERROR..",1,30,2);
		get_numInt(&mes,"  MES >> "," \n ERROR..",1,12,2);
		get_numInt(&anio,"  ANIO >> "," \n ERROR..",2022,2023,2);

		bufferHoja=HOJA_SearchByFecha(arrayHoja, limitHoja, dia, mes, anio);

		printf("\n\n   ============================================");
		printf("\n   FECHAS DE LOS PROXIMOS VIAJES: %d / %d / %d ",bufferHoja.fecha.dia,bufferHoja.fecha.mes,bufferHoja.fecha.anio);
		for(i=0;i<limit;i++){
			if(arrayHoja[i].isEmpty==LLENO && arrayHoja[i].fecha.dia == dia && arrayHoja[i].fecha.mes==mes && arrayHoja[i].fecha.anio){
				tipoDes=arrayVehi[i].idTipo;
				bufferTipo=TIP_SearchTipoId(arrayTipo, limitTipo, tipoDes);
				printf("\n\n   IDHOJA: %d\n    DESCRIPCION VOU: %s\n    PRECIO VOU: $$ [(%.2f])\n    FECHA: %d / %d / %d\n   ID DE VIAJE: %d",
						arrayHoja[i].idHoja,arrayHoja[i].Descripcion,arrayHoja[i].precio,
						bufferHoja.fecha.dia,bufferHoja.fecha.mes,bufferHoja.fecha.anio,arrayHoja[i].idVehiculo);
				printf("\n    DESCRIPCION: %s\n    MODELO: %d\n   COLOR: %s\n   TIPO DE VIAJE: %d -> %s",
						      arrayVehi[i].descripcioVe,arrayVehi[i].modelo,arrayVehi[i].color,arrayVehi[i].idTipo,bufferTipo.descripcion);
				iGet=0;
			}
		}
		printf("\n\n   ============================================");
	}
	return iGet;
}

int INFO_ImporteHojaViaje(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int tipoSearch;
	int i;
	int tipoViaje;
	int tipoVoucher;
	float importe;
	eTipo bufferTipo;
	eHojaServicio bufferHoja;
	eVehiculo bufferVeihi;
	if(arrayVehi!=NULL && limit>0 && arrayTipo!=NULL && limitTipo>0){
		VEHI_PrintAll(arrayVehi, limit);

		get_numInt(&tipoSearch,"\n\n INGRESA TIPO DE VIAJE A IMPRIMIR >> ", " ERROR..",1, 10,2);
		bufferVeihi=VEHI_SearchViajeId(arrayVehi, limit, tipoSearch);

		printf("\n\n   ============================================");
		printf("\n   --------- TIPO DE VIAJE:  ---------");
		for(i=0;i<limit;i++){
			if(arrayVehi[i].isEmpty==LLENO && arrayVehi[i].idVehiculo==tipoSearch){

				tipoViaje=arrayVehi[i].idTipo;
				bufferTipo=TIP_SearchTipoId(arrayTipo, limitTipo, tipoViaje);
				tipoVoucher=arrayHoja[i].idVehiculo;
				bufferHoja=HOJA_SearchTipo(arrayHoja, limitHoja, tipoVoucher);

				importe=arrayHoja[i].precio;

				printf("\n\n   ID HOJA: %d\n    DESCRIPCION VOU: %s\n    PRECIO VOU: $$ [(%.2f])\n    FECHA: %d / %d / %d\n   ID DE VEHICULO: %d",
						bufferHoja.idHoja,bufferHoja.Descripcion,bufferHoja.precio,
						bufferHoja.fecha.dia,bufferHoja.fecha.mes,bufferHoja.fecha.anio,bufferVeihi.idVehiculo);
				printf("\n   DESCRIPCIP V. : %s\n   MODELO: %d\n  COLOR: %s\n TIPO: %d -> %s",
						arrayVehi[i].descripcioVe,arrayVehi[i].modelo,arrayVehi[i].color,
						bufferTipo.idTipo,bufferTipo.descripcion);
				iGet=0;
				printf("\n    IMPORTE FINAL._ PRECIO POR LA CANTIDAD DE PERSONAS: $$$ [( %.2f )]",importe);
			}
		}
		printf("\n\n   ============================================");
	}

	return iGet;
}

int INFO_Informes(eVehiculo*arrayVehi,int limit,eHojaServicio*arrayHoja,int limitHoja,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int opcion;
	do{
		opcion = menuInforme();
		switch(opcion){
			case 1:
				INFO_AutoByTipo(arrayVehi, limit, arrayTipo, limitTipo);
				break;

			case 2:
				INFO_HojasByFecha(arrayHoja, limitHoja, arrayVehi, limit, arrayTipo, limitTipo);
				break;

			case 3:
				INFO_ImporteHojaViaje(arrayHoja, limitHoja, arrayVehi, limit, arrayTipo, limitTipo);
				break;

			case 4:
				printf("\n PENDIENTE");
				break;

			case 5:
				printf("\n SALISTE DEL MENU DE INFORME");
				break;
		}
		iGet=0;
	}while(opcion!=5);
	return iGet;
}



















