/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:55:37 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:11:20 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_is_set(char const *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	i;
	char	*ptr;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[first] && ft_char_is_set(set, s1[first]))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_char_is_set(set, s1[last - 1]))
		last--;
	ptr = (char *)malloc(sizeof(*s1) * (last - first + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (first < last)
		ptr[i++] = s1[first++];
	ptr[i] = 0;
	return (ptr);
}
