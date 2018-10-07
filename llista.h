#ifndef _LLISTABIDORD_H
#define _LLISTABIDORD_H

#include <stdio.h>

//Definim els structs de node i els punters
typedef struct n {
	int num;
	struct n *ant;
	struct n *seg;
}Node;

typedef struct {
	Node *cap;
	Node *ult;
	Node *pdi;
}LlistaBID;

//Capçalera de les funcions
LlistaBID LLISTABIDORD_crea();
void LLISTABIDORD_insereixDavant(LlistaBID *l, int num);
void LLISTABIDORD_insereixDarrera(LlistaBID *l, int num);
int LLISTABIDORD_consulta(LlistaBID l);
void LLISTABIDORD_esborra(LlistaBID *l);
void LLISTABIDORD_avanca(LlistaBID * l);
void LLISTABIDORD_retrocedeix(LlistaBID *l);
int LLISTABIDORD_fi(LlistaBID l);
int LLISTABIDORD_inici(LlistaBID l);
void LLISTABIDORD_vesInici(LlistaBID *l);
void LLISTABIDORD_vesFinal(LlistaBID *l);
int LLISTABIDORD_buida(LlistaBID l);
void LLISTABIDORD_destrueix(LlistaBID *l);
#endif