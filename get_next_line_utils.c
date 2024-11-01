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
int	ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
	{
		if (s[i] == c)
			return (0);
	}
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		total;
	char	*str;
	
	total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (total + 1));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[i] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
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
	while (buffer[i + j])
	{
		temp[j] = buffer[i + j];
		j++;
	}
	temp[j] = '\0';
	free (buffer);
	return (temp);
}
