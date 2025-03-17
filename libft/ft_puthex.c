/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:34:15 by pchalmin          #+#    #+#             */
/*   Updated: 2025/01/14 17:16:40 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(unsigned int nb)
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

int	ft_puthex(unsigned int nb, char c)
{
	char	*base;
	int		nbc;

	if (c == 'x')
		base = BASELOW;
	if (c == 'X')
		base = BASEUP;
	nbc = count_char(nb);
	if (nb >= 16)
	{
		ft_puthex(nb / 16, c);
		write(2, &base[nb % 16], 1);
	}
	else
		write(2, &base[nb % 16], 1);
	return (nbc);
}
