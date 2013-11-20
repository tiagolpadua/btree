#ifndef BTREE_H_
#define BTREE_H_


#define REGISTROS_CSV_FILE 			"cadastro.csv"
#define REGISTROS_DAT_FILE 			"cadastro.dat"
#define MATRICULA_LEN				9
#define NOME_LEN					101
#define STR_BUFFER_SIZE 			512

typedef struct {
	char matricula[MATRICULA_LEN];
	char nome[NOME_LEN];
} Registro;

typedef struct {
	int size;
	Registro *data;
} registros_vector;

#endif /* BTREE_H_ */
