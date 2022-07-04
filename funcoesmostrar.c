#include "funcoesmostrar.h"

void mostrarApresentacao()
{
	imprimirlinha("|=========================================|");
	imprimirlinha("|             Alunos Database             |");
	imprimirlinha("|              Versão 2.04                |");
	imprimirlinha("|   Feito por: Renato Antoniolli Corte    |");
	imprimirlinha("|          Turma CC 2022 manhã            |");
	imprimirlinha("|=========================================|");
	imprimirlinha("");
}

void mostrarBoletim(Aluno *aluno)
{
	float PI = aluno->notas.nota_PI;
	float T1 = aluno->notas.nota_T1;
	float T2 = aluno->notas.nota_T2;
	float P1 = aluno->notas.nota_P1;
	float P2 = aluno->notas.nota_P2;
	float media = calcularMediaAluno(aluno);
	
	imprimirlinha("");
	imprimirlinhaF("Nome: {texto} | RGM: {texto}", aluno->nome, aluno->rgm);
	imprimirlinhaF("PI: {real}", PI);
	imprimirlinhaF("T1: {real}", T1);
	imprimirlinhaF("T2: {real}", T2);
	imprimirlinhaF("P1: {real}", P1);
	imprimirlinhaF("P2: {real}", P2);
	imprimirlinhaF("média: {real}", media);
}

void listarAlunos(Array *listaAlunos)
{
	int quantidade = get_count(listaAlunos);
	
	int i;
	for (i = 0; i < quantidade; i++)
	{
		Aluno *aluno = (Aluno*) get_item(listaAlunos, i);
		imprimirAluno(aluno, i);
	}
	
	imprimirlinha("");
	imprimirlinhaF("{inteiro} aluno(s) listados.", quantidade);
}

void imprimirAluno(Aluno *aluno, int indice)
{
	imprimirlinhaF("{inteiro}) Nome: {texto} | RGM: {texto}", indice + 1, aluno->nome, aluno->rgm);
}

void mostrarOpcoes(Array *opcoes)
{
	int quantidadeOpcoes = get_count(opcoes);
	
	imprimirlinha("Qual opção você deseja escolher ?");
	imprimirlinha("");
	
	int i;
	char buff[100];
	for (i = 0; i < quantidadeOpcoes; i++)
	{
		Opcao* opcao = (Opcao*) get_item(opcoes, i);
		
		imprimirlinhaF("{inteiro}) {texto}", i + 1, opcao->descricao);
	}
	
	imprimirlinhaF("{inteiro}) sair", quantidadeOpcoes + 1);
	imprimirlinha("");
}

void imprimirAlunoListaMsg(Array* listaAlunos)
{
	imprimirlinhaF("há {inteiro} aluno(s) disponíveis para selecionar:", get_count(listaAlunos));
	imprimirlinha("");
}

