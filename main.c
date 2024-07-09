/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:23:56 by badriano          #+#    #+#             */
/*   Updated: 2024/07/09 19:24:56 by badriano         ###   ########.fr       */
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
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t ft_strlen(const char *s)
{
    size_t count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

char *ft_strjoin(char *s1, const char *s2)
{
    char *result;
    size_t i, j, total_len;

    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    total_len = ft_strlen(s1) + ft_strlen(s2);
    result = (char *)malloc((total_len + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    i = 0;
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

int ft_line_len(const char *str)
{
    int i = -1;
    while (str[++i])
        if (str[i] == '\n')
            return (i);
    return (0);
}

int ft_strchr(const char *str)
{
    int i = -1;
    while (str[++i])
        if (str[i] == '\n')
            return (1);
    return (0);
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
        return (NULL);
    }
    while (chars_read[i] != '\n' && chars_read[i] != '\0')
    {
        i++;
    }
    if (chars_read[i] == '\0')
    {
        free(chars_read);
        return (NULL);
    }
    i++;
    temp = i;
    while (chars_read[i])
    {
        len++;
        i++;
    }
    i = temp;
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL);
    while (chars_read[i])
    {
        line[j] = chars_read[i];
        i++;
        j++;
    }
    line[j] = '\0';
    free(chars_read);
    return (line);
}

char *ft_new_line(char *chars_read)
{
    int i = 0;
    int len = 0;
    char *line;
    if (!chars_read)
        return (NULL);
    len = ft_line_len(chars_read);
    line = malloc(sizeof(char) * (len + 2));
    if (!line)
        return (NULL);
    while (i < len)
    {
        line[i] = chars_read[i];
        i++;
    }
    line[len] = '\n';
    line[len + 1] = '\0';
    return (line);
}

char *left_str(char *chars_read, char *buf, int fd)
{
    int bytes_read;

    while (ft_strchr(buf) != 1)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0'; // Properly null-terminate the buffer
        chars_read = ft_strjoin(chars_read, buf);
        if (bytes_read == 0)
            break;
    }
    return chars_read;
}

char *ft_get_next_line(int fd)
{
    char buf[BUFFER_SIZE + 1];
    static char *chars_read = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf[0] = '\0';
    chars_read = left_str(chars_read, buf, fd);
    if (!chars_read || chars_read[0] == '\0')
        return (NULL);
    line = ft_new_line(chars_read);
    chars_read = ft_new_left_str(chars_read);
    return (line);
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
