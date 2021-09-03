#include "pipex.h"

void	free_aux(char **aux_path)
{
	int	i;

	i = 0;
	while (aux_path[i])
		free(aux_path[i++]);
	free(aux_path);
}