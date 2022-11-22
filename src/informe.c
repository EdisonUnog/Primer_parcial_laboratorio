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
	int idVehi;
	//int idTipo;
	eHojaServicio bufferHoja;
	eVehiculo bufferVehi;
	if(arrayHoja!=NULL && limitHoja>0 ){

		HOJA_FechasDisponibles(arrayHoja, limitHoja);

		get_numInt(&dia,"\n\n FECHA DE VIAJE \n  DIA >> "," \n ERROR..",1,31,2);
		get_numInt(&mes,"  MES >> "," \n ERROR..",1,12,2);
		get_numInt(&anio,"  ANIO >> "," \n ERROR..",1900,2023,2);

		bufferHoja=HOJA_SearchByFecha(arrayHoja, limitHoja, dia, mes, anio);

		printf("\n\n   ============================================");
		printf("\n   FECHAS DE LOS PROXIMOS VIAJES: %d / %d / %d ",bufferHoja.fecha.dia,bufferHoja.fecha.mes,bufferHoja.fecha.anio);
		for(i=0;i<limit;i++){
			if(arrayHoja[i].isEmpty==LLENO && arrayHoja[i].fecha.dia == dia && arrayHoja[i].fecha.mes==mes && arrayHoja[i].fecha.anio){
				idVehi=arrayHoja[i].idVehiculo;
				bufferVehi=VEHI_SearchViajeId(arrayVehi, limit, idVehi);
				HOJA_PrintUno(&bufferHoja);
				NEXO_PrintUno(bufferVehi, arrayTipo, limitTipo);
				iGet=0;
			}
		}
		printf("\n\n   ============================================");
	}
	return iGet;
}

int INFO_ImporteDeVehiculo(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit){
	int iGet=-1;
	int i;
	int j;
	int idSearch;
	int index;
	float result;
	if(arrayHoja!=NULL && limitHoja>0 && arrayVehi!=NULL && limit>0 ){
		VEHI_PrintAll(arrayVehi, limit);
		index=get_numInt(&idSearch, "\n\n INGRESA ID PARA BUSCAR VEHICULO >> ", "\n ERROR...", 1, 10, 2);
		for(i=0;i<limit;i++){
			for(j=0;j<limitHoja;j++){
				if(index!=-1){
					if(arrayVehi[i].idVehiculo==idSearch){
						HOJA_precioById(arrayHoja, limitHoja, &result, idSearch);
						iGet=0;
					}
				}
			}
		}
		printf("\n IMPORTE DEL VEHICULO CON ID [( %d )] ES: %.2f",idSearch,result);
	}
	return iGet;
}

int INFO_ImporteDeVehiculoByFecha(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limit,eTipo*arraTipo,int limitTipo){
	int iGet=-1;
	int i;

	int dia;
	int mes;
	int anio;

	float acumulador=0;
	char tipo[LEN_DES];

	eHojaServicio bufferHoja;

	if(arrayHoja!=NULL && limitHoja>0 && arrayVehi!=NULL && limit>0 ){
		HOJA_FechasDisponibles(arrayHoja, limitHoja);
		get_numInt(&dia,"\n\n FECHA DE ENTREGA \n  DIA >> "," \n ERROR..",1,31,2);
		get_numInt(&mes,"  MES >> "," \n ERROR..",1,12,2);
		get_numInt(&anio,"  ANIO >> "," \n ERROR..",1900,2023,2);

		bufferHoja=HOJA_SearchByFecha(arrayHoja, limitHoja, dia, mes, anio);

		printf("\n  FECHAS DE LAS PROXIMAS ENTREGAS: %d / %d / %d ",bufferHoja.fecha.dia,bufferHoja.fecha.mes,bufferHoja.fecha.anio);
		for(i=0;i<limit;i++){
			if(arrayHoja[i].isEmpty==LLENO && arrayHoja[i].fecha.dia == dia && arrayHoja[i].fecha.mes==mes && arrayHoja[i].fecha.anio){
				acumulador+=arrayHoja[i].precio;
				strncpy(tipo,arraTipo[i].descripcion,DES_LEN);
				iGet=0;
			}
		}
		printf("\n  IMPORTE TOTAL DE LOS VOUCHERS REALIZADOS CON TIPO [(%s)] ES DE [($$ %.2f)] PLANIFICADO EL %2d/%1d/%4d\n", tipo, acumulador, dia, mes, anio);
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
				INFO_ImporteDeVehiculo(arrayHoja, limitHoja, arrayVehi, limit);
				break;

			case 4:
				INFO_ImporteDeVehiculoByFecha(arrayHoja, limitHoja, arrayVehi, limit,arrayTipo, limitTipo);
				break;

			case 5:
				printf("\n SALISTE DEL MENU DE INFORME");
				break;
		}
		iGet=0;
	}while(opcion!=5);

	return iGet;
}



















