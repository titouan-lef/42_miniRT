/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:34:17 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/19 18:17:57 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Every digit of the decimal part of the string is added to the number.
 * @return 0 if success,
 * 2 if there is a non-digit character,
 * 4 if floating point overflow.
 */
static int	ft_manage_decimal_part(double *nb, const char *nptr)
{
	double	divisor;
	int		digit;

	if (*nptr == '\0')
		return (2);
	divisor = 1.0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (2);
		divisor = divisor / 10.0;
		digit = ft_toint(*nptr);
		if (divisor == 0 && digit != 0)
			return (4);
		*nb += divisor * digit;
		++nptr;
	}
	return (0);
}

/**
 * @brief Add every digit of the string in the number.
 * @return 0 if success,
 * 1 if not a number,
 * 2 if there is a non-digit character,
 * 3 if overflow,
 * 4 if floating point overflow.
 */
static int	ft_char_to_number(double *nb, const char *nptr)
{
	int	result;

	if (*nptr == '\0' || *nptr == '.')
		return (1);
	while (*nptr != '.')
	{
		if (*nptr == '\0')
			return (0);
		if (!ft_isdigit(*nptr))
			return (2);
		*nb = *nb * 10 + ft_toint(*nptr);
		if (isinf(*nb))
			return (3);
		++nptr;
	}
	++nptr;
	result = ft_manage_decimal_part(nb, nptr);
	return (result);
}

/**
 * @brief Convert the string to a double.
 * @param nptr the string number.
 * @param status the exit status define by
 * 0 if success,
 * 1 if not a number,
 * 2 if there is a non-digit character,
 * 3 if overflow,
 * 4 if floating point overflow.
 * @return A double
 * @warning isinf() of lib math.h is used.
 */
double	ft_todouble(const char *nptr, int *status)
{
	int		is_neg;
	double	nb;

	is_neg = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			is_neg = 1;
		++nptr;
	}
	nb = 0;
	*status = ft_char_to_number(&nb, nptr);
	if (*status)
		return (nb);
	if (is_neg)
		nb = -nb;
	if (isinf(nb))
		*status = 3;
	return (nb);
}
