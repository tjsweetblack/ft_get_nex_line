/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:05:20 by badriano          #+#    #+#             */
/*   Updated: 2024/05/23 00:05:07 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "unistd.h"
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
