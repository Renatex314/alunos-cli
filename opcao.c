#include "opcao.h"

Opcao* criarOpcao(char *descricao, void (*funcaoOpcao)(Database *database), int valor)
{
	Opcao *opcao = malloc(sizeof(Opcao));
	opcao->descricao = descricao;
	opcao->funcaoOpcao = funcaoOpcao;
	opcao->valor = 0;
}

void destruirOpcao(Opcao* opcao)
{
	free(opcao);
}
