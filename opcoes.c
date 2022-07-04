#include "opcoes.h"

Array* criarArrayDeOpcoes()
{
	Array* opcoes = create_array();
	
	push_back(opcoes, criarOpcao("Adicionar aluno", 				&realizarOpcaoAdicionar		, 0));
	push_back(opcoes, criarOpcao("Atualizar notas", 				&realizarOpcaoAtualizarNotas, 0));
	push_back(opcoes, criarOpcao("Mostrar média total dos alunos", 	&realizarOpcaoMediaAlunos	, 0));
	push_back(opcoes, criarOpcao("Mostrar boletim", 				&realizarOpcaoBoletimAluno	, 0));
	push_back(opcoes, criarOpcao("Listar alunos", 					&realizarOpcaoListarAlunos	, 0));
	
	push_back(opcoes, criarOpcao("Remover aluno", 					&realizarOpcaoRemoverAluno	, 0));
	push_back(opcoes, criarOpcao("Alterar RGM aluno", 				&realizarOpcaoMudarRgm		, 0));
	push_back(opcoes, criarOpcao("Alterar Nome aluno", 				&realizarOpcaoMudarNome		, 0));

	return opcoes;
}

Array* opcoesParaTexto(Array* opcoes)
{
	Array* descricoes = create_array();
	
	int i;
	for (i = 0; i < get_count(opcoes); i++)
	{
		Opcao* opcao = (Opcao*) get_item(opcoes, i);
		push_back(descricoes, opcao->descricao);
	}
	
	return descricoes;
}

void destruirArrayDeOpcoes(Array *opcoes)
{
	destroy_array_with_free_item(opcoes);
}

void realizarOpcaoAdicionar(Database *database)
{
	Aluno* aluno = criarAluno();
	char* nome = malloc(1000 * sizeof(char));
	char* rgm = malloc(1000 * sizeof(char));
	Notas notas;
	
	perguntarNome(nome);
	perguntarRgm(rgm);
	perguntarNotas(&notas);
	
	//realoca a memoria para utilizar apenas o necessário
	nome = realloc(nome, strlen(nome) + 1);
	rgm = realloc(rgm, strlen(rgm) + 1);
	
	atualizarNomeAluno(aluno, nome);
	atualizarRgmAluno(aluno, rgm);
	atualizarNotasAluno(aluno, notas);
	
	adicionarAluno(database, aluno);
	
	imprimirlinha("");
	imprimirlinha("Aluno adicionado com sucesso !");
	imprimirlinha("");
	esperarFeedback();
}

void realizarOpcaoAtualizarNotas(Database *database)
{	
	int usuarioNaoSair = 1;

	while (usuarioNaoSair)
	{
		limparInterface();
		
		Notas notas;
		int indiceAluno, quantidadeAlunos;
		
		quantidadeAlunos = consultarTamanhoDatabase(database);
		perguntarAlunoLista(database, &indiceAluno, "Selecione o aluno que deseja atualizar as notas: ");
		
		if (indiceAluno == quantidadeAlunos) break;
		
		imprimirlinha("");
		imprimirlinha("Agora digite as notas atualizadas:");
		perguntarNotas(&notas);
		atualizarNotasDB(database, indiceAluno, notas);
		
		imprimirlinha("");
		imprimirlinha("Notas atualizadas com sucesso !");
		imprimirlinha("");
		esperarFeedback();
	}
}

void realizarOpcaoListarAlunos(Database *database)
{
	listarAlunos(consultarListaAlunos(database));
	
	imprimirlinha("");
	imprimirlinha("Alunos listados com sucesso !");
	imprimirlinha("");
	esperarFeedback();
}

void realizarOpcaoRemoverAluno(Database *database)
{
	int usuarioNaoSair = 1;
	
	while (usuarioNaoSair)
	{
		limparInterface();
	
		int indiceAluno, quantidadeAlunos;
		
		quantidadeAlunos = consultarTamanhoDatabase(database);
		perguntarAlunoLista(database, &indiceAluno, "Selecione o aluno que deseja remover: ");
		
		if (indiceAluno == quantidadeAlunos) return;
		
		removerAluno(database, indiceAluno);
		
		imprimirlinha("");
		imprimirlinha("Aluno removido com sucesso !");
		imprimirlinha("");
		esperarFeedback();
	}
}

void realizarOpcaoMediaAlunos(Database *database)
{
	float mediaTotal = calcularMediaAlunos(consultarListaAlunos(database));
	
	imprimirlinhaF("A média total dos alunos é: {real}", mediaTotal);
	esperarFeedback();
}

void realizarOpcaoBoletimAluno(Database *database)
{
	int usuarioNaoSair = 1;
	
	while (usuarioNaoSair)
	{
		limparInterface();
	
		int indiceAluno, quantidadeAlunos;
		
		quantidadeAlunos = consultarTamanhoDatabase(database);
		perguntarAlunoLista(database, &indiceAluno, "Selecione o aluno que deseja ver o boletim: ");
		
		if (indiceAluno == quantidadeAlunos) return;
		
		Aluno *aluno = consultarAluno(database, indiceAluno);
		mostrarBoletim(aluno);
		
		imprimirlinha("");
		imprimirlinha("Boletim apresentado com sucesso !");
		imprimirlinha("");
		esperarFeedback();
	}
}

void realizarOpcaoMudarNome(Database *database)
{
	int indiceAluno, quantidadeAlunos;
		
	quantidadeAlunos = consultarTamanhoDatabase(database);
	perguntarAlunoLista(database, &indiceAluno, "Selecione o aluno que deseja mudar o nome: ");
	
	if (indiceAluno == quantidadeAlunos) return;
	
	Aluno* aluno = consultarAluno(database, indiceAluno);
	char* nomeAtualizado = malloc(1000 * sizeof(char));
	
	imprimirlinha("Agora digite o nome atualizado do aluno:");
	perguntarNome(nomeAtualizado);
	
	nomeAtualizado = realloc(nomeAtualizado, strlen(nomeAtualizado) + 1);
	
	atualizarNomeAluno(aluno, nomeAtualizado);
	
	imprimirlinha("");
	imprimirlinha("Nome atualizado com sucesso !");
	imprimirlinha("");
	esperarFeedback();
}

void realizarOpcaoMudarRgm(Database *database)
{
	int indiceAluno, quantidadeAlunos;
		
	quantidadeAlunos = consultarTamanhoDatabase(database);
	perguntarAlunoLista(database, &indiceAluno, "Selecione o aluno que deseja alterar o RGM: ");
	
	if (indiceAluno == quantidadeAlunos) return;
	
	Aluno* aluno = consultarAluno(database, indiceAluno);
	char* rgmAtualizado = malloc(1000 * sizeof(char));
	
	imprimirlinha("Agora digite o RGM atualizado do aluno:");
	perguntarRgm(rgmAtualizado);
	
	rgmAtualizado = realloc(rgmAtualizado, strlen(rgmAtualizado) + 1);
	
	atualizarRgmAluno(aluno, rgmAtualizado);
	
	imprimirlinha("");
	imprimirlinha("RGM atualizado com sucesso !");
	imprimirlinha("");
	esperarFeedback();
}

void realizarOpcaoMudarCorConsole(Database *database)
{
	
}
