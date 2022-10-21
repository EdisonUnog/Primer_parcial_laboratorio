/*
 * menuM.c
 *
 *  Created on: 14 oct. 2022
 *      Author: ediso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "menuM.h"

int muestraMenu(){
	int opcion=0;
	printf("\n\n ============================================");
	printf("\n --------------- MENU PRINCIPAL --------------");
	printf("\n ------ VIHUCULOS GESTIONA UNA OPCION --------");
	printf("\n 1._ALTA VIHUCULOS ");
	printf("\n 2._MODIFICAR VIHUCULOS");
	printf("\n 3._BAJA VIHUCULOS");
	printf("\n 4._LISTAR VIHUCULOS");
	printf("\n 5._LISTAR TIPOS");
	printf("\n 6._ALTA HOJA DE SERVICIO");
	printf("\n 7._LISTAR HOJA DE SERVICIO");
	printf("\n 8._INFORMES");
	printf("\n 9._SALIR");
	printf("\n ============================================");
	get_numInt(&opcion,"\n INGRESA UNA OPCION >> ","\n ERROR...",1, 9, 2);
	return opcion;
}

int menuInforme(){
	int opcion;
	printf("\n\n ============================================");
	printf("\n --------------- MENU INFORMES _-------------");
	printf("\n ------- INFORMACION GESTIONA UNA OPCION --------");
	printf("\n 1._MOSTRAR VEHICULO DE UN TIPO SELECIONADO ");
	printf("\n 2._MOSTRAR TODOS KLAS HOJAS EFECTUADOS EN UNA FECHA SELELCIONADA");
	printf("\n 3._INFORMAR IMPORTE TOTAL DE LAS HOJAS REALIZADO POR UN VEHICULO SELECCIONADO");
	printf("\n 4._INFORMAR IMPORTE TOTAL DE TODAS LAS HOJAS DE UN TIPO EN UNA FECHA SELECCIONADA");
	printf("\n 5._SALIR");
	printf("\n ============================================");
	get_numInt(&opcion,"\n INGRESA UNA OPCION >> ","\n ERROR...",1, 5, 2);
	return opcion;
}


int salir(char*cadena){
	int iGet=-1;
	char salir;

	if(cadena!=NULL){
		printf("\n SALIR DEL MENU (S/N) >> ");
		fflush(stdin);
		scanf("%c", &salir);
		salir=minuscula(salir);

		while(salir != 's' && salir != 'n'){
			printf("\n ERROR..IINGRESA UNA DE LAS OPCIONES (S/N) >> ");
			fflush(stdin);
			scanf("%c", &salir);
			salir=minuscula(salir);
		}
		if(salir=='s'){
			printf("\n\t   *GRACIAS POR VISITARNOS*");
		}
		if(salir=='n'){
			printf("\n\t   CONTINUA EN EL MENU...");
		}
		iGet = 0;
	}
	*cadena=salir;
	return iGet;
}

char minuscula(char cadena){
	if(cadena !='s' && cadena !='n'){
		cadena=tolower(cadena);
	}
	return cadena;
}
