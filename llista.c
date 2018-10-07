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

// Tira endarrera una posició
void LLISTABIDORD_retrocedeix (LlistaBID *l) {
	if (l->pdi == l->cap) {
		printf("No podem anar mes enrere\n");
	}
	else {
		l->pdi = l->pdi->ant;
	}
}

int LLISTABIDORD_consulta(LlistaBID l) {
	int num;
	num = -1;
	
	if(l.pdi != l.cap && l.pdi != l.ult) {
		num=l.pdi->num;
	}
  return num;
}

void  LLISTABIDORD_esborra(LlistaBID *l) {
	Node *aux;
	
	if (l->pdi == l->cap || l->pdi == l->ult) {
		printf("Error\n");
	}
	else {
		aux = l->pdi;
		aux->ant->seg = aux->seg;
		aux->seg->ant = aux->ant;
		l->pdi = l->pdi->seg;
		free(aux);
	}
}

void LLISTABIDORD_destrueix(LlistaBID *l) {
	Node *aux;
  
	while (l->cap != NULL) {
		aux = l->cap;
		l->cap = l->cap->seg;
		free(aux);
	}
	l->ult = NULL;
	l->pdi = NULL;
}

void LLISTABIDORD_vesInici(LlistaBID *l) {
	l->pdi = l->cap->seg;
}

int LLISTABIDORD_inici(LlistaBID l) {
	return (l.pdi == l.cap);
}

int LLISTABIDORD_buida(LlistaBID l) {
	return l.cap->seg == l.ult;
}

void LLISTABIDORD_vesFinal(LlistaBID *l) {
	l->pdi = l->ult->ant;
}

int LLISTABIDORD_fi(LlistaBID l) {
	return l.pdi == l.ult;
}

void LLISTABIDORD_avanca(LlistaBID *l) {
	if (l->pdi->seg == NULL) {
		printf("No es pot avançar\n");
	}
	else {
		l->pdi = l->pdi->seg;
	}
}

void LLISTABIDORD_insereixDavant(LlistaBID *l, int num) {
	Node *aux;
	
	if (l->pdi == l->cap) {
    	printf("Error\n");
  	}
	else {
    	aux =(Node*) malloc (sizeof(Node));
   		if (aux == NULL) {
     	 	printf("Error\n");
    	}
		else {
     	aux->num = num;
     	aux->seg = l->pdi;
    	aux->ant = l->pdi->ant;
     	l->pdi->ant = aux;
     	aux->ant->seg = aux;
   		}
	}
}

void LLISTABIDORD_insereixDarrera(LlistaBID *l, int num) {
	Node *aux;
  
	if (l->pdi == l->ult) {
		printf("Error\n");
	}
	else {
		aux =(Node*) malloc (sizeof(Node));
		if (aux == NULL) {
			printf("Error\n");
		}
		else {
			aux->num = num;
			if (l->pdi->seg == NULL) {
				printf("Error\n");
			}
			else {
				aux->num = num;
				aux->seg = l->pdi->seg;
				aux->ant = l->pdi;
				l->pdi->seg->ant = aux;
				l->pdi->seg = aux;
			}
		}
	}
}