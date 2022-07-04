#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "smartarray.h"
#include "opcao.h"

#define COR_VERDE 		0x0A
#define COR_VERMELHA 	0x0C
#define COR_AMARELA 	0x0E
#define COR_AZUL 		0x09
#define COR_BRANCA 		0x0F
#define COR_ROXA 		0x0D

Array* criarArrayDeCores();
void mudarCorConsole(int codigoCor);
