/***********************************
*  criado por Renato Antoniolli Corte
*  turma CC 2022 manhã
*
*  Nome da aplicação: Alunos DataBase
*
*  Descrição:
*		Este é um programa que simula um banco de dados,
*		onde o usuário pode: 
*			- Adicionar alunos, 
*			- Removê-los,
*			- Atualizar suas notas, 
*			- Ver seu boletim,
*			- Ver a lista de alunos
*	
*	Bibliotecas:
*		'Smart Array':
*			Neste projeto eu utilizei uma biblioteca que
*			eu havia construído alguns meses atrás quando
*			estava estudando sobre ponteiros na linguagem
*			C, que é o Smart Array.
*			
*			O motivo que me levou a construir essa biblioteca
*			é a ausência de um array de tamanho dinâmico na 
*			linguagem C e também a necessidade de se verificar
*			a quantidade de elementos em um array, que em alguns
*			casos não é possível de se obter nesta linguagem,
*			por conta da função sizeof retornar a quantidade
*			de bytes inicialmente alocado na memória por um 
*			vetor de tamanho fixo, e não a memória ocupada
*			pelos itens colocados no array. Sendo assim,
*			construí uma biblioteca que pudesse registrar
*			esses dados cada vez que um elemento fosse
*			adicionado ou removido, e também alocar 
*			somente a quantidade de memória que realmente
*			será usada.
*			
*			No Smart Array eu decidi armazenar ponteiros void*
*			pois eles são considerados ponteiros "universais" na
*			linguagem C.
*		
*		'Database':
*			Essa é uma biblioteca que criei exclusivamente 
*			para esse projeto, ela serve para tornar o 
*			controle de dados mais definido e claro, e 
*			também para simular um banco de dados contendo
*			uma lista de alunos.
*			
*		'Aluno':
*			Essa é uma biblioteca que criei exclusivamente
*			para esse projeto, ela serve para manipular os
*			dados dos alunos de uma maneira mais clara e 
*			descritiva.
*		
*		'Interface':
*			Essa é uma biblioteca que criei exclusivamente
*			para esse projeto, ela é responsável fornecer
*			algumas funções para facilitar o processo de
*			mostrar algo na tela.
*
*		'Programa':
*			Essa é uma biblioteca que criei exclusivamente
*			para esse projeto, ela é responsável por gerenciar
*			alguns dados relacionados a aplicação, sendo eles:
*			um ponteiro para o banco de dados e uma variavel
*			para indicar se o programa está executando.
*			
*			É também responsável por tornar mais claro o 
*			ciclo de vida da aplicação.
*
*		'Opcoes':
*			Essa é uma biblioteca que criei exclusivamente
*			para esse projeto, ela é responsável por implementar
*			as opções disponíveis para o usuário escolher.
*
*		'FuncoesMostrar e FuncoesPerguntar':
*			Essas são bibliotecas que criei exclusivamente
*			para esse projeto, elas são responsáveis por implementar
*			as funções que mostram algo na tela e as funções que
*			obtém dados perguntando algo ao usuário.
************************************/


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include "programa.h"

int main(int argc, char *argv[])
{	
	DadosPrograma *programa = inicializarPrograma();	//configura e inicializa os dados do programa
	executarPrograma(programa);							//executa o programa
	finalizarPrograma(programa);						//finaliza o programa
	
	return 0;
}


//perguntar alunos
//perguntar notas
//consultar boletim
//calcular media
//sair
