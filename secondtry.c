/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondtry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:17:36 by jesusoncrac       #+#    #+#             */
/*   Updated: 2025/05/08 02:04:01 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linetrim(bytes)
{
	int		len;
	char *trimed;

	while (bytes[i] && bytes[i] != '\n')
		len++;
	trimed = ft_substr(ft_strchr(bytes, '\n'), 0, len);
	free(bytes);
	return (trimed);
}

char	*writeline(char *bytes)
{
	int		len;
	char	*line;

	// find the len until the first \n
	while (bytes[i] && bytes[i] != '\n')
		len++;
	// make a substring until the first \n
	return (ft_substr(bytes, 0, len));
}

char	*ft_catbuf(char *bytes, char *buf)
{
	char	*catbuf;
	
	catbuf = ft_strjoin(bytes, buf);
	free(bytes);
	return (catbuf);
}
char	*ft_readline(int fd, char *bytes)
{
	ssize_t		bytes_read;
	char		*buf;

	if (!bytes)
		bytes = calloc(1, sizeof(char));
	buf = (char *) calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (byte_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == - 1)
		{
			free(bytes);
			return (NULL);
		}
		bytes = ft_catbuf(bytes, buf);
		if (ft_strchr(buf, '\n')
				break ;
	}
	free(buf);
	return (bytes);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bytes;

	// read n bytes until a new line is found	
	bytes = ft_readline(fd, bytes);
	// copy the read info until the \n to a new variable
	line = ft_writeline(bytes);
	// save the extra info for the next function call
	bytes = ft_linetrim(bytes);
	// return the entire line 
	return (line);
}
