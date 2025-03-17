/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:49:37 by pchalmin          #+#    #+#             */
/*   Updated: 2025/01/14 17:16:01 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(size_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static int	printchar(size_t adress)
{
	char	*base;
	int		nbc;

	base = BASELOW;
	nbc = count_char(adress);
	if (adress >= 16)
	{
		printchar(adress / 16);
		write(2, &base[adress % 16], 1);
	}
	else
		write(2, &base[adress % 16], 1);
	return (nbc);
}

int	ft_putptr(void *ptr)
{
	int		i;
	size_t	adress;

	if (!ptr)
	{
		write(2, "(nil)", 5);
		return (5);
	}
	adress = (size_t)ptr;
	write(2, "0x", 2);
	i = 2;
	i += printchar(adress);
	return (i);
}
