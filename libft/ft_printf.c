/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:40:16 by pchalmin          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:15 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_check_arg(const char c, va_list lst)
{
	int	nbc;

	nbc = 0;
	if (!c)
		return (0);
	if (c == 'c')
		nbc = ft_putchar(va_arg(lst, int));
	else if (c == 's')
		nbc = ft_putstr(va_arg(lst, char *));
	else if (c == 'p')
		nbc = ft_putptr(va_arg(lst, void *));
	else if (c == 'd')
		nbc = ft_putnbr(va_arg(lst, int));
	else if (c == 'i')
		nbc = ft_putnbr(va_arg(lst, int));
	else if (c == 'u')
		nbc = ft_putnbr(va_arg(lst, unsigned int));
	else if (c == 'x')
		nbc = ft_puthex(va_arg(lst, unsigned int), c);
	else if (c == 'X')
		nbc = ft_puthex(va_arg(lst, unsigned int), c);
	else if (c == '%')
		nbc = ft_putchar('%');
	return (nbc);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		ncp;

	ncp = 0;
	if (!str)
		return (-1);
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ncp += ft_check_arg(*str, lst);
		}
		else
			ncp += ft_putchar(*str);
		str++;
	}
	va_end(lst);
	return (ncp);
}
