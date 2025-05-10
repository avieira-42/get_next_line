/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:49:43 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/10 00:48:01 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bytemove(char *buf)
{
	char	*ptr;
	ssize_t	i;

	i = 0;
	ptr = buf;
	while (buf[i] != '\n' && buf[i])
		i++;
	ptr += i;
	if (buf[i] == '\n')
		ptr++;
	i = 0;
	while (*ptr)
		buf[i++] = *(ptr++);
	buf[i] = '\0';
}

int	ft_found_newline(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
		if (line[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_addbytes(char *stash, char *buf)
{
	int		len;
	char	*line;
	char	*l_ptr;
	char	*s_ptr;

	s_ptr = stash;
	len = ft_nlen(stash) + ft_nlen(buf);
	line = (char *) malloc(sizeof(char) * (len + 1));
	if (!line)
		return (free(stash), NULL);
	l_ptr = line;
	while (s_ptr && *s_ptr)
		*(l_ptr++) = *(s_ptr++);
	while ((l_ptr - line < len))
		*(l_ptr++) = *(buf++);
	*l_ptr = '\0';
	return (free(stash), line);
}

char	*get_next_line(int fd)
{
	ssize_t			bytes_read;
	char			*line;
	static char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (!ft_found_newline(line))
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
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
}
