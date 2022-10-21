/*
 * tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"
#include "Biblioteca.h"

#define VACIO 1
#define LLENO 0

int TIP_ArrayInit(eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int i;
	if(arrayTipo!=NULL && limitTipo>0){
		iGet=0;
		for(i=0;i<limitTipo;i++){
			arrayTipo[i].isEmpty=VACIO;
		}
	}
	return iGet;
}

int TIP_GetEmptyIndex(eTipo*arrayTipo,int limit){
	int iGet=-1;
	int i;
	if(arrayTipo!=NULL && limit>0){
		for(i=0;i<limit;i++){
			if(arrayTipo[i].isEmpty==VACIO){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int TIP_CargaTipo(eTipo*arrayTipo,int limitTipo,int index,int*idTipo){
	int iGet=-1;
	eTipo bufferTipo;
	if(arrayTipo!=NULL && limitTipo>0 && index<limitTipo && index>=0 && idTipo!=NULL){
		get_textString(bufferTipo.descripcion,DES_LEN,"\n DESCRIPCION DE TIPO >> ", "\n ERROR..",2);
		iGet=0;
		bufferTipo.idTipo=*idTipo;
		bufferTipo.isEmpty=LLENO;
		arrayTipo[index]=bufferTipo;
		(*idTipo)++;

		TIP_PrintUno(&bufferTipo);
		printf("\n\n CARGA EXITOSA");
	}
	return iGet;
}


int TIP_Alta(eTipo*arrayTipo,int limitTipo,int*idTipo){
	int iGet=-1;
	int empty;
	if(arrayTipo!=NULL && limitTipo>0){
		empty=TIP_GetEmptyIndex(arrayTipo, limitTipo);
		if(empty>=0){
			TIP_CargaTipo(arrayTipo, limitTipo, empty, idTipo);
			iGet=0;
		}else
			printf("\n ARRAY SIN ESPACIO...");
	}
	return iGet;
}

/////

eTipo TIP_SearchTipoId(eTipo*arrayTipo,int limitTipo,int idSearch){
	int i;
	eTipo bufferTipo;
	if(arrayTipo!=NULL && limitTipo>0){
		for(i=0;i<limitTipo;i++){
			if(arrayTipo[i].idTipo==idSearch){
				bufferTipo=arrayTipo[i];
				break;
			}
		}
	}
	return bufferTipo;
}

eTipo TIP_SearchTipo(eTipo*arrayTipo,int limitTipo,int idTipo){
	int i;
	eTipo bufferVia;
	if(arrayTipo!=NULL && limitTipo>0){
		for(i=0;i<limitTipo;i++){
			if(arrayTipo[i].idTipo==idTipo){
				bufferVia=arrayTipo[i];
				break;
			}
		}
	}
	return bufferVia;
}

int TIP_BuscarId(eTipo*arrayTipo,int limitTipo,int idSearch){
	int iGet=-1;
	int i;
	if(arrayTipo!=NULL && limitTipo>0){
		for(i=0;i<limitTipo;i++){
			if(arrayTipo[i].isEmpty==LLENO && arrayTipo[i].idTipo==idSearch){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int TIP_BuscarTipoT(eTipo*arrayTipo,int limitTipo,int tipoViaje){
	int iGet=-1;
	int i;
	if(arrayTipo!=NULL && limitTipo>0){
		for(i=0;i<limitTipo;i++){
			if(arrayTipo[i].isEmpty==LLENO && arrayTipo[i].idTipo==tipoViaje){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int TIP_PrintUno(eTipo*arrayTipo){
	int iGet=-1;
	if(arrayTipo!=NULL && arrayTipo->isEmpty==LLENO){
		printf("\n\n ID VIAJE: %d\n DESTINO: %s",
				arrayTipo->idTipo,arrayTipo->descripcion);
		iGet=0;
	}
	return iGet;
}

int TIP_PrintAll(eTipo*arrayTipo,int limitTipo){
	int iGet=-1;
	int i;
	if(arrayTipo!=NULL && limitTipo>0){
		iGet=0;
		for(i=0;i<limitTipo;i++){
			if(arrayTipo[i].isEmpty==LLENO){
				TIP_PrintUno(&arrayTipo[i]);
			}
		}
	}
	return iGet;
}


int TIP_AltaForzada(eTipo*arrayTipo,int limitTipo,int index,int*id,char*charTipo){
	int iGet=-1;
	eTipo bufferTipo;
	if(arrayTipo!=NULL && limitTipo>0 && index<limitTipo && index>=0 && id!=NULL && charTipo!=NULL){
		strncpy(bufferTipo.descripcion,charTipo,DES_LEN);
		iGet=0;
		bufferTipo.idTipo=*id;
		bufferTipo.isEmpty=LLENO;
		arrayTipo[index]=bufferTipo;
		(*id)++;
	}
	return iGet;
}




