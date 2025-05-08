/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:17:36 by jesusoncrac       #+#    #+#             */
/*   Updated: 2025/05/08 16:24:31 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_linetrim(char *bytes)
{
	int		len;
	char *trimed;

	while (bytes[len] && bytes[len] != '\n')
		len++;
	trimed = ft_substr(ft_strchr(bytes, '\n'), 0, len);
	free(bytes);
	return (trimed);
}

static char	*ft_writeline(char *bytes)
{
	int		len;
	char	*line;

	len = 0;
	while (bytes[len] && bytes[len] != '\n')
		len++;
	bytes[len] = '\n';
	return (ft_substr(bytes, 0, len));
}

static char	*ft_catbuf(char *bytes, char *buf)
{
	char	*catbuf;
	
	catbuf = ft_strjoin(bytes, buf);
	free(bytes);
	return (catbuf);
}
static char	*ft_readline(int fd, char *bytes)
{
	ssize_t		bytes_read;
	char		*buf;

	if (!bytes)
		bytes = calloc(1, sizeof(char));
	buf = (char *) calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == - 1)
		{
			free(bytes);
			return (NULL);
		}
		bytes = ft_catbuf(bytes, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (bytes);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bytes;

	bytes = ft_readline(fd, bytes);
	line = ft_writeline(bytes);
	bytes = ft_linetrim(bytes);
	if (!*bytes)
		free(bytes);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (20)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;	
	}
}
