/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:23:34 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:47 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	l;

	l = 0;
	if (n < 0)
		l++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		l++;
	}
	return (l + 1);
}

static void	ft_fillnb(char *nb, int n, int l)
{
	int	i;

	nb[l - 1] = '\0';
	--l;
	i = 0;
	if (n < 0)
	{
		nb[0] = '-';
		n = -n;
		++nb;
		--l;
	}
	while (i < l)
	{
		nb[l - i - 1] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		length;

	if (n == -2147483648)
	{
		nb = ft_strdup("-2147483648");
		return (nb);
	}
	if (n == 0)
	{
		nb = ft_strdup("0");
		return (nb);
	}
	length = ft_size(n);
	nb = malloc(sizeof(char) * length);
	if (!nb)
		return (NULL);
	ft_fillnb(nb, n, length);
	return (nb);
}
