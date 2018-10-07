#include <stdlib.h>
#include "llistabidord.h"

//Creem la llista Bidireccional Ordenada
LlistaBID LLISTABIDORD_crea() {
	LlistaBID l;
	
	l.cap = (Node*) malloc (sizeof(Node));
	if (l.cap == NULL) {
		printf("Error!\n");
	}
	else {  
		l.ult = (Node*) malloc(sizeof(Node));
		if (l.ult==NULL) {
			printf("Error\n");
			free(l.cap);
		}
		else {
			l.pdi = l.ult;
			l.cap->seg = l.ult;
			l.ult->ant = l.cap;
			l.cap->ant = NULL;
			l.ult->seg = NULL;
		}
	}
	return l;
}
