/*
 ============================================================================
 Name        : btree.c
 Author      : Tiago Lage Payne de Pádua, Pedro Mohn
 Version     : 0.1
 Copyright   : UnB
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(void) {
	FILE *fregistros;
	char line[STR_BUFFER_SIZE];
	registros_vector vregistros;
	int qtd_registros = 0;
	int i = 0;

	puts("Iniciando Populador de cadastro");

	fregistros = fopen(REGISTROS_CSV_FILE, "rt");

	if (fregistros == NULL ) {
		puts("Arquivo de registros não pode ser lido.");
		return EXIT_FAILURE;
	}

	// Contando os registros do arquivo
	while (fgets(line, STR_BUFFER_SIZE, fregistros) != NULL) {
		qtd_registros++;
	}
	rewind(fregistros);

	printf("%d registros lidos\n", qtd_registros);

	 vregistros.size = qtd_registros;
	 vregistros.data = (Registro*) malloc(sizeof(Registro) * qtd_registros);

	 for(i = 0; i < qtd_registros; i++){
		 fgets(line, STR_BUFFER_SIZE, fregistros);
		 //sscanf(line, "%9s%10s", vregistros.data[i].matricula, vregistros.data[i].nome);
		 sscanf(line, "%9s", vregistros.data[i].matricula);
	 }

	 for(i = 0; i < qtd_registros; i++){
		 //printf("%s-%s\n",vregistros.data[i].matricula, vregistros.data[i].nome);
		 printf("%9s\n",vregistros.data[i].matricula);
	 }

	 fclose(fregistros);

	 //+++++++++++++++++++++++++++++++++++++++++++++++++
	 puts("Populador de cadastro finalizado com sucesso");

	 /*

	 sscanf("Teste", "%10s", vregistros.data[0].matricula);
	 //vregistros.data[0].matricula = "980980"; vregistros.data[0].nome = "JOAO PEDRO";

	 int i = 0;
	 for(i = 0; i < qtd; i++){
	 puts(vregistros.data[i].matricula);
	 puts(vregistros.data[i].nome);
	 puts("\n");
	 }
	 */

	return EXIT_SUCCESS;
}
