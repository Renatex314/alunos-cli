#pragma once

#include <stdlib.h>
#include <string.h>
#include "smartarray.h"
#include "aluno.h"

typedef struct {
	Array *listaAlunos;
} Database;

Database* criarDatabase();
void adicionarAluno(Database *database, Aluno *aluno);
void removerAluno(Database *database, int indice);
Aluno* consultarAluno(Database *database, int indice);
Array* consultarListaAlunos(Database *database);
Array* listaAlunosParaTexto(Database* alunos);
void destruirListaAlunosTexto(Array* lista);
void atualizarNotasDB(Database *database, int indice, Notas notas);
void atualizarNomeDB(Database *database, int indice, char *nome);
void atualizarRgmDB(Database *database, int indice, char *rgm);
void destruirDatabase(Database *database);
int consultarTamanhoDatabase(Database *database);
