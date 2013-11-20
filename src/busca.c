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

struct Registro {
	char matricula[9];
	char nome[101];
};

int main(void) {
	puts("Hello World btree"); /* prints Hello World */
	return EXIT_SUCCESS;
}
