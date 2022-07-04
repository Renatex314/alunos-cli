#pragma once

#include "interface.h"
#include "smartarray.h"
#include "database.h"
#include "funcoesmostrar.h"

void perguntarOpcao(int *opcao, int quantidadeOpcoes);
void perguntarNome(char *nome);
void perguntarRgm(char *rgm);
void perguntarNota(char* msg, int *nota);
void perguntarNotas(Notas *notas);
void perguntarPosicaoListaAlunos(int quantidadeAlunos, int *posicao);
void perguntarAlunoLista(Database *database, int* opcao, char* inicioMsg);
