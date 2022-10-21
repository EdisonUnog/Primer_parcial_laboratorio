/*
 * Name        : Biblioteca.c
 * Author      : EDISON FRANCISCO UÑOG VALENCIA
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Biblioteca.h"

//============================================================================
//--Enteros
static int itIsNumerical(char cadena[]);
static int getInt(int*pResultado);
//short
static int itIsNumericalShort(char cadena[]);
static int getShort(short*pResultado);
//--Flotantes
static int itIsFloating(char cadena[]);
static int getFloating(float*pResultado);
//--texto
static int myGets(char cadena[],int longitud);
static int getString(char*cadena,int longitud);

static int isText(char*cadena,int longitud);
static int getText(char* pResultado,int longitud);

static int isAlfaNum(char*cadena,int longitud);
static int getAlfaNum(char* pResultado,int longitud);

//==========================ES_NUMERICA
static int itIsNumerical(char cadena[]){
	int retorno=1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0){
		for(i=0 ; cadena[i]!='\0' ; i++){
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+')){
				continue;
			}
			if((cadena[i]<'0'||cadena[i]>'9') && cadena[i]!=' '){
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}
//===========================GET_INT
 //verifica si la cadena ingresada es flotante
 //return, retorna 0 si se obtiene un numeroflotante y -1 si no

static int getInt(int*pResultado){
	int retorno=-1;
	char buffer[64];

	if(pResultado!=NULL){
		if(getString(buffer,sizeof(buffer))==0 && itIsNumerical(buffer)){
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}
//=========================GET_NUMERO-------------
int get_numInt(int*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos){
	int retorno=-1;
	int buffer;

	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&minimo<=maximo&&reintentos>=0){
		do {
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo){
				*pResultado=buffer;
				retorno=0;
				break;
			}else{
				printf("%s",mensajeError);
			    reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


//==========================ES_NUMERICA SHORT
static int itIsNumericalShort(char cadena[]){
	int retorno=1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0){
		for(i=0 ; cadena[i]!='\0' ; i++){
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+')){
				continue;
			}
			if((cadena[i]<'0'||cadena[i]>'9') && cadena[i]!=' '){
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}

static int getShort(short*pResultado){
	int retorno=-1;
	char buffer[64];

	if(pResultado!=NULL){
		if(getString(buffer,sizeof(buffer))==0 && itIsNumericalShort(buffer)){
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}
//=========================GET_NUMERO_SHORT-------------
int get_numShort(short*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos){
	int retorno=-1;
	short buffer;

	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&minimo<=maximo&&reintentos>=0){
		do {
			printf("%s",mensaje);
			if(getShort(&buffer)==0 && buffer>=minimo && buffer<=maximo){
				*pResultado=buffer;
				retorno=0;
				break;
			}else{
				printf("%s",mensajeError);
			    reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
//PIDO NUMERO SIN MAXI, MIN NI REINTENTOS
int numero(int*pResultado,char*mensaje,char*mensajeError){
	int retorno=-1;
	int buffer;
	if(pResultado!=NULL &&mensaje!=NULL&&mensajeError!=NULL){
		printf("%s",mensaje);
		fflush(stdin);
		if(getInt(&buffer)==0){
			*pResultado=buffer;
			retorno=0;
		}else{
			printf("%s",mensajeError);
		}
	}else{
		printf("%s",mensajeError);
	}
	return retorno;
}
//PIDO NUMERO SIN MAXI, MIN
int numeroReintentos(int*pResultado,char*mensaje,char*mensajeError,int reintentos){
	int retorno=-1;
	int buffer;
	if(pResultado!=NULL&&mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0){
				*pResultado=buffer;
				retorno=0;
				break;
			}else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
//----------------------Floating--------------------------------------------------------------------
static int itIsFloating(char cadena[]){
	int retorno=1;
	int i=0;
	int contPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0){
		for(i=0 ; cadena[i]!='\0' ; i++){
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+')){
				continue;
			}
			if((cadena[i]<'0' || cadena[i]>'9') && cadena[i]!=' '){
				if(cadena[i]=='.' && contPuntos==0){
					contPuntos++;
				}else{
					retorno=0;
					break;
				}
			}
		}
	}
return retorno;
}
//--------------------------------------------------
static int getFloating(float*pResultado){
	int retorno=-1;
	char buffer[64];

	if(pResultado!=NULL){
		if(getString(buffer,sizeof(buffer))==0 && itIsFloating(buffer)){
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}
//------------------NUMERO_FLOTANTE--------------------------------------------
int get_numFloat(float* pResultado, char*mensaje, char*mensajeError, float minimo, float maximo, int reintentos){
	int retorno=-1;
	float bufferFloat;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{// me asegura que el codigo se va a cumplir si o si una ves
			printf("%s",mensaje); //"%s": recibi una cadena de caracteres o un string.
			if(getFloating(&bufferFloat)==0 && bufferFloat>=minimo && bufferFloat<=maximo){
				*pResultado=bufferFloat;
				retorno=0;
				break;
			}else{
				printf("%s",mensajeError);
				reintentos--; //-1
			}
		}while(reintentos>=0);
	}
	return retorno;
}
//PEDIR NUMERO FLOAT SIN MAX, MIN NI REINTENTOS
int numeroF(float*pResultado,char*mensaje,char*mensajeError){
	int retorno=-1;
	float bufferF;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL){
		printf("%s",mensaje);
		fflush(stdin);
		if(getFloating(&bufferF)==0){
			*pResultado=bufferF;
			retorno=0;
		}else{
			printf("%s",mensajeError);
		}
	}else{
		printf("%s",mensajeError);
	}
	return retorno;
}
//PEDIR NUMERO FLOAT CON REINTENTOS
int numeroFR(float*pResultado,char*mensaje,char*mensajeError,int reintentos){
	int retorno=-1;
	float bufferF;
	if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s",mensaje);
			fflush(stdin);
			if(getFloating(&bufferF)==0){
				*pResultado=bufferF;
				retorno=0;
			}else{
				printf("%s",mensajeError);
				reintentos--; //-1
			}
		}while(reintentos>=0);
	}
	return retorno;
}
/*====================================================================================*/
//--------------------------VALIDAR_TEXTO----------------------------------------
//=========================MY_GETS--------------------------------------------------
static int myGets(char cadena[],int longitud){//no desbordar la variable que el usuario nos pasa.
	int retorno=-1;
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n'){
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=0;
	}
	return retorno;
}
//------getString_valida_a_las_demas
static int getString(char*cadena,int longitud){
	int retorno=-1;
	char bufferString[4096]; //**********************

	if(cadena!=NULL && longitud>0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
/*====================================================================================*/
//=======================Validar_Cadena_De_Texto--------------------------
//------------static
static int getText(char* pResultado,int longitud){
	int retorno=-1;
	char buffer[4096];
	if(pResultado!=NULL){
		if(getString(buffer,sizeof(buffer))==0 &&
		   isText(buffer,sizeof(buffer)) &&
		   strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}

//--------static
static int isText(char*cadena,int longitud){
	int retorno=-1;
	int i=0;
	if(cadena!=NULL && longitud>0){
		for(i=0; cadena[i]!='\0' && i<longitud; i++){
			if(cadena[i]!=' ' && cadena[i]!='ñ' && cadena[i]!='Ñ' &&
			  (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z')){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

//=============funcion_text---------
int get_textString(char*pResultado,int len, char*mensaje, char*mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[4096];

	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getText(bufferString,sizeof(bufferString))==0 && strnlen(bufferString,sizeof(bufferString))<len){
			strncpy(pResultado,bufferString,len);
			retorno=0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
//PEDIR CADENA DE TEXTO SIN REINTENTOS
int stringL(char*pResultado,int len,char*mensaje,char*mensajeError){
	int retorno=-1;
	char bufferC[4234];
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		while(1){
			printf("%s",mensaje);
			if(getText(bufferC,sizeof(bufferC))==0 && strnlen(bufferC,sizeof(bufferC))<len){
				strncpy(pResultado,bufferC,len);
				retorno =0;
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}
//-------------------------------------------------------------------------------------------------------------
//------------static
static int getAlfaNum(char* pResultado,int longitud){
	int retorno=-1;
	char buffer[4096];
	if(pResultado!=NULL){
		if(getString(buffer,sizeof(buffer))==0 &&
		   isAlfaNum(buffer,sizeof(buffer)) &&
		   strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}

//--------static
static int isAlfaNum(char*cadena,int longitud){
	int retorno=-1;
	int i=0;
	if(cadena!=NULL && longitud>0){
		for(i=0; cadena[i]!='\0' && i<longitud; i++){
			if(cadena[i]!='.' && cadena[i]!=' ' && cadena[i]!='_' && cadena[i]!='-' &&
			  (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') &&
			  (cadena[i]<'0' || cadena[i]>'9')  && cadena[i]!='ñ' && cadena[i]!='Ñ'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

//=============funcion_text_Nombre---------
int get_AlfaNum(char*pResultado,int len, char*mensaje, char*mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[4096];

	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getAlfaNum(bufferString,sizeof(bufferString))==0 && strnlen(bufferString,sizeof(bufferString))<len){
			strncpy(pResultado,bufferString,len);
			retorno=0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

//=======================Get_String_Num--------------------------
//--------------------------VALIDAR_TEXTO-------
int isLetters(char str[]){
	int retorno;
	int i=0;
	while(str[i]!='\0'){
		if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'z')){
			retorno=0;
			i++;
		}
	}
	return retorno;
}
//------------static
char getCadenaNA(char cadena[],char*len){
	char auxChar[4234];
	printf(cadena);
	if(myGets(auxChar,sizeof(auxChar))==0){
		while(!isLetters(auxChar)){
			printf("\n Error. Solo letras");
			myGets(auxChar,sizeof(auxChar));
		}
	}
	strcpy(len,auxChar);
	return *len;
}
//-----------------------------------
