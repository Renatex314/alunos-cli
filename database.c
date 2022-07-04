#include "database.h"

Database* criarDatabase()
{
	Database *novaDatabase = (Database*) malloc(sizeof(Database));
	novaDatabase->listaAlunos = create_array();
	
	return novaDatabase;
}

void adicionarAluno(Database *database, Aluno *aluno)
{
	push_back(database->listaAlunos, aluno);
}

void removerAluno(Database *database, int indice)
{
	remove_from_index(database->listaAlunos, indice);
}

Aluno* consultarAluno(Database *database, int indice)
{
	return (Aluno*) get_item(database->listaAlunos, indice);
}

Array* consultarListaAlunos(Database *database)
{
	return database->listaAlunos;
}

Array* listaAlunosParaTexto(Database* database)
{
	Array* alunosTexto = create_array();
	
	int quantidadeAlunos = consultarTamanhoDatabase(database);
	
	int i;
	for (i = 0; i < quantidadeAlunos; i++)
	{
		Aluno* aluno = consultarAluno(database, i);
		
		int quantidadeCaracteres = strlen(aluno->nome) + strlen(aluno->rgm) + 20; 
		char* texto = malloc(quantidadeCaracteres);
		snprintf(texto, quantidadeCaracteres, "Nome: %s | RGM: %s", aluno->nome, aluno->rgm);
		
		push_back(alunosTexto, texto);
	}
	
	return alunosTexto;
}

void destruirListaAlunosTexto(Array* lista)
{
	destroy_array_with_free_item(lista);
}

void atualizarNotasDB(Database *database, int indice, Notas notas)
{
	Aluno *aluno = consultarAluno(database, indice);
	atualizarNotasAluno(aluno, notas);
}

void atualizarNomeDB(Database *database, int indice, char *nome)
{
	Aluno *aluno = consultarAluno(database, indice);
	atualizarNomeAluno(aluno, nome);
}

void atualizarRgmDB(Database *database, int indice, char *rgm)
{
	Aluno *aluno = consultarAluno(database, indice);
	atualizarRgmAluno(aluno, rgm);
}

void liberarMemoriaAlunos(Database *database)
{
	int quantidade = consultarTamanhoDatabase(database);
	
	int i;
	for (i = 0; i < quantidade; i++)
	{
		Aluno *aluno = consultarAluno(database, i);
		liberarMemoriaAluno(aluno);
	}
}

void destruirDatabase(Database *database)
{
	liberarMemoriaAlunos(database);
	destroy_array_without_free_item(database->listaAlunos);
	free(database);
}

int consultarTamanhoDatabase(Database *database)
{
	return get_count(database->listaAlunos);
}
