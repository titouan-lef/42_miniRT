/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:57:23 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:11:02 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (i + 1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long nb)
{
	int	ret;

	ret = 0;
	ret = count_char(nb);
	if (nb < 0)
	{
		ft_putchar(45);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
	return (ret);
}
