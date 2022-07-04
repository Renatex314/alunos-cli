/***********************************
*  criado por Renato Antoniolli Corte
*  turma CC 2022 manhã
*
*  Smart Array
*
*  Biblioteca que implementa um Array de ponteiros
************************************/

//OBS: A liberação de memória dos dados armazenados dentro do array é responsabilidade do programador !
//   : O item não é liberado da memória quando ele é removido do array !
//	 : Os itens não são liberados da memória quando o array é destruido !

#pragma once

#include <stdlib.h>

typedef struct {
	int size;	  //tamanho do array em bytes
	void **items; //array de ponteiros
} Array;

Array *create_array();

void push_back(Array* mArray, void *item);
void* get_item(Array* mArray, int index);
int get_count(Array* mArray);
void remove_from_index(Array* mArray, int index);
void destroy_array_without_free_item(Array* arrPtr);
void destroy_array_with_free_item(Array* mArray);
