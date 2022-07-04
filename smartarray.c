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

#include "smartarray.h"

Array *create_array() {
	Array *newArray = malloc(sizeof(Array));
	
	newArray->size = 0;
	newArray->items = malloc(0);
	
	return newArray;
}

void push_back (Array* arrPtr, void* item) {
	arrPtr->size = arrPtr->size + sizeof(void*);
	arrPtr->items = (void*)realloc(arrPtr->items, arrPtr->size);
	
	int count = get_count(arrPtr);
	
	arrPtr->items[count - 1] = item;
}

int get_count(Array* arrPtr) {
	return arrPtr->size / sizeof(void*);
}

void* get_item(Array* arrPtr, int index) {
	return arrPtr->items[index];
}

void remove_from_index(Array* arrPtr, int index) {
	int count = get_count(arrPtr);
	
	int i = index;
	int end = count;
	for (i = index; i < end; i++) {
		arrPtr->items[i] = arrPtr->items[i + 1];
	}
	
	arrPtr->size = arrPtr->size - sizeof(void*);
	arrPtr->items = (void*)realloc(arrPtr->items, arrPtr->size);
}

void destroy_array_without_free_item(Array* arrPtr) {
	free(arrPtr->items);
	free(arrPtr);
}

void destroy_array_with_free_item(Array* arrPtr) {
	int count = get_count(arrPtr);
	
	int i;
	for (i = 0; i < count; i++) {
		free(get_item(arrPtr, i));
	}
	
	free(arrPtr->items);
	free(arrPtr);
}
