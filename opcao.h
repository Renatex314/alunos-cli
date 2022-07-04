#pragma once

#include "database.h"

typedef struct {
	char* descricao;
	int valor;
	void (*funcaoOpcao)(Database *database);
} Opcao;

Opcao* criarOpcao(char *descricao, void (*funcaoOpcao)(Database *database), int valor);
