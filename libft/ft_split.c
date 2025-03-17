/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:40:29 by prosset           #+#    #+#             */
/*   Updated: 2024/10/11 10:39:46 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *str, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_create_tab(char **tab, int i, int j)
{
	tab[i] = (char *) malloc((j + 1) * sizeof(char));
	if (!tab[i])
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
		return (0);
	}
	return (tab[i]);
}

static const char	*ft_fill_tab(char **tab, char const *s, int i, int j)
{
	int	n;

	n = 0;
	while (n < j)
	{
		tab[i][n] = s[0];
		s++;
		n++;
	}
	tab[i][n] = '\0';
	return (s);
}

static char const	*ft_tab(int i, char const *s, char **tab, char c)
{
	int	j;

	j = 0;
	while (s[j] == c && s[j] != '\0')
		s++;
	while (s[j] != c && s[j] != '\0')
		j++;
	tab[i] = ft_create_tab(tab, i, j);
	if (!tab[i])
		return (0);
	s = ft_fill_tab(tab, s, i, j);
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	**tab;

	if (!s)
		return (0);
	count = count_words(s, c);
	tab = (char **) malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (i < count)
	{
		s = ft_tab(i, s, tab, c);
		if (!s)
			return (0);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
