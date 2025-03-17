/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:19:40 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:55 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = 0;
	if (!dest && destsize == 0)
		return (ft_strlen(src));
	while (dest[i] && i < destsize)
		i++;
	length = ft_strlcpy((dest + i), src, destsize - i);
	return (length + i);
}
