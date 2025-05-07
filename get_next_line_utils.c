/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:11:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/05/07 14:55:18 by jesusoncrac      ###   ########.fr       */
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

char	*ft_bytes_init(void)
{
	char	*bytes;

	bytes = (char *) malloc(sizeof(char));
	if (!bytes)
		return (NULL);
	*bytes = '\0';
	return (bytes);
}
