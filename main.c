/***********************************
*  criado por Renato Antoniolli Corte
*  turma CC 2022 manh�
*
*  Nome da aplica��o: Alunos DataBase
*
*  Descri��o:
*		Este � um programa que simula um banco de dados,
*		onde o usu�rio pode: 
*			- Adicionar alunos, 
*			- Remov�-los,
*			- Atualizar suas notas, 
*			- Ver seu boletim,
*			- Ver a lista de alunos
*	
*	Bibliotecas:
*		'Smart Array':
*			Neste projeto eu utilizei uma biblioteca que
*			eu havia constru�do alguns meses atr�s quando
*			estava estudando sobre ponteiros na linguagem
*			C, que � o Smart Array.
*			
*			O motivo que me levou a construir essa biblioteca
*			� a aus�ncia de um array de tamanho din�mico na 
*			linguagem C e tamb�m a necessidade de se verificar
*			a quantidade de elementos em um array, que em alguns
*			casos n�o � poss�vel de se obter nesta linguagem,
*			por conta da fun��o sizeof retornar a quantidade
*			de bytes inicialmente alocado na mem�ria por um 
*			vetor de tamanho fixo, e n�o a mem�ria ocupada
*			pelos itens colocados no array. Sendo assim,
*			constru� uma biblioteca que pudesse registrar
*			esses dados cada vez que um elemento fosse
*			adicionado ou removido, e tamb�m alocar 
*			somente a quantidade de mem�ria que realmente
*			ser� usada.
*			
*			No Smart Array eu decidi armazenar ponteiros void*
*			pois eles s�o considerados ponteiros "universais" na
*			linguagem C.
*		
*		'Database':
*			Essa � uma biblioteca que criei exclusivamente 
*			para esse projeto, ela serve para tornar o 
*			controle de dados mais definido e claro, e 
*			tamb�m para simular um banco de dados contendo
*			uma lista de alunos.
*			
*		'Aluno':
*			Essa � uma biblioteca que criei exclusivamente
*			para esse projeto, ela serve para manipular os
*			dados dos alunos de uma maneira mais clara e 
*			descritiva.
*		
*		'Interface':
*			Essa � uma biblioteca que criei exclusivamente
*			para esse projeto, ela � respons�vel fornecer
*			algumas fun��es para facilitar o processo de
*			mostrar algo na tela.
*
*		'Programa':
*			Essa � uma biblioteca que criei exclusivamente
*			para esse projeto, ela � respons�vel por gerenciar
*			alguns dados relacionados a aplica��o, sendo eles:
*			um ponteiro para o banco de dados e uma variavel
*			para indicar se o programa est� executando.
*			
*			� tamb�m respons�vel por tornar mais claro o 
*			ciclo de vida da aplica��o.
*
*		'Opcoes':
*			Essa � uma biblioteca que criei exclusivamente
*			para esse projeto, ela � respons�vel por implementar
*			as op��es dispon�veis para o usu�rio escolher.
*
*		'FuncoesMostrar e FuncoesPerguntar':
*			Essas s�o bibliotecas que criei exclusivamente
*			para esse projeto, elas s�o respons�veis por implementar
*			as fun��es que mostram algo na tela e as fun��es que
*			obt�m dados perguntando algo ao usu�rio.
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
