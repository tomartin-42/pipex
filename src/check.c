/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:37:21 by tommy             #+#    #+#             */
/*   Updated: 2021/09/02 09:40:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check(int argc, char **argv)
{
	if (argc != 5 || !ft_strlen(argv[2]) || !ft_strlen(argv[3]))
		execut_error("Error: please, \"./pipex infile cmd1 cmd2 outfile\"\n", 8);
	printf("%s\n", argv[0]);
}