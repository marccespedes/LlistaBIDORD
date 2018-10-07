#include <stdio.h>
#include <stdlib.h>
#include "llistabidord.h"

// Aquí farem el testing
int main () {

	LlistaBID l;
   	int	num = 3;
	int a = 0;

	//Comprova que funcioni el llista crea
	l = LLISTABIDORD_crea();
	if (l.cap->seg == l.ult) {
		printf("Funcio Buida funciona\n");
	}
	return 0;
}