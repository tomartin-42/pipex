/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:50:47 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/02 23:48:47 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_params(t_param *param, char **argv, char **env)
{

	param->file[0] = ft_strdup(argv[1]);
	param->file[1] = ft_strdup(argv[4]);
	param->cmd[0] = ft_strdup(argv[2]);
	param->cmd[1] = ft_strdup(argv[3]);
	if(access(argv[2], X_OK))
		param->cmd[0] = get_path(argv[2], env);
	if(access(argv[3], X_OK))
		param->cmd[1] = get_path(argv[3], env);
}