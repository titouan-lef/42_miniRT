/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:38:51 by pchalmin          #+#    #+#             */
/*   Updated: 2025/01/28 12:36:14 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[length] = 0;
	return (str);
}
