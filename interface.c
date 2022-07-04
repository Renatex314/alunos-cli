#include "interface.h"

void limparInterface()
{
	system("cls");
}

void esperarFeedback()
{
	system("pause");	
}

void imprimirlinha(char *msg)
{
	printf(" %s\n", msg);
}

/*
Aqui tive que criar uma função que fizesse a mesma coisa que a
função imprimirlinha, mas que permitisse uma formatação de texto
parecida com a do printf. O que me motivou a criar essa função foi
a necessidade de criar um printf que fosse mais legível e necessitasse
de menos argumentos, algo parecido com a função println de algumas outras
linguagens de programação, e a ultima coisa que me motivou a criar essa
função foi a necessidade de se ter um controle geral sobre as operações
de saída do console, para manter todas saídas com o mesmo padrão visual.
*/
void imprimirlinhaF(char* texto, ...)
{ 
	Array* tokens = obterSubsEntreChaves(texto);
	Array* subs = obterOuterSubsChaves(texto, tokens);
	
	int count = get_count(tokens);
	
	printf(" ");
	
	va_list args;
	va_start(args, count);
	
	int i;
	for (i = 0; i < count; i++)
	{
		char* sub = (char*) get_item(subs, i);
		printf(sub);
		
		char* token = (char*) get_item(tokens, i);
		
		if (textosSaoIguais(token, "{inteiro}"))
		{
			printf("%d", va_arg(args, int));
		}
		else if (textosSaoIguais(token, "{real}"))
		{
			printf("%.2f", va_arg(args, double));
		}
		else if (textosSaoIguais(token, "{texto}"))
		{
			char* texto = va_arg(args, char*);
			printf("%s", texto);
		}
		else if (textosSaoIguais(token, "{caractere}"))
		{
			printf("%c", (char)va_arg(args, int));
		}
		
	}
	
	va_end(args);
	
	char* sub = (char*) get_item(subs, count);
	printf(sub);
	printf("\n");
	
	destroy_array_with_free_item(tokens);
	destroy_array_with_free_item(subs);
	
}

/*
Aqui tive que criar uma função que fizesse a mesma coisa
que o scanf faz quando lê um texto, pois aqui nessa função
ele não considera um espaço em branco como fim de linha,
coisa que o scanf faz, o que acaba gerando erros quando se
escreve o nome completo de alguém. Pensei em usar alternativas como
a função fgets(), no entanto ela requer o tamanho da 
variavel "char* input", algo que não é possível realizar, 
pois aqui na função lerTexto o operador sizeof não retorna 
o valor correto de bytes ocupados pelo "char* input", por 
conta do input ser do tipo char*.
*/
void lerTexto(char* input)
{
	printf("> ");
	
	char* buff = malloc(0);
	
	int concluido = 0, teclasEscritas = 0;
	while (!concluido)
	{
		int tecla = getch();
		
		switch (tecla)
		{
			case TECLA_ENTER:
				concluido = 1;
			
				buff = realloc(buff, teclasEscritas + 1);
				buff[teclasEscritas] = '\0';
				break;
			
			case TECLA_BACKSPACE:
				printf("\b ");
				if (teclasEscritas > 0)
				{
					printf("%c", tecla);	
					teclasEscritas--;
					
					buff = realloc(buff, teclasEscritas);
				}
				break;
			
			default:
				printf("%c", tecla);
				teclasEscritas++;
				
				buff = realloc(buff, teclasEscritas);
				buff[teclasEscritas - 1] = tecla;
				break;
		}

	}
	
	memcpy(input, buff, strlen(buff) + 1);
	free(buff);
	
	printf("\n");
}

void imprimiralternativa(char* descricao, int posicao, int selecionada)
{
	char selecionadaSimbolo = selecionada ? '>' : ' ';
	imprimirlinhaF(" {caractere} {inteiro}) {texto}", selecionadaSimbolo, posicao, descricao);
}

void imprimirAlternativas(Array* alternativas, int* selecionado, void (*inicioMsg)(Array* alternativas), char* comecoMsg, char* cancelarMsg)
{
	imprimirlinha(comecoMsg);
	inicioMsg(alternativas);
	
	int quantidadeAlternativas = get_count(alternativas);
	
	int i;
	for (i = 0; i < quantidadeAlternativas; i++)
	{
		char* alternativaDescricao = (char*) get_item(alternativas, i);
		int seAlternativaSelecionada = (*selecionado == i);
		int posicao = i + 1;
		
		imprimiralternativa(alternativaDescricao, posicao, seAlternativaSelecionada);
	}
	
	imprimiralternativa(cancelarMsg, quantidadeAlternativas + 1, *selecionado == quantidadeAlternativas);
}

void selecionarAlternativas(Array* alternativas, int* selecionado, void (*inicioMsg)(Array* alternativas), char* comecoMsg, char* cancelarMsg)
{
	int sair = 0;
	int quantidadeAlternativas = get_count(alternativas);
	
	while (!sair)
	{
		limparInterface();
		imprimirAlternativas(alternativas, selecionado, inicioMsg, comecoMsg, cancelarMsg);
		
		int teclaPressionada = getch();
		
		if (teclaPressionada == SETA_PRESSIONADA)
		{	
			switch(getch())
			{
				case SETA_CIMA:
					(*selecionado)--;
					break;
				
				case SETA_BAIXO:
					(*selecionado)++;
					break;
			}
		}
		
		if (teclaPressionada == TECLA_ENTER)
		{
			sair = 1;
		}
		
		if (*selecionado < 0)
		{
			*selecionado = quantidadeAlternativas;
		}
		else if (*selecionado > quantidadeAlternativas)
		{
			*selecionado = 0;
		}
	
	}
}

int numeroEValido(float numero, float minimo, float maximo, int digitoEscape)
{
	int resultado = minimo <= numero && numero <= maximo;
	
	if (digitoEscape)
	{
		resultado = resultado || numero == -1;
	}
	
	return resultado;
}

void lerNumero(int eFloat, int *inputInteiro, float *inputFloat, float minimo, float maximo, char *invalidoMsg, int digitoEscape)
{
	int valido = 0;
	
	while (!valido)
	{
		printf("> ");
		
		if (eFloat)
		{
			scanf(" %f", inputFloat);		
			valido = numeroEValido(*inputFloat, minimo, maximo, digitoEscape);
		}
		else
		{
			scanf(" %d", inputInteiro);
			valido = numeroEValido(*inputInteiro, minimo, maximo, digitoEscape);
		}
		
		if (!valido)
		{
			imprimirlinha(invalidoMsg);
		}
	}
}

void lerDecimal(float *input, float minimo, float maximo, char* invalidoMsg, int digitoEscape)
{
	lerNumero(1, NULL, input, minimo, maximo, invalidoMsg, digitoEscape);
}

void lerInteiro(int *input, int minimo, int maximo, char* invalidoMsg, int digitoEscape)
{
	lerNumero(0, input, NULL, (float) minimo, (float) maximo, invalidoMsg, digitoEscape);
}

void configurarLinguaPortuguesa()
{
	setlocale(LC_ALL, "portuguese");
}
