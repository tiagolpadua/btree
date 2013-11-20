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
		 sscanf(line, "%8s%14s", vregistros.data[i].matricula, vregistros.data[i].nome);
	 }

	 for(i = 0; i < vregistros.size; i++){
		 printf("%s\t%s\n",vregistros.data[i].matricula, vregistros.data[i].nome);
	 }

	 fclose(fregistros);

	 fregistros = fopen(REGISTROS_CSV_FILE, "wb");
	 for(i = 0; i < vregistros.size; i++){
		 printf("%s\t%s\n",vregistros.data[i].matricula, vregistros.data[i].nome);
	 }

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
