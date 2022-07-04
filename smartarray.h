/***********************************
*  criado por Renato Antoniolli Corte
*  turma CC 2022 manh�
*
*  Smart Array
*
*  Biblioteca que implementa um Array de ponteiros
************************************/

//OBS: A libera��o de mem�ria dos dados armazenados dentro do array � responsabilidade do programador !
//   : O item n�o � liberado da mem�ria quando ele � removido do array !
//	 : Os itens n�o s�o liberados da mem�ria quando o array � destruido !

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
