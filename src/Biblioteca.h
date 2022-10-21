/*
 * Name        : Biblioteca.c
 * Author      : EDISON FRANCISCO UÑOG VALENCIA
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_


int get_numInt(int*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos);

int get_numShort(short*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos);

int numero(int*pResultado,char*mensaje,char*mensajeError);
int numeroReintentos(int*pResultado,char*mensaje,char*mensajeError,int reintentos);

int get_numFloat(float* pResultado, char*mensaje, char*mensajeError, float minimo, float maximo, int reintentos);
int numeroF(float*pResultado,char*mensaje,char*mensajeError);
int numeroFR(float*pResultado,char*mensaje,char*mensajeError,int reintentos);

int get_textString(char*pResultado,int len, char*mensaje, char*mensajeError, int reintentos);
int stringL(char*pResultado,int len,char*mensaje,char*mensajeError);

int get_AlfaNum(char*pResultado,int len, char*mensaje, char*mensajeError, int reintentos);

int isLetters(char str[]);
int esText(char*cadena);

char getCadenaNA(char cadena[],char*len);


#endif /* BIBLIOTECA_H_ */
