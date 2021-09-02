/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:37:21 by tommy             #+#    #+#             */
/*   Updated: 2021/09/02 23:47:18 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check(int argc, char **argv)
{
	if (argc != 5 || !ft_strlen(argv[2]) || !ft_strlen(argv[3]))
		execut_error("Error: please, \"./pipex infile cmd1 cmd2 outfile\"\n", 8);
	printf("%s\n", argv[0]);
}

char *get_path(char *argv, char **env)
{
	int		i;
	char	*tem_p;
	char	**aux_path;
	char	*path;

	i = 0;
	while(ft_strncmp(env[i], "PATH=", 5) && env[i])
		i++;
	tem_p = ft_strtrim(env[i], "PATH=");
	aux_path = ft_split(tem_p, ':');
	free(tem_p);
	path = get_correct_path(aux_path, argv);
	return(path);
}

char *get_correct_path(char **tem_p, char *argv)
{
	char	*t_path;
	int		i;
	char	*aux;

	i = 0;
	while(tem_p[i])
	{
		aux = ft_strjoin(tem_p[i], "/");
		t_path = ft_strjoin(aux, argv);
		free(aux);
		if (access(t_path, X_OK))
			break ;
		free(tem_p[i]);
		i++;
	}
	free(tem_p);
	return (t_path);
}