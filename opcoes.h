#pragma once

#include "smartarray.h"
#include "aluno.h"
#include "database.h"
#include "interface.h"
#include "funcoesperguntar.h"
#include "funcoesmostrar.h"
#include "opcao.h"

Array* criarArrayDeOpcoes();
Array* opcoesParaTexto(Array* opcoes);

void destruirArrayDeOpcoes(Array *opcoes);
void realizarOpcaoAdicionar(Database *database);
void realizarOpcaoAtualizarNotas(Database *database);
void realizarOpcaoListarAlunos(Database *database);
void realizarOpcaoRemoverAluno(Database *database);
void realizarOpcaoMediaAlunos(Database *database);
void realizarOpcaoBoletimAluno(Database *database);
void realizarOpcaoMudarRgm(Database *database);
void realizarOpcaoMudarNome(Database *database);
void realizarOpcaoMudarCorConsole(Database *database);
