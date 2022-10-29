/*
 ============================================================================
 Name        : Primer_Parcial_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
#include "informe.h"

#define TIPOS 3
#define AUTOS 10
#define HOJA 10

int main(void) {
	setbuf(stdout,NULL);

	eTipo auxTipo[TIPOS];
	eVehiculo auxAuto[AUTOS];
	eHojaServicio auxHoja[HOJA];


	int opcion;

	int idAuto=1;
	int idTipo=1;
	int idHoja=2000;

	TIP_AltaForzada(auxTipo, TIPOS, 0, &idTipo, "SEDAN 3PTAS"); // 1
	TIP_AltaForzada(auxTipo, TIPOS, 1, &idTipo, "SEDAN 5PTAS"); // 2
	TIP_AltaForzada(auxTipo, TIPOS, 2, &idTipo, "CAMIONETAS");  //3

	NEXO_VehiculoAltaForzada(auxAuto, AUTOS, 0, &idAuto,"MODELO 0023", 1997, "ROJO", 2);       // 1
	NEXO_VehiculoAltaForzada(auxAuto, AUTOS, 1, &idAuto,"MODELO 2344", 1900, "VERDE", 1);      // 2
	NEXO_VehiculoAltaForzada(auxAuto, AUTOS, 2, &idAuto,"MODELO 3453", 1945, "NEGRO MATE", 3); // 3



	do{
			opcion=muestraMenu();
			switch(opcion){
				case 1: ///ALTA
					NEXO_AltaVehiculo(auxAuto,AUTOS,auxTipo,TIPOS,&idAuto);
					break;
				case 2: ///EDITAR
					NEXO_Edit(auxAuto,AUTOS,auxTipo,TIPOS);
					break;
				case 3: ///BAJA VIAJE
					NEXO_BajaVehiculo(auxAuto,AUTOS,auxTipo,TIPOS);
					break;
				case 4: ///LISTAR VIAJES
					NEXO_PrintAll(auxAuto,AUTOS,auxTipo,TIPOS);
					break;
				case 5: ///LISTAR TIPOS
					TIP_PrintAll(auxTipo, TIPOS);
					break;
				case 6: ///ALTA VOUCHER
					NEXO_AltaHoja(auxHoja, HOJA, auxAuto, AUTOS, &idHoja);
					break;
				case 7: ///LISTAR VOUCHER
					//pendiente
					break;
				case 8: ///INFORMES
					INFO_Informes(auxAuto, AUTOS, auxHoja, HOJA, auxTipo, TIPOS);
					break;
				case 9: ///SALIR
					break;
			}
		}while(opcion!=9);

	return EXIT_SUCCESS;
}
