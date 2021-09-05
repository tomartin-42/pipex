/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:50:47 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/04 19:05:26 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_params(t_param *param, char **argv, char **env)
{
	param->file[0] = ft_strdup(argv[1]);
	param->file[1] = ft_strdup(argv[4]);
	param->cmd1 = ft_split(argv[2], ' ');
	param->cmd2 = ft_split(argv[3], ' ');
	param->cmd[0] = ft_strdup(param->cmd1[0]);
	param->cmd[1] = ft_strdup(param->cmd2[0]);
	printf("*cmd1= %s\n*cmd2= %s\n", param->cmd[0], param->cmd[1]);
	printf("*cmd1= %s\n*cmd2= %s\n", param->cmd1[0], param->cmd2[0]);
	if (access(param->cmd1[0], X_OK) == 0)
		param->cmd[0] = get_path(param->cmd1[0], env);
	else
		param->cmd[0] = ft_strdup(argv[2]);
	if (access(param->cmd2[0], X_OK) == 0)
		param->cmd[1] = get_path(param->cmd2[0], env);
	else
		param->cmd[1] = ft_strdup(argv[3]);
	printf("**cmd1= %s\n**cmd2= %s\n", param->cmd[0], param->cmd[1]);
	printf("**cmd1= %s\n**cmd2= %s\n", param->cmd1[0], param->cmd2[0]);
}

char	*get_path(char *argv, char **env)
{
	int		i;
	char	*tem_p;
	char	**aux_path;
	char	*path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) && env[i])
		i++;
	tem_p = ft_strtrim(env[i], "PATH=");
	aux_path = ft_split(tem_p, ':');
	free(tem_p);
	path = get_correct_path(aux_path, argv);
	free_aux(aux_path);
	return (path);
}

char	*get_correct_path(char **aux_path, char *argv)
{
	char	*t_path;
	int		i;
	char	*aux;

	i = 0;
	while (aux_path[i])
	{
		aux = ft_strjoin(aux_path[i], "/");
		t_path = ft_strjoin(aux, argv);
		free(aux);
		if (access(t_path, X_OK) == 0)
			break ;
		free(t_path);
		i++;
	}
	if (aux_path[i] == NULL)
	{
		perror("Error: ");
		exit(2);
	}
	return (t_path);
}
