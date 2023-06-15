/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:53 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/13 22:17:43 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(const int fd)
{
	int	line 
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (line > 0)
	{
		line = read(fd, buf, BUFFER_SIZE);
		buf[line] = '\0';
		//coloca uma join aq e retorna a linha e o buf fazer um tratamento de erro
	}
	return ();
}