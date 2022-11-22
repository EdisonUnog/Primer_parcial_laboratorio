/*
 * vehiculo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menuM.h"
#include "Biblioteca.h"
#include "vehiculo.h"
#include "tipo.h"

#define VACIO 1
#define LLENO 0

///==================================================================================


int VEHI_ArrayInit(eVehiculo*arrayVehi,int limitVehi){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		iGet=0;
		for(i=0;i<limitVehi;i++){
			arrayVehi[i].isEmpty=VACIO;
		}
	}
	return iGet;
}

int VEHI_GetEmptyIndex(eVehiculo*arrayVehi,int limitVehi){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].isEmpty==VACIO){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}


int VEHI_CargaVehiculo(eVehiculo*arrayVehi,int limitVehi,int index,int*idAuto){
	int iGet=-1;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0 && index<limitVehi && index>=0 && idAuto!=NULL){
		get_textString(bufferVehi.descripcioVe,DESCRI,"\n DESCRIPCION DEL VEHICULO >> ", "\n ERROR..",2);
		get_numInt(&bufferVehi.modelo," MODELO DEL VEHICULO >> ","\n ERROR..",1,1000,2);
		get_textString(bufferVehi.color,COLOR,"\n COLOR >> ", "\n ERROR..",2);
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

int VEHI_Alta(eVehiculo*arrayVehi,int limitVehi,int*idAuto){
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

eVehiculo VEHI_SearchViajeId(eVehiculo*arrayVehi,int limitVehi,int idSearch){
	int i;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0){
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].idVehiculo==idSearch){
				bufferVehi=arrayVehi[i];
				break;
			}
		}
	}
	return bufferVehi;
}

eVehiculo VEHI_SearchTipo(eVehiculo*arrayVehi,int limitVehi,int idTipo){
	int i;
	eVehiculo bufferVehi;
	if(arrayVehi!=NULL && limitVehi>0){
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].idTipo==idTipo){
				bufferVehi=arrayVehi[i];
				break;
			}
		}
	}
	return bufferVehi;
}

int VEHI_BuscarId(eVehiculo*arrayVehi,int limitVehi,int idSearch){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].isEmpty==LLENO && arrayVehi[i].idVehiculo==idSearch){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int VEHI_BuscarTipoVehi(eVehiculo*arrayVehi,int limitVehi,int tipo){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].isEmpty==LLENO && arrayVehi[i].idTipo==tipo){
				iGet=i;
				break;
			}
		}
	}
	return iGet;
}

int VEHI_PrintUno(eVehiculo*arrayVehi){
	int iGet=-1;
	if(arrayVehi!=NULL && arrayVehi->isEmpty==LLENO){
		printf("\n\n ID VEHICULO: %d\n DESCRIPCION: %s\n MODELO: %d\n COLOR: %s\n ID TIPO: %d",
				arrayVehi->idVehiculo,arrayVehi->descripcioVe,arrayVehi->modelo,arrayVehi->color,arrayVehi->idTipo);
		iGet=0;
	}
	return iGet;
}

int VEHI_PrintAll(eVehiculo*arrayVehi,int limitVehi){
	int iGet=-1;
	int i;
	if(arrayVehi!=NULL && limitVehi>0){
		iGet=0;
		for(i=0;i<limitVehi;i++){
			if(arrayVehi[i].isEmpty==LLENO){
				VEHI_PrintUno(&arrayVehi[i]);
			}
		}
	}
	return iGet;
}

int VEHI_establecerTipo(int idTipo, char* tipoDescripcion){
	int rtn = 1;

	if(idTipo > 0 && tipoDescripcion != NULL){
		switch(idTipo){
			case 1:
				strcpy(tipoDescripcion, "CAMIONETA");
			break;

			case 2:
				strcpy(tipoDescripcion, "SEDAN 3PTAS");
			break;

			case 3:
				strcpy(tipoDescripcion, "SEDAN 5PTAS");
			break;
		}

		rtn = 0;
	}

	return rtn;
}
