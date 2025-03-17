/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:47:54 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:51 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!s1 || !s2) && n == 0)
		return (0);
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)(s1 + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
