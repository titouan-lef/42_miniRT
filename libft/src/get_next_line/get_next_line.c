/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:16:28 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/16 18:15:15 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Goal: Add buffer line or subline at 'line'.
*
* Return: if 'line' isn't a complete line return len of 'line',
* else return 0 (complete line or error).
*/
static size_t	update_line(char **line, size_t len, char *buf, size_t buf_len)
{
	size_t	len_add;
	char	*old_line;

	len_add = 1;
	while (len_add < buf_len && buf[len_add - 1] != '\n')
		++len_add;
	old_line = *line;
	*line = ft_strnjoin(*line, len, buf, len_add);
	free(old_line);
	if (!*line || (len_add == buf_len && buf[len_add - 1] == '\n'))
	{
		buf[0] = '\0';
		return (0);
	}
	len += len_add;
	ft_memcpy(buf, buf + len_add, buf_len - len_add);
	buf[buf_len - len_add] = '\0';
	if ((*line)[len - 1] == '\n')
		return (0);
	return (len);
}

static char	*read_next_line(int fd, char *buffer, char *line, size_t len)
{
	ssize_t	buffer_len;

	buffer_len = read(fd, buffer, BUFFER_SIZE);
	while (buffer_len > 0)
	{
		len = update_line(&line, len, buffer, (size_t)buffer_len);
		if (len == 0)
			return (line);
		buffer_len = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[0] = '\0';
	if (buffer_len < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line_one_file(int fd)
{
	static char	buffer[BUFFER_SIZE] = "\0";
	size_t		buffer_len;
	char		*line;
	size_t		len;

	if (fd < 0)
		return (NULL);
	line = NULL;
	len = 0;
	if (buffer[0] != '\0')
	{
		buffer_len = ft_strlen(buffer);
		len = update_line(&line, len, buffer, buffer_len);
		if (len == 0)
			return (line);
	}
	line = read_next_line(fd, buffer, line, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE];
	size_t		buffer_len;
	char		*line;
	size_t		len;

	if (fd < 0 || fd >= 4096)
		return (NULL);
	line = NULL;
	len = 0;
	if (buffer[fd][0] != '\0')
	{
		buffer_len = ft_strlen(buffer[fd]);
		len = update_line(&line, len, buffer[fd], buffer_len);
		if (len == 0)
			return (line);
	}
	line = read_next_line(fd, buffer[fd], line, len);
	return (line);
}
