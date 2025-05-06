/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:49:43 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/06 14:00:39 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bufmove(char *buf, ssize_t bytes_read)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	tmp = buf;
	while (buf[i] != '\n')
	{
		tmp++;
		i++;
	}
	i = 0;;
	tmp++;
	while (*tmp)
	{
		buf[i++] = *(tmp++);
	}
	buf[i] = '\0';
}

char	*ft_writeline(char *stash)
{
	int		i;
	int		stash_len;
	char	*line;	

	i = 0;
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

char	*ft_addbuf(char *stash, char *buf, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t j;
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

char	*ft_resetstash(void)
{
	char	*bytes;

	bytes = (char *) malloc(sizeof(char) * 1);
	if (!bytes)
		return (NULL);
	bytes[0] = '\0';
	return (bytes);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*bytes;
	char		*line;
	static char	buf[BUFFER_SIZE];

	line = NULL;
	bytes_read = 0;
	bytes = ft_resetstash();
	if (*buf)
		bytes = ft_addbuf(bytes, buf, BUFFER_SIZE);
	while (!ft_found_newline(buf, bytes_read))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (0);  //what to do here since the end of file is reached?
		bytes = ft_addbuf(bytes, buf, bytes_read);
	}
	ft_bufmove(buf, bytes_read);
	line = ft_writeline(bytes);
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
	while (i < 20)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;	
	}
	free(line);
}
