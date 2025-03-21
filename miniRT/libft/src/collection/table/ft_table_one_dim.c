/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_one_dim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:52:26 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/19 17:05:09 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free table.
 * @param tab Address of the table.
 */
void	ft_free_tab(void **tab)
{
	free(*tab);
	*tab = NULL;
}

/**
 * @brief Free table and its elements.
 * @param tab Address of the table.
 * @param size Size of table.
 * @param del Function to free each element in the table.
 * @warning del function mustn't be null.
 */
void	ft_free_complete_tab(void **tab, size_t size, void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		del(*tab + i);
		++i;
	}
	ft_free_tab(tab);
}
