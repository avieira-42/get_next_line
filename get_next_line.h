/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:26:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/11 11:20:54 by jesusoncrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen(char *str);
int		ft_found_newline(char *line);
int		ft_nlen(char *str);
char	*get_next_line(int fd);
char	*ft_writeline(char *line, char *buf);
void	ft_removeline(char *buf);

#endif
