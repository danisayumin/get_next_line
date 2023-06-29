/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:53 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/15 22:17:42 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*line_break(int fd, char *buf, char *remainder);
static int	find_break_line(char *buf);
char	*get_next_line(const int fd);

static char	*line_break(int fd, char *buf, char *remainder)
{
	int		bytes;
	int		break_line;

	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		break_line = find_break_line(buf);
		if (break_line != -1)
		{
			ft_strncpy(remainder, &buf[break_line + 1], BUFFER_SIZE - break_line);
			return (buf);
		}
		
	}
	return (buf);
}

static int	find_break_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(const int fd)
{
	char		*line;
	char		*buf;
	static char		*remainder;
	size_t		len;

	line = NULL;	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	remainder = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || !remainder)
	{
		free(buf);
		free(remainder);
		return (NULL);
	}
	line = line_break(fd, buf, remainder);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);

	for (int i = 0; i < 12; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
        free(line);
	}
    close(fd);
    return 0;
}
