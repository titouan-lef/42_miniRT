/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:09 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:57 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(p1 + i) == *(unsigned char *)(p2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(p1 + i) - *(unsigned char *)(p2 + i));
	return (0);
}
