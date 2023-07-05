/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:53 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/07/04 21:48:05 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*line_break(int fd, char *buf, char *remainder);
char	*get_next_line(const int fd);

static char	*line_break(int fd, char *buf, char *remainder)
{
	int		bytes;
	char	*temp;

	bytes = 0;
	// while (1)
	// {
	// 	bytes = read(fd, buf, BUFFER_SIZE);
	// 	if (bytes == -1)
	// 		return (NULL);
	// 	else if (bytes == 0)
	// 		break ;
	// 	buf[bytes] = '\0';
	// 	break_line = find_break_line(buf);
	// 	if (break_line != -1)
	// 	{
	// 		ft_strncpy(remainder, &buf[break_line + 1], BUFFER_SIZE - break_line);
	// 		return (buf);
	// 	}
	// }
	// return (buf);
	while (1)
	{
		
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = buf;
		buf = ft_strjoin(remainder, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buf);
}

static char	*ft_split_line(char *line)
{
	int		i;
	int		j;
	char	*rest_memorie;

	i = 0;
	j = 0;
	rest_memorie = NULL;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	i++;
	rest_memorie = malloc(i + 1);
	while (line[i])
		rest_memorie[j++] = line[i++];
	rest_memorie[j + 1] = '\0';
	// if (line[0] == '\0')
	// {
	// 	free(rest_memorie);
	// 	rest_memorie = NULL;
	// }

	line[i - j] = '\0';
	return (rest_memorie);
}

char	*get_next_line(const int fd)
{
	char			*line;
	char			*buf;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = line_break(fd, buf, remainder);
	if (!line)
		return (line);
	remainder = ft_split_line(line);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);

	for (int i = 0; i < 2; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
        free(line);
	}
    close(fd);
    return 0;
}
