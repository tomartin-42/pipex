/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:29 by tommy             #+#    #+#             */
/*   Updated: 2021/09/03 11:01:28 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_param	param;
	
	check(argc, argv);
	get_params(&param, argv, envp);
	printf("%s - %s -- %s -%s\n",param.file[0], param.file[1], param.cmd[0], param.cmd[1]);
	free(param.file[0]);
	free(param.file[1]);
	free(param.cmd[0]);
	free(param.cmd[1]);
	system ("leaks pipex");
	//printf ("%s - %s\n", param.file[0], param.file[1]);
	
}