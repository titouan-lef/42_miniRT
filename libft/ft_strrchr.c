/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:51:35 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:50 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (*(str + i) == (unsigned char)c)
			return ((char *)(str + i));
		i--;
	}
	if (!c)
		return ((char *)str);
	return (0);
}
