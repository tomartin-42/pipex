/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:50:47 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/02 11:50:27 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_params(t_param *param, char **argv, char **env)
{
	int i;

	i = 0;
	param->file[0] = ft_strdup(argv[1]);
	param->file[1] = ft_strdup(argv[4]);
	
	printf("%s\n", env[0]);
}