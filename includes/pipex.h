/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:33 by tommy             #+#    #+#             */
/*   Updated: 2021/09/05 20:37:33 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_param{
	char	*file[2];
	char	*cmd[2];
	char	**cmd1;
	char	**cmd2;
}	t_param;

void	check(int argc, char **argv, char **env);
void	command_not_found_error(char **cmd);
void	execut_error(char *text, int numerror);
void	get_params(t_param *param, char **argv, char **env);

char	*get_path(char *argv, char **env);
char	*get_correct_path(char **tem_p, char *argv);

void	free_aux(char **aux_path);
void	free_param(t_param *param);

void	open_and_read(t_param param, int *pp);
void	open_and_write(t_param param, int *pp);
#endif
