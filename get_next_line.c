/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:49:43 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/08 01:16:51 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bytemove(char *bytes)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	tmp = bytes;
	while (bytes[i] != '\n')
	{
		tmp++;
		i++;
	}
	i = 0;
	tmp++;
	while (*tmp)
	{
		bytes[i++] = *(tmp++);
	}
	bytes[i] = '\0';
}

char	*ft_writeline(char *stash)
{
	int		i;
	int		stash_len;
	char	*line;	

	i = 0;
	stash_len = 0;
	if (*stash)
		stash_len = ft_strlen(stash);
	line = (char *) malloc (sizeof(char) * (stash_len + 1));
	if (!line)
		return (NULL);
	while (i < stash_len && *stash != '\n')
		line[i++] = *(stash++);
	if (i < stash_len)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	ft_found_newline(char *buf, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buf[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_addbytes(char *stash, char *buf, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t	j;
	char	*bytes;

	i = 0;
	j = 0;
	if (!stash || !buf)
		return (NULL);
	bytes = (char *) malloc(sizeof(char) * (ft_strlen(stash) + bytes_read + 1));
	while (stash[i])
	{
		bytes[i] = stash[i];
		i++;
	}
	free(stash);
	while (j < bytes_read)
	{
		bytes[i + j] = buf[j];
		j++;
	}
	bytes[i + j] = '\0';
	return (bytes);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	static char	*bytes;
	char		*line;
	char		buf[BUFFER_SIZE];

	line = NULL;
	bytes_read = 0;
	if (bytes == NULL)
		bytes = ft_bytes_init();
	while (!ft_found_newline(buf, bytes_read))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(bytes);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		bytes = ft_addbytes(bytes, buf, bytes_read);
	}
	line = ft_writeline(bytes);
	ft_bytemove(bytes);
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
	line = get_next_line(fd);
	printf("%s", line);
	i++;	
	while (*line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		i++;	
	}
	free(line);
}
