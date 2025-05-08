/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:26:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/07 15:02:09 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_bytes_init(void);
void	ft_bytemove(char *bytes);
char	*ft_writeline(char *stash);
char	*ft_addbytes(char *stash, char *buf, ssize_t bytes_read);
char	*get_next_line(int fd);

#endif
