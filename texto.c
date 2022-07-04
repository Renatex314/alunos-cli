#include "texto.h"

int textosSaoIguais(char* texto1, char* texto2)
{
	int tamanhoTexto1 = strlen(texto1);
	int tamanhoTexto2 = strlen(texto2);
	
	if (tamanhoTexto1 != tamanhoTexto2) return 0;
	
	int i;
	for (i = 0; i < tamanhoTexto1; i++)
	{
		if (texto1[i] != texto2[i]) return 0;
	}
	
	return 1;
}

int contarNumeroCaracteres(char* texto, char caractere)
{
	int quantidadeCaractere = 0;
	int tamanhoTexto = strlen(texto);
	
	int i;
	for (i = 0; i < tamanhoTexto; i++)
	{
		if (texto[i] == caractere)
		{
			quantidadeCaractere++;
		}
	}
	
	return quantidadeCaractere;
}

int contarSubtexto(char* texto, char* subtexto)
{
	int tamanhoSubtexto = strlen(subtexto);
	int tamanhoTexto = strlen(texto);
	int quantidadeSubtexto = 0;
	
	if (tamanhoSubtexto > tamanhoTexto) return 0;
	
	int i;
	for (i = 0; i <= tamanhoTexto - tamanhoSubtexto; i++)
	{
		char* sub = obterSubtexto(texto, i, i + tamanhoSubtexto);
		
		if (textosSaoIguais(subtexto, sub))
		{
			quantidadeSubtexto++;
		}
		
		free(sub);
	}
	
	return quantidadeSubtexto;
}

//USAR A FUNÇÃO FREE PARA LIBERAR A MEMÓRIA DEPOIS DO USO !!!!!!!!!!!!!!!!!!!!!!!!
char* obterSubtexto(char* texto, int comeco, int fim)
{
	int tamanhoTexto = strlen(texto);
	
	if (comeco > fim || comeco < 0) 
	{
		char* vazio = malloc(1);
		vazio[0] = '\0';
		
		return vazio;
	};
	
	if (fim > tamanhoTexto) fim = tamanhoTexto;
	
	char* novoSubtexto = malloc(fim - comeco + 1);
	memcpy(novoSubtexto, texto + comeco, fim - comeco);
	
	novoSubtexto[fim - comeco] = '\0';
	return novoSubtexto;
}

int acharIndice(char* texto, char* subtexto, int indiceInicial)
{
	int tamanhoSubtexto = strlen(subtexto);
	int tamanhoTexto = strlen(texto);
	
	if (tamanhoSubtexto > tamanhoTexto) return -1;
	
	int i;
	for (i = indiceInicial; i <= tamanhoTexto - tamanhoSubtexto; i++)
	{
		char* sub = obterSubtexto(texto, i, i + tamanhoSubtexto);
		
		if (textosSaoIguais(subtexto, sub)) 
		{
			free(sub);
			return i;	
		}
		
		free(sub);
	}	
	
	return -1;
}

Array* obterSubsEntreChaves(char* texto)
{
	Array* subs = create_array();
	
	int ultimoIndice = acharIndice(texto, "{", 0);
	
	while (ultimoIndice != -1)
	{
		char* sub = obterSubtexto(texto, ultimoIndice, acharIndice(texto, "}", ultimoIndice) + 1);
		push_back(subs, sub);
		
		ultimoIndice = acharIndice(texto, "{", ultimoIndice + 1);
	}
	
	return subs;
}

Array* obterOuterSubsChaves(char* texto, Array* tokens)
{
	Array* outerSubs = create_array();
	
	int startIndex = 0, endIndex = 0;
	
	int i;
	for (i = 0; i < get_count(tokens); i++)
	{
		char* token = (char*) get_item(tokens, i);
		endIndex = acharIndice(texto, token, startIndex);
		
		char* sub = obterSubtexto(texto, startIndex, endIndex);
		push_back(outerSubs, sub);
		
		startIndex = endIndex + strlen(token);
	}
	
	char* sub = obterSubtexto(texto, startIndex, strlen(texto));
	push_back(outerSubs, sub);
	
	return outerSubs;
}








