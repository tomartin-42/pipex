/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:29 by tommy             #+#    #+#             */
/*   Updated: 2021/09/05 20:24:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_proces(t_param param, int *pp, char **env)
{
	int		fd;

	close(pp[0]);
	fd = open(param.file[0], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: ");
		exit(2);
	}
	dup2(fd, 0);
	close(fd);
	dup2(pp[1], 1);
	close (pp[1]);
	if(-1 == execve(param.cmd[0], param.cmd1, env))
		perror("Error");
}

static void	child2_proces(t_param param, int *pp, char **env)
{
	int		fd;

	close(pp[1]);
	fd = open(param.file[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error");
		exit(2);
	}
	dup2(fd, 1);
	close(fd);
	dup2(pp[0], 0);
	close(pp[0]);
	if(-1 == execve(param.cmd[1], param.cmd2, env))
		perror("Error");
}

static void	parent_proces(t_param param, int *pp, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(2);
	}
	else if (pid == 0)
		child2_proces(param, pp, env);
	else
	{
		close(pp[0]);
		close(pp[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_param	param;
	int		pp[2];
	pid_t	pid;

	check(argc, argv, envp);
	get_params(&param, argv, envp);
	pipe(pp);
	pid = fork ();
	if (pid < 0)
		execut_error("Error: in fork()", 2);
	else if (pid == 0)
		child1_proces(param, pp, envp);
	else
		parent_proces(param, pp, envp);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}
