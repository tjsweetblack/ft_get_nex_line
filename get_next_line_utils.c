/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:38:36 by badriano          #+#    #+#             */
/*   Updated: 2024/06/14 14:44:05 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *next_lines, char *temp)
{
	char	*dest;
	size_t	next_lines_len;
	size_t	temp_len;
	int		count;

	if (next_lines == NULL)
	{
		next_lines = malloc(1 * sizeof(char));
		next_lines[0] = '\0';
	}
	next_lines_len = ft_strlen(next_lines);
	temp_len = ft_strlen(temp);
	dest = malloc((next_lines_len + temp_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	count = -1;
	while (next_lines[++count] != '\0')
		dest[count] = next_lines[count];
	count = -1;
	while (temp[++count] != '\0')
		dest[count + next_lines_len] = temp[count];
	dest[count + next_lines_len] = '\0';
	free(next_lines);
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int		count;

	if (s == NULL)
		return (NULL);
	count = -1;
	while (s[++count] != '\0')
		if (s[count] == (char)c)
			return (&s[count]);
	if ((char)c == '\0')
		return (&s[count]);
	return (NULL);
}
