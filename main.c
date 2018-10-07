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
	if (LLISTABIDORD_buida(l)) {
		printf("Funcio Buida funciona\n");
	}
	
	//Comprova que funcioni el insereix davant, el retrocedeix, el buida, el esborra i  el consulta
	LLISTABIDORD_insereixdavant(&l, num);
	if (LLISTABIDORD_buida(l)){
		printf("Buida no funciona\n");
	}else{
		printf("Buida funciona\n");
	}
	LLISTABIDORD_retrocedeix(&l);
	LLISTABIDORD_esborra(&l);
	LLISTABIDORD_insereixdavant(&l, 4);
	LLISTABIDORD_insereixdavant(&l, 6);
	LLISTABIDORD_insereixdavant(&l, 7);
	LLISTABIDORD_insereixdavant(&l, 9);
	LLISTABIDORD_insereixdavant(&l, 1);
	LLISTABIDORD_retrocedeix(&l);
	a = LLISTABIDORD_consulta(l);
	printf("w%dw\n", a);
	
	// Comprova que  funcioni el inici, ves inici, insereix darrera i avanca.
	LLISTABIDORD_vesInici(&l);
	LLISTABIDORD_retrocedeix(&l);	
	
	if (LLISTABIDORD_inici(l)) {
		LLISTABIDORD_avanca(&l);
		LLISTABIDORD_insereixDarrera(&l, 23);
		LLISTABIDORD_avanca(&l);
		a = LLISTABIDORD_consulta(l);
		printf("@%d@\n", a);
	}
	
	//Comprova que funcioni el ves final i fi
	LLISTABIDORD_vesFinal(&l);
	LLISTABIDORD_avanca(&l);

	if (LLISTABIDORD_fi(l)) {
		LLISTABIDORD_retrocedeix(&l);	
		a = LLISTABIDORD_consulta(l);
		printf("|%d|\n", a);
	}

	//Comprova que funcioni insereix davant ordenat i insereix darrera ordenat
	LLISTABIDORD_insereixdavant(&l, 3);
	LLISTABIDORD_insereixdavant(&l, 5);
	LLISTABIDORD_insereixdavant(&l, 8);
	LLISTABIDORD_insereixdavant(&l, 12);
	LLISTABIDORD_insereixdavant(&l, 15);
	LLISTABIDORD_vesInici(&l);
	LLISTABIDORD_avanca(&l);
	LLISTABIDORD_avanca(&l);
	LLISTABIDORD_insereixdavantOrdenat(&l, 4);
	LLISTABIDORD_insereixdarreraOrdenat(&l, 13);
	LLISTABIDORD_vesInici(&l);
	
	while (l.pdi != l.ult) {
		a = LLISTABIDORD_consulta(l);
		printf("-%d-\n", a);
		l.pdi = l.pdi->seg;
	}

	// Comprova que funcioni el destrueix
	LLISTABIDORD_destrueix(&l);
	if (l.ult == NULL) {
		printf("S'ha borrat correctment la llista\n");
	}
	return 0;
}