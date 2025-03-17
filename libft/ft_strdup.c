/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:56:16 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:57 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	while (j < i)
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
