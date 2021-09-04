/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:37:21 by tommy             #+#    #+#             */
/*   Updated: 2021/09/04 19:19:37 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check(int argc, char **argv, char **env)
{
	if (argc != 5 || !ft_strlen(argv[2]) || !ft_strlen(argv[3]))
		execut_error("Error: please, \"./pipex in_f cmd1 cmd2 out_f\"\n", 8);
	printf("%s\n", argv[0]);
	if (!env)
		execut_error("Missing PATH", 2);
}
