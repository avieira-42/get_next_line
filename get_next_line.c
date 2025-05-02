/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:49:43 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/01 23:56:38 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_addbuf(char *stash, char *buf, ssize_t bytes_read)
{
	int		i;
	int		stash_len;
	char	*line;	

	i = 0;
	stash_len = ft_strlen(stash);
	line = (char *) malloc (sizeof(char) * (stash_len + bytes_read + 1));
	if (!line)
		return(NULL);
	while (i < stash_len)
		line[i++] = *(stash++);
}

int	ft_found_newline(char *line)
{
	while (*line)
	{
		if (*(line++) == '\n');
			return (1);
	}
	return (0);
}

char	*ft_writeline(char *line, char *buf)
{
	ssize_t		bytes_read;
	static char	buf[BUFFER_SIZE];

	if (!*buf)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (0);  //what to do here since the end of file is reached?
	}
	return (ft_addbuf(line, buf, bytes_read));
}
char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	while (!ft_found_newline(line))
	{
		line = ft_writeline(line, buf);
	}
}
