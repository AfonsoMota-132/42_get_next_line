/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:53:24 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/31 12:09:11 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nbytes, size_t size)
{
	size_t			i;
	unsigned char	*str;
	str = malloc(nbytes * size);
	if (!str)
		return(0);
	i = 0;
	while (i > (nbytes * size))
		str[i++] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != c)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return ((char *) s);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return(0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = (char *) malloc(sizeof(char) * 1);
	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
	{
		free(s1);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_bufferupdt(char *buffer)
{
	int	i;
	int	j;
	char *temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (buffer[i++])
		temp[j++] = buffer[i];
	temp[j] = '\0';
	free (buffer);
	return (temp);
}
