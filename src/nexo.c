/*
 * nexo.c
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

int NEXO_CargaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int index,int*idAuto){
	int iGet=-1;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0 && index<limitVehi && index>=0 &&idAuto!=NULL){
		get_AlfaNum(bufferVehi.descripcioVe,DESCRI,"\n DESCRIPCION DEL VEHICULO >> ", "\n ERROR..",2);
		get_numInt(&bufferVehi.modelo," MODELO DEL VEHICULO >> ","\n ERROR..",1900,2023,2);
		get_textString(bufferVehi.color,COLOR," COLOR >> ", "\n ERROR..",2);
		TIP_PrintAll(arrayTipo, limitTipo);
		get_numInt(&bufferVehi.idTipo,"\n\n SELECIONA UN TIPO >> ","\n ERROR..",1, 3, 2);
		iGet=0;
		bufferVehi.idVehiculo=*idAuto;
		bufferVehi.isEmpty=LLENO;
		arrayVehi[index]=bufferVehi;
		(*idAuto)++;

		VEHI_PrintUno(&bufferVehi);
		printf("\n\n CARGA EXITOSA");
		}
		return iGet;
}

int NEXO_AltaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int*idAuto){
	int iGet=-1;
	int empty;
	if(arrayVehi!=NULL && limitVehi>0){
	empty=VEHI_GetEmptyIndex(arrayVehi, limitVehi);
		if(empty>=0){
			VEHI_CargaVehiculo(arrayVehi, limitVehi, empty, idAuto);
			iGet=0;
		}else
			printf("\n ARRAY SIN ESPACIO...");
		}
	return iGet;
}

int NEXO_Modificar(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo,int index){
	int iGet=-1;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0 && index<limitVehi && index>=0 ){
		get_AlfaNum(bufferVehi.descripcioVe,DESCRI,"\n DESCRIPCION DEL VEHICULO >> ", "\n ERROR..",2);
		get_numInt(&bufferVehi.modelo," MODELO DEL VEHICULO >> ","\n ERROR..",1900,2023,2);
		get_textString(bufferVehi.color,COLOR," COLOR >> ", "\n ERROR..",2);
		TIP_PrintAll(arrayTipo, limitTipo);
		get_numInt(&bufferVehi.idTipo,"\n\n SELECIONA UN TIPO >> ","\n ERROR..",1, 3, 2);
		iGet=0;
		bufferVehi.idVehiculo=arrayVehi[index].idVehiculo;
		bufferVehi.isEmpty=LLENO;
		arrayVehi[index]=bufferVehi;


			printf("\n\n MODIFICACION EXITOSA");
		}
		return iGet;
}

int NEXO_Edit(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int idSearch;
	int idEncontrado;
	if(arrayVehi!=NULL && limitVehi>0 && arrayTipo !=NULL && limitTipo>0){
		NEXO_PrintAll(arrayVehi, limitVehi, arrayTipo, limitTipo);
		get_numInt(&idSearch,"\n\n  INGRESA ID A MODIFICAR >> ", "\n ERROR..",1,10, 2);
		idEncontrado=VEHI_BuscarId(arrayVehi, limitVehi, idSearch);
		if(idEncontrado>=0){
			NEXO_Modificar(arrayVehi, limitVehi, arrayTipo, limitTipo, idEncontrado);
			iGet=0;
		}else{
			printf("\n ID NO ENCONTRADO...");
			iGet=-1;
		}
	}
	return iGet;
}


int NEXO_BajaVehiculo(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int index;
	int idSearch;
	NEXO_PrintAll(arrayVehi, limitVehi, arrayTipo, limitTipo);
	get_numInt(&idSearch,"\n\n  INGRESA ID A ELIMINAR >> ", "\n ERROR..",1,10, 2);
	index=VEHI_BuscarId(arrayVehi, limitVehi, idSearch);
	if(index!=-1){
		arrayVehi[index].isEmpty=VACIO;
		printf("\n BAJA EXITOSA...");
		iGet=0;
	}else{
		printf("\n ID NO ENCONTRADO...");
		iGet=-1;
	}
	return iGet;
}

int NEXO_PrintUno(eVehiculo arrayVehi,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int id;
	eTipo auxTipo;
	id=arrayVehi.idTipo;
	auxTipo=TIP_SearchTipoId(arrayTipo, limitTipo, id);
	if(arrayTipo!=NULL && limitTipo>0){
		printf("\n\n ID AUTo: %d\n DESCRIPCION: %s\n MODELO: %d\n COLOR: %s\n ID TIPO: %d -> %s",
				arrayVehi.idVehiculo,arrayVehi.descripcioVe,arrayVehi.modelo,arrayVehi.color,auxTipo.idTipo,auxTipo.descripcion);
		iGet=0;
	}
	return iGet;
}

int NEXO_PrintAll(eVehiculo*arrayVehi,int limitVehi,eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		iGet=0;
		printf("\n   ============ LISTA DE VIAJES =========== ");
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].isEmpty==LLENO){
				NEXO_PrintUno(arrayVehi[i], arrayTipo, limitTipo);
			}
		}
	   printf("\n\n   ======================================== ");
	}
	return iGet;
}

int NEXO_VehiculoAltaForzada(eVehiculo*arrayVehi,int limitVehi,int indice,int*idAuto,char*descr,int modelo, char*color,int idTipo){
	int iGet=-1;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0 && indice<limitVehi && indice>=0 && idAuto!=NULL && descr!=NULL){
		strncpy(bufferVehi.descripcioVe,descr,DESCRI);
		strncpy(bufferVehi.color,color,COLOR);
		bufferVehi.modelo=modelo;
		bufferVehi.idTipo=idTipo;
		iGet=0;
		bufferVehi.idVehiculo=*idAuto;
		bufferVehi.isEmpty=LLENO;
		arrayVehi[indice]=bufferVehi;
		(*idAuto)++;
	}
	return iGet;
}

///================================================================================
int NEXO_CargarHoja(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limitVehi,int index,int*idHoja){
	int iGet=-1;
	eHojaServicio bufferHoja;
	if(arrayHoja!=NULL && limitHoja>0 && index<limitHoja && index>=0 && idHoja!=NULL){
		get_AlfaNum(bufferHoja.Descripcion,LEN_DES,"\n HOJA DESCRIPCION >> ","\n ERROR..", 2);
		get_numFloat(&bufferHoja.precio," PRECIO DE SERVICIO >> ", "\n ERROR..",10, 90000.00,2);
		get_numInt(&bufferHoja.fecha.dia," FECHA DE VIAJE \n DIA >> "," \n ERROR..",1,30,2);
		get_numInt(&bufferHoja.fecha.mes," MES >> "," \n ERROR..",1,12,2);
		get_numInt(&bufferHoja.fecha.anio," ANIO >> "," \n ERROR..",2022,2023,2);
		VEHI_PrintAll(arrayVehi, limitVehi);
		get_numInt(&bufferHoja.idVehiculo," SELECCIONA UN VEHICULO >> ","\n ERROR..",1, 10, 2);
		iGet=0;
		bufferHoja.idHoja=*idHoja;
		bufferHoja.isEmpty=LLENO;
		arrayHoja[index]=bufferHoja;
		(*idHoja)++;

		HOJA_PrintUno(&bufferHoja);
		printf("\n\n CARGA EXITOSA");

	}
	return iGet;
}

int NEXO_AltaHoja(eHojaServicio*arrayHoja,int limitHoja,eVehiculo*arrayVehi,int limitVehi,int*idHoja){
	int iGet=-1;
	int empty;
	if(arrayHoja!=NULL && limitHoja>0 && idHoja!=NULL){
		empty=HOJA_GetEmptyIndex(arrayHoja, limitHoja);
		if(empty>=0){
			NEXO_CargarHoja(arrayHoja, limitHoja, empty, idHoja);
			iGet=0;
		}else
			printf("\n ARRAY SIN ESPACIO...");
	}
	return iGet;
}




