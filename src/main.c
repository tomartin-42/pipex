/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:29 by tommy             #+#    #+#             */
/*   Updated: 2021/09/03 12:58:23 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_proces(t_param param, int *pp)
{

}

static void child_proces(t_param param, int *pp)
{

}

int main(int argc, char **argv, char **envp)
{
	t_param	param;
	int		pp[2];
	pid_t	pid;
	
	check(argc, argv);
	get_params(&param, argv, envp);
	pipe(pp);
	pid = fork ();
	if (pid < 0)
		execut_error("Error: in fork()", 2);
	else if (pid == 0)
		child_proces(param, pp);
	else
		parent_proces(param, pp);
	printf("%s - %s -- %s -%s\n",param.file[0], param.file[1], param.cmd[0], param.cmd[1]);
	free(&param);
	system ("leaks pipex");
	//printf ("%s - %s\n", param.file[0], param.file[1]);
	
}

