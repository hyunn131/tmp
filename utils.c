/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docho <docho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:49:14 by docho             #+#    #+#             */
/*   Updated: 2022/09/19 05:26:49 by docho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free2d(char **ss)
{
	int	i;

	if (!ss)
		return;
	i = -1;
	while (ss[++i])
		free(ss[i]);
	free(ss);
}

bool	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while(s1[++i])
	{
		if(s1[i] != s2[i])
			break ;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (true);
	return (false);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = dst;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		while (i < len)
		{
			d[len - i - 1] = s[len - i - 1];
			i++;
		}
	}
	return (dst);
}

char	*joinpath(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	if (!s2)
		s2len = 0;
	else
		s2len = ft_strlen(s2);
	str = (char *)malloc((s1len + s2len + 2) * sizeof(char));
	if (!str)
		return (0);
	ft_memmove(str, s1, s1len * sizeof(char));
	ft_memmove(str + s1len + 1, s2, s2len * sizeof(char));
	str[s1len] = '/';
	str[s1len + s2len + 1] = '\0';
	free(s2);
	return (str);
}