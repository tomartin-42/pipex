/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:29 by tommy             #+#    #+#             */
/*   Updated: 2021/09/02 11:58:05 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_param	param;
	int	i= 0;

	while (envp[i])
		printf ("%s\n", envp[i++]);
	
	check(argc, argv);
	get_params(&param, argv, envp);
	printf ("%s - %s\n", param.file[0], param.file[1]);
}