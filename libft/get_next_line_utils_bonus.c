/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:27:49 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:13:17 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrint(const char *s, char c)
{
	while (*s != c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (1);
}

char	*ft_malloc(size_t n)
{
	char	*str;
	size_t	i;
	size_t	size_max;

	size_max = -1;
	if (n > size_max)
		return (NULL);
	str = (char *)malloc(sizeof(char) * n);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
