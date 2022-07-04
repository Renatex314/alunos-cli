#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "smartarray.h"

int textosSaoIguais(char* texto1, char* texto2);
int contarNumeroCaracteres(char* texto, char caractere);
int contarSubtexto(char* texto, char* subtexto);
char* obterSubtexto(char* texto, int comeco, int fim);
int acharIndice(char* texto, char* subtexto, int indiceInicial);
Array* obterSubsEntreChaves(char* texto);
Array* obterOuterSubsChaves(char* texto, Array* tokens);
