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
#include "hojaServicio.h"

#define TIPOS 3
#define AUTOS 10
#define HOJA 10

int main(void) {
	setbuf(stdout,NULL);

	eTipo auxTipo[TIPOS];
	eVehiculo auxAuto[AUTOS];
	eHojaServicio auxHoja[HOJA];

	VEHI_ArrayInit(auxAuto, AUTOS);
	TIP_ArrayInit(auxTipo, TIPOS);
	HOJA_ArrayInit(auxHoja, HOJA);

	int opcion;

	int idAuto=1;
	int idTipo=1;
	int idHoja=2000;

	NEXO_ALTAS(auxAuto, AUTOS, &idAuto);
	TIPO_ALTAS(auxTipo, TIPOS, &idTipo);
	HOJA_ALTAS(auxHoja, HOJA, &idHoja);

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
				HOJA_PrintAll(auxHoja, HOJA);
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

