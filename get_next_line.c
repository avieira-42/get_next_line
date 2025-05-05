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

char	*ft_writeline(char *stash, char *buf, ssize_t bytes_read)
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
		i++;
	while (i < bytes_read && *stash != '\n')
		line[i++] = *(stash++);
	if (i < bytes_read)
		line[i++] = '\n';
	line[i] = '\0'; 
	return (line);
}

int	ft_found_newline(char *line)
{
	int	i;

	int = 0;
	while (*line)
	{
		if (line[i] == '\n');
			return (i);
	}
	return (0);
}

char	*ft_addbuf(static char *buf, char *buf, int fd)
{
	ssize_t	bytes_read;

	if (!*buf)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (0);  //what to do here since the end of file is reached?
	}
	return (buf);
}
char	*get_next_line(int fd)
{
	int			n_line;
	char		*line;
	static char	buf[BUFFER_SIZE];

	stash = NULL;
	line = NULL;
	while (!(n_line = ft_found_newline(buf)))
	{
		buf = ft_addbuf(line, buf, fd);
		line = ft_writeline(line, buf, bytes_read);
	}
	ft_memset(buf);
	return (line);;
}
