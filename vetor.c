#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include "smartarray.h"
#include "aluno.h"
#include "database.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese");
	
	Array *lista = create_array();
	
	printf("%d\n", get_count(lista));	
}


//perguntar alunos
//perguntar notas
//consultar boletim
//calcular media
//sair
