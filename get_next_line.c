/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:49:43 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/09 00:13:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bytemove(char *buf)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	tmp = buf;
	while (buf[i] != '\n' && buf[i])
	{
		tmp++;
		i++;
	}
	if (buf[i] == '\n')
		tmp++;
	i = 0;
	while (*tmp)
	{
		buf[i++] = *(tmp++);
	}
	buf[i] = '\0';
}

int	ft_found_newline(char *buf, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
		if (buf[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_addbytes(char *stash, char *buf)
{
	ssize_t	i;
	ssize_t	j;
	char	*line;

	i = 0;
	j = 0;
	line = (char *) malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!line)
		return (free(stash), NULL);
	while (stash && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	while (buf[j])
	{
		line[i + j] = buf[j];
		if (line[i + j] == '\n')
			break ;
		j++;
	}
	line[i + j + 1] = '\0';
	return (free(stash), line);
}

char	*get_next_line(int fd)
{
	ssize_t			bytes_read;
	char			*line;
	static char		buf[BUFFER_SIZE + 1];

	line = NULL;
	bytes_read = 0;
	while (!ft_found_newline(line, bytes_read))
	{
		if (!*buf)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_addbytes(line, buf);
		if (!line)
			return (NULL);
		ft_bytemove(buf);
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	(void)argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
}
