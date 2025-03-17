/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:29:57 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:52 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while ((s1[j] != '\0') && (s1[j] == s2[j]) && (s2[j] != '\0') && (j < n))
		j++;
	if (j == n)
		return (0);
	return ((unsigned char)(s1[j]) - (unsigned char)(s2[j]));
}
