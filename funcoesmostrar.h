#pragma once

#include "aluno.h"
#include "smartarray.h"
#include "interface.h"
#include "opcao.h"

void mostrarApresentacao();
void mostrarBoletim(Aluno *aluno);
void listarAlunos(Array *listaAlunos);
void imprimirAluno(Aluno *aluno, int indice);
void mostrarOpcoes(Array *opcoes);
void imprimirAlunoListaMsg(Array* listaAlunos);
