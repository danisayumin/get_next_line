/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:53 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/07/08 23:44:18 by dsayumi-         ###   ########.fr       */
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
		temp = remainder;
		remainder = ft_strjoin(remainder, buf);
		if (ft_strchr(remainder, '\n'))
			break ;
	}
	return (remainder);
}

static char	*ft_split_line(char *line)
{
	int		i;
	int		j;
	char	*rest_memory;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	while (line[i] == '\0')
		return (NULL);
	rest_memory = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest_memory == '\0')
	{
		free(rest_memory);
		rest_memory = NULL;
	}
	line[i + 1] = '\0';
	return (rest_memory);
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
	if (line == NULL || !remainder)
		return (line);	
	remainder = ft_split_line(line);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);

// 	for (int i = 0; i < 42; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
//         free(line);
// 	}
//     close(fd);
//     return 0;
// }
