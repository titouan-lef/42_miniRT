/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:06:16 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:42 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*ptr;
	size_t	size_max;

	size_max = -1;
	if (n != 0 && s > size_max / n)
		return (0);
	ptr = (void *)malloc(n * s);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n * s);
	return (ptr);
}
