/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:28:20 by badriano          #+#    #+#             */
/*   Updated: 2024/07/09 21:14:57 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
/*char buf[250];
int fd = open("my.txt", O_RDONLY);

char *get_next_line()
{
	int chars_read = read(fd, buf, BUFFER_SIZE);
	static char *str = 
}*/
size_t ft_strlen(char *s)
{
    size_t count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;
	size_t	total_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
		{
			return(NULL);
		}
		s1[0] = '\0';
	}
	
	total_len = ft_strlen(s1) + ft_strlen(s2);

	i = 0;
	result = (char *)malloc((total_len * sizeof(char)) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int ft_line_len(char *str)
{
	int i = -1;
	while(str[++i])
		if (str[i] == '\n')
			return(i);
	return(0);
}

int ft_strchr(char *str)
{
	int i = -1;
	while(str[++i])
		if (str[i] == '\n')
			return(1);
	return(0);
}

char *ft_new_left_str(char *chars_read)
{
	char *line;
	int len = 0;
	int temp = 0;
	int j = 0;
	int i = 0;

	if (!chars_read)
	{
		return(NULL);
	}
	while(chars_read[i] != '\n')
	{
		i++;
	}
	i++;
	temp = i;
	while(chars_read[i])
	{
		len++;
		i++;
	}
	i = temp;
	line = malloc(sizeof(char) * len + 1);
	while(chars_read[i])
	{
		line[j] = chars_read[i];
		i++;
		j++;
	}
	line[j] = '\0';
	//printf("leftovers: {%s}\n", line);
	free(chars_read);
	return (line);
}

char *ft_new_line(char *chars_read)
{
	int i = 0;
	int len = 0;
	char *line;
	if (!chars_read)
		return(NULL);
	len = ft_line_len(chars_read);
	line = malloc(sizeof(char) * len + 2);
	while (i < len)
	{
		line[i] = chars_read[i];
		i++;
	}
	line[len] = '\n';
	line[len + 1] = '\0';
	return(line);

}

char *left_str(char *chars_read, char* buf, int fd)
{
	int read_bytes;
	while(ft_strchr(buf) != 1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if(read_bytes == -1)
		{
			free(buf);
			return(NULL);
		}
		buf[read_bytes] = '\0';
		chars_read = ft_strjoin(chars_read, buf);
		if(read_bytes == 0)
			break;
	}
	return(chars_read);
}

char *ft_get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	if (fd < 0 || BUFFER_SIZE <= 0)
	static char  *chars_read = NULL;
	char *line;
	
	chars_read = left_str(chars_read, buf, fd);
	if (next_lines == NULL)
		return (NULL);
	line = ft_new_line(chars_read);
	chars_read = ft_new_left_str(chars_read);
	return(line);
}
	
int main(void)
{
    int fd = open("./my.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    char *line;
    while ((line = ft_get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
