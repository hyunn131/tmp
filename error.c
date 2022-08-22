/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docho <docho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:07:19 by docho             #+#    #+#             */
/*   Updated: 2022/08/22 15:26:25 by docho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	terminate()
{
	if (errno != 0)
		strerror(errno);
	
	exit(1);
}

void	e_close(int fd)
{
	if (close(fd) < 0)
		terminate();
}

void	e_pipe(int *fd, t_info *info)
{
	if (pipe(fd) == -1)
	{
		terminate();
	}
}

pid_t	e_fork(t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		terminate();
	}
	return (pid);
}