/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:22:17 by jesusoncrac       #+#    #+#             */
/*   Updated: 2025/05/10 01:11:58 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_removeline(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = line;
	while (line[i] != '\n' && line[i])
		i++;
	ptr += i;
	if (line[i] == '\n')
		ptr++;
	i = 0;
	while (*ptr)
		line[i++] = *(ptr++);
	line[i] = '\0';
}

char	*ft_writeline(char *line, char *buf)
{
	int		len;
	char	*new_line;
	char	*l_ptr;
	char	*nl_ptr;

	l_ptr = line;
	len = ft_nlen(line) + ft_nlen(buf);
	new_line = (char *) malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (free(line), NULL);
	nl_ptr = new_line;
	while (l_ptr && *l_ptr)
		*(nl_ptr++) = *(l_ptr++);
	while (nl_ptr - new_line < len)
		*(nl_ptr++) = *(buf++);
	*nl_ptr = '\0';
	return (free(line), new_line);
}

int	ft_found_newline(char *line)
{
	while (line && *line)
		if (*(line++) == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t			bytes_read;
	char			*line;
	static char		buf[1024][BUFFER_SIZE + 1];

	line = NULL;
	while (!ft_found_newline(line))
	{
		if (!(*(buf[fd])))
		{
			bytes_read = read(fd, buf[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_writeline(line, buf[fd]);
		if (!line)
			return (NULL);
		ft_removeline(buf[fd]);
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void) argc;
	int	fd1;
	int	fd2;
	char	*line;

	fd1 = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	fd2 = open(argv[2], O_RDONLY);
	while ((line = get_next_line(fd2)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
}
