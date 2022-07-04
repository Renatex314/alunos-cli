#include "funcoesperguntar.h"

void perguntarOpcao(int *opcao, int quantidadeOpcoes)
{
	lerInteiro(opcao, 1, quantidadeOpcoes, "opção inválida ! digite a opção novamente:", 0);
}

void perguntarNome(char *nome)
{
	imprimirlinha("Qual o nome do aluno ?");
	lerTexto(nome);
}

void perguntarRgm(char *rgm)
{
	imprimirlinha("Qual o RGM do aluno ?");
	lerTexto(rgm);
}

void perguntarNota(char* msg, int *nota)
{
	imprimirlinha(msg);
	lerInteiro(nota, 0, 10, "Nota digitada incorretamente ! digite novamente:", 0);
}

void perguntarNotas(Notas *notas)
{
	int PI, T1, T2, P1, P2;
	
	perguntarNota("Digite a nota da PI:", &PI);
	perguntarNota("Digite a nota da T1:", &T1);
	perguntarNota("Digite a nota da T2:", &T2);
	perguntarNota("Digite a nota da P1:", &P1);
	perguntarNota("Digite a nota da P2:", &P2);
	
	notas->nota_PI = PI;
	notas->nota_T1 = T1;
	notas->nota_T2 = T2;
	notas->nota_P1 = P1;
	notas->nota_P2 = P2;
}

void perguntarPosicaoListaAlunos(int quantidadeAlunos, int *posicao)
{
	imprimirlinha("Digite o número do aluno, ou digite -1 para sair:");
	lerInteiro(posicao, 1, quantidadeAlunos, "número inválido ou fora da lista de alunos ! digite novamente:", 1);
}

void perguntarAlunoLista(Database *database, int* opcao, char* inicioMsg)
{
	Array* listaAlunos = listaAlunosParaTexto(database);
	selecionarAlternativas(listaAlunos, opcao, imprimirAlunoListaMsg, inicioMsg, "cancelar");
	destruirListaAlunosTexto(listaAlunos);
}




