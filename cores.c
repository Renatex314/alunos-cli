#include "cores.h"

Array* criarArrayDeCores()
{
	Array* cores = create_array();

	push_back(cores, criarOpcao("cor verde", NULL, COR_VERDE));
	push_back(cores, criarOpcao("cor vermelha", NULL, COR_VERMELHA));
	
	return cores;
}

void mudarCorConsole(int codigoCor)
{
	
}
