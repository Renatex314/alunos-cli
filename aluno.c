#include "aluno.h"

Aluno* criarAluno()
{
	Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
	aluno->nome = malloc(0);
	aluno->rgm = malloc(0);
	
	return aluno;
}

void liberarMemoriaAluno(Aluno *aluno)
{
	free(aluno->nome);
	free(aluno->rgm);
	free(aluno);
}

float calcularMedia(float PI, float P1, float P2, float T1, float T2)
{
	return PI * 0.5 + T1 * 0.1 + T2 * 0.1 + P1 * 0.15 + P2 * 0.15;
}

void atualizarNomeAluno(Aluno *aluno, char *nome)
{
	free(aluno->nome);	

	aluno->nome = nome;
}

void atualizarRgmAluno(Aluno *aluno, char *rgm)
{
	free(aluno->rgm);
	
	aluno->rgm = rgm;
}

void atualizarNotasAluno(Aluno *aluno, Notas notas)
{
	aluno->notas = notas;
}

float calcularMediaAluno(Aluno *aluno)
{
	float PI = aluno->notas.nota_PI;
	float P1 = aluno->notas.nota_P1;
	float P2 = aluno->notas.nota_P2;
	float T1 = aluno->notas.nota_T1;
	float T2 = aluno->notas.nota_T2;
	
	return calcularMedia(PI, P1, P2, T1, T2);
}

float calcularMediaAlunos(Array *listaAlunos)
{
	int quantidadeAlunos = get_count(listaAlunos);
	float somaNotas = 0;
	
	if (quantidadeAlunos == 0) return 0;
	
	int i;
	for (i = 0; i < quantidadeAlunos; i++)
	{
		Aluno *aluno = (Aluno*) get_item(listaAlunos, i);
		float mediaAluno = calcularMediaAluno(aluno);
		
		somaNotas += mediaAluno;
	}
	
	return somaNotas / quantidadeAlunos;
}
