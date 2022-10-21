/*
 * vehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: ediso
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_
#define DESCRI 30
#define COLOR 10
typedef struct{
	int idVehiculo;
	char descripcioVe[DESCRI];
	int modelo;
	char color[COLOR];
	int idTipo;
	int isEmpty;
}eVehiculo;

int VEHI_ArrayInit(eVehiculo*arrayVehi,int limitVehi);
int VEHI_GetEmptyIndex(eVehiculo*arrayVehi,int limitVehi);
int VEHI_CargaVehiculo(eVehiculo*arrayVehi,int limitVehi,int index,int*idAuto);
int VEHI_Alta(eVehiculo*arrayVehi,int limitVehi,int*idAuto);
eVehiculo VEHI_SearchViajeId(eVehiculo*arrayVehi,int limitVehi,int idSearch);
eVehiculo VEHI_SearchTipo(eVehiculo*arrayVehi,int limitVehi,int idTipo);
int VEHI_BuscarId(eVehiculo*arrayVehi,int limitVehi,int idSearch);
int VEHI_BuscarTipoVehi(eVehiculo*arrayVehi,int limitVehi,int tipo);
int VEHI_PrintUno(eVehiculo*arrayVehi);
int VEHI_PrintAll(eVehiculo*arrayVehi,int limitVehi);

#endif /* VEHICULO_H_ */
