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

char *ft_read(int fd, char *buffer)
{
	char	*temp;
	int		byte;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	byte = 1;
	while (!ft_strchr(buffer, '\n') && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char *get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
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
