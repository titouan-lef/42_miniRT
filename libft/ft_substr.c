/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:40 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:10:49 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!s || (size_t)start > ft_strlen(s))
	{
		ptr = ft_strdup("");
		if (!ptr)
			return (0);
		return (ptr);
	}
	if (start + len > ft_strlen(s))
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
