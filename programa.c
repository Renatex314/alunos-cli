#include "programa.h"
#include "texto.h"

DadosPrograma* inicializarPrograma()
{
	DadosPrograma* programa = malloc(sizeof(DadosPrograma));
	
	programa->executando = 0;
	programa->database = criarDatabase();
	programa->opcoes = criarArrayDeOpcoes();
}

void executarPrograma(DadosPrograma *programa)
{
	configurarLinguaPortuguesa();
	
	programa->executando = 1;
	
	int indiceOpcao = 0;
	
	while(programa->executando)
	{
		Array* descricoesOpcoes = opcoesParaTexto(programa->opcoes);
		selecionarAlternativas(descricoesOpcoes, &indiceOpcao, mostrarApresentacao, "", "sair");
			
		realizarOpcao(indiceOpcao, programa);
		limparInterface();
	
		destroy_array_without_free_item(descricoesOpcoes);
	}
}

void finalizarPrograma(DadosPrograma *programa)
{
	destruirDatabase(programa->database);
	destruirArrayDeOpcoes(programa->opcoes);
	free(programa);
	
	imprimirlinha("programa executado com sucesso !");
}

void realizarOpcao(int indiceOpcao, DadosPrograma* programa)
{
	limparInterface();
	
	int quantidadeOpcoes = get_count(programa->opcoes);
	if (indiceOpcao == quantidadeOpcoes)
	{
		programa->executando = 0;
		return;
	}
	
	Opcao* opcao = (Opcao*) get_item(programa->opcoes, indiceOpcao);
	opcao->funcaoOpcao(programa->database);
}


