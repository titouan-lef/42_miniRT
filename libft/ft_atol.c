/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:26:10 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/05 08:27:49 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const	char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = ((result * 10) + (str[i] - 48));
		i++;
	}
	return (sign * result);
}
