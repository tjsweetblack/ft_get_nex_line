/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:20 by badriano          #+#    #+#             */
/*   Updated: 2024/05/23 00:04:51 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	ret[7000000];
	int		i;
	int		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	read_size = read(fd, &buffer, 1);
	while (read_size > 0)
	{
		ret[i++] = buffer;
		if (buffer == '\n')
			break ;
		read_size = read(fd, &buffer, 1);
	}
	if (read_size <= 0 && i == 0)
		return (NULL);
	ret[i] = '\0';
	return (ft_strdup(ret));
}
