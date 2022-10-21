/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#ifndef TIPO_H_
#define TIPO_H_

#define DES_LEN 30

typedef struct{
	int idTipo;
	char descripcion[DES_LEN];
	int isEmpty;
}eTipo;


int TIP_ArrayInit(eTipo*arrayTipo,int limitTipo);
int TIP_GetEmptyIndex(eTipo*arrayTipo,int limit);
int TIP_CargaTipo(eTipo*arrayTipo,int limitTipo,int index,int*idTipo);
int TIP_Alta(eTipo*arrayTipo,int limitTipo,int*idTipo);
eTipo TIP_SearchTipoId(eTipo*arrayTipo,int limitTipo,int idSearch);
eTipo TIP_SearchTipo(eTipo*arrayTipo,int limitTipo,int idTipo);

int TIP_BuscarId(eTipo*arrayTipo,int limitTipo,int idSearch);
int TIP_BuscarTipoT(eTipo*arrayTipo,int limitTipo,int tipoViaje);
int TIP_PrintUno(eTipo*arrayTipo);
int TIP_PrintAll(eTipo*arrayTipo,int limitTipo);

int TIP_AltaForzada(eTipo*arrayTipo,int limitTipo,int index,int*id,char*charTipo);

#endif /* TIPO_H_ */
