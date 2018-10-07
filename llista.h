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

#endif