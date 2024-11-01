/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:47:08 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/31 11:50:17 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
// Main

char	*ft_read(int fd, char *stash);
char	*get_next_line(int fd);
// Utils
int	ft_strchr(const char *s, int c);
int	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_getline(char *buffer);
char	*ft_bufferupdt(char *buffer);

#endif

