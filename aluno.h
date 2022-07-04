#pragma once

#include <stdlib.h>
#include "smartarray.h"

typedef struct {
	float nota_PI;
	float nota_T1;
	float nota_T2;
	float nota_P1;
	float nota_P2;
} Notas;

typedef struct {
	char *nome;
	char *rgm;
	
	Notas notas;
} Aluno;

Aluno* criarAluno();
void atualizarNomeAluno(Aluno *aluno, char *nome);
void atualizarRgmAluno(Aluno *aluno, char *rgm);
void atualizarNotasAluno(Aluno *aluno, Notas notas);
void liberarMemoriaAluno(Aluno *aluno);
float calcularMediaAluno(Aluno *aluno);
float calcularMediaAlunos(Array *alunos);
