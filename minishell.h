/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docho <docho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:55:26 by docho             #+#    #+#             */
/*   Updated: 2022/09/19 06:00:59 by docho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>
# include <stdlib.h>

typedef struct s_info{
	char	**argv;
	char	**envp;
	int		len;
	int		fd[2];
	int		inputfd;
	int		pid;
}				t_info;


void    free2d(char **ss);
void    terminate(char *str);
void    e_close(int fd);
void    e_pipe(int *fd);
pid_t	e_fork();
bool    ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*joinpath(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void    process(t_info *info);
int     e_wait(pid_t pid);
void    input(char *filename, int *fd);
void	output(char *filename, int *fd);
void	append(char *filename, int *fd);
void	here_doc(char *limiter, int *fd);
bool	isbuiltin(char **argv, char **envp);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
void	splits(char *buffer);

#endif