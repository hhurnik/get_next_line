/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:04:22 by hhurnik           #+#    #+#             */
/*   Updated: 2024/07/04 19:48:12 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *string)
{
	int		i;
	int		j;
	char	*line;

	if (!string || !string[0])
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	line = (char *)malloc(i * sizeof(char) + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = string[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_after_nl(char *string)
{
	char	*new_buffer;
	char	*newline_pos;

	newline_pos = ft_strchr(string, '\n');
	if (!newline_pos)
	{
		free(string);
		return (NULL);
	}
	new_buffer = ft_strdup(newline_pos + 1);
	free(string);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buffer;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	nbytes = 1;
	while (!(ft_strchr(string, '\n')) && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	buffer = ft_line(string);
	string = ft_after_nl(string);
	return (buffer);
}
