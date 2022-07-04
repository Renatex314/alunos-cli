#include "atualizarnotas.h"
#include "listaralunos.h"

void perguntarPosicaoListaAluno(Database *database, int quantidadeAlunos, int *posicao)
{
	imprimirlinha("Digite o número do aluno que deseja atualizar as notas, ou -1 para sair:");
	lerInteiro(posicao, 1, quantidadeAlunos, "número inválido ou fora da lista de alunos ! digite novamente:", 1);
}

void realizarOpcaoAtualizarNotas(Database *database)
{	
	while (1)
	{
		limparInterface();
		
		Notas notas;
		int posicao;
		
		perguntarPosicaoAlunoAtualizar(database, consultarTamanhoDatabase(database), &posicao);
		
		if (posicao == -1) break;
		
		imprimirlinha("");
		imprimirlinha("Agora digite as notas atualizadas:");
		perguntarNotas(&notas);
		atualizarNotas(database, posicao - 1, notas);
		
		imprimirlinha("");
		imprimirlinha("Notas atualizadas com sucesso !");
		imprimirlinha("");
		esperarFeedback();		
	}
}



