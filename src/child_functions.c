/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:30:21 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/04 13:34:52 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_and_read(t_param param, int *pp)
{
	int		fd;
	//char	*buff;

	fd = open(param.file[0], O_RDONLY);
	if (fd < 0)
		perror("Error: ");
	dup2(0, fd);
	//while(read(fd, &buff, 32))
	//	;
	dup2(1, pp[0]);
	//close(fd);
}

void	open_and_write(t_param param, int *pp)
{
	int		fd;
	//char	*buff;

	fd = open(param.file[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("Error: ");
	dup2(pp[1], 0);
	//while(write(pp[1], buff, 32))
	//	;
	dup2(1, fd);
	//close(fd);
}