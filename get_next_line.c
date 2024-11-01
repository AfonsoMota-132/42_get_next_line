/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:47:47 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/31 12:09:28 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *stash)
{
	char	*temp;
	int		byte;

	byte = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(stash, '\n') && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	return(stash);
}

char *get_next_line(int fd)
{
	char	*line;
	static char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	line = ft_getline(buffer);
	buffer = ft_bufferupdt(buffer);
	return (line);
}
