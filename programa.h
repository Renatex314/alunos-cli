#pragma once

#include "interface.h"
#include "database.h"
#include "opcao.h"
#include "opcoes.h"

typedef struct {
	int executando;
	Database *database;
	Array *opcoes;
} DadosPrograma;

DadosPrograma* inicializarPrograma();
void executarPrograma(DadosPrograma *programa);
void finalizarPrograma(DadosPrograma *programa);
void realizarOpcao(int indiceOpcao, DadosPrograma* programa);
