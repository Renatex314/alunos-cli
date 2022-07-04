#pragma once

#define SETA_PRESSIONADA 224
#define SETA_CIMA 72
#define SETA_BAIXO 80
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "smartarray.h"
#include "texto.h"

void configurarLinguaPortuguesa();
void imprimirlinha(char* msg);
void imprimirlinhaF(char* texto, ...);
void imprimiralternativa(char* descricao, int posicao, int selecionada);
void imprimirAlternativas(Array* alternativas, int* selecionado, void (*inicioMsg)(Array* alternativas), char* comecoMsg, char* cancelarMsg);
void selecionarAlternativas(Array* alternativas, int* selecionado, void (*inicioMsg)(Array* alternativas), char* comecoMsg, char* cancelarMsg);
void limparInterface();
void esperarFeedback();
void lerEntrada(char* input);
void lerDecimal(float* input, float minimo, float maximo, char* invalidoMsg, int digitoEscape);
void lerInteiro(int* input, int minimo, int maximo, char* invalidoMsg, int digitoEscape);
