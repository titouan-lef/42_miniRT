/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:26:21 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:13:19 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nextline(char *buffer)
{
	char	*nextline;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	nextline = ft_malloc(ft_strlen(buffer) - i + 1);
	if (!nextline)
		return (NULL);
	j = 0;
	while (buffer[i])
	{
		nextline[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (nextline);
}

static char	*ft_getline(char *buffer)
{
	char	*returnline;
	size_t	len;

	len = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	returnline = ft_malloc(len + 1 + (buffer[len] == '\n'));
	if (!returnline)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		returnline[len] = buffer[len];
		len++;
	}
	if (buffer[len] && buffer[len] == '\n')
		returnline[len] = '\n';
	return (returnline);
}

static char	*ft_newbuffer(char *buffer, char *tmp)
{
	char	*newbuffer;

	newbuffer = ft_strjoin(buffer, tmp);
	free(buffer);
	return (newbuffer);
}

static char	*ft_read_file(int fd, char *buffer)
{
	int		bytes;
	char	*tmp;

	if (!buffer)
		buffer = ft_malloc(1);
	if (!buffer)
		return (NULL);
	tmp = ft_malloc(BUFFER_SIZE +1);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[bytes] = 0;
		buffer = ft_newbuffer(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*returnline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	returnline = ft_getline(buffer[fd]);
	buffer[fd] = ft_nextline(buffer[fd]);
	return (returnline);
}
