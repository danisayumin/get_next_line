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

static char	*line_break(int fd, char *rest_line, char *buf)
{
	int		bytes;
	char	*temp;
	char	*storage;

	bytes = 1;
	while (1)
	{
		bytes = read(fd, rest_line, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(storage, '\n'))
			break ;
	}
}

char	*get_next_line(const int fd)
{
	char		*line;
	char		*buf;
	static char	*rest_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = line_break(fd, rest_line, buf);
	free(buf);
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
