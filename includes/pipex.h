/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:33 by tommy             #+#    #+#             */
/*   Updated: 2021/09/03 10:57:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


typedef struct s_param{
	char	*file[2];
	char	*cmd[2];
}	t_param;

void	check(int argc, char **argv);
void	execut_error(char *text, int numerror);
void	get_params(t_param *param, char **argv, char **env);

char	*get_path(char *argv, char **env);
char	*get_correct_path(char **tem_p, char *argv);

void	free_aux(char **aux_path);

#endif 