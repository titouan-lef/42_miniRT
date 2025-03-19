/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_two_dim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:13:29 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/19 17:10:07 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the number of row in matrix.
 * @param matrix The matrix.
 */
size_t	ft_matrix_get_row(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i] != NULL)
		++i;
	return (i);
}

/**
 * @brief Free matrix.
 * @param matrix Address of the matrix.
 * @param nb_row Number of row in matrix.
 */
void	ft_free_matrix(void ***matrix, size_t nb_row)
{
	size_t	i;

	i = 0;
	while (i < nb_row)
	{
		ft_free_tab(*matrix + i);
		++i;
	}
	free(*matrix);
	*matrix = NULL;
}

/**
 * @brief Free matrix.
 * @param matrix Address of the matrix.
 * @warning matrix must null terminated.
 */
void	ft_clean_matrix(void ***matrix)
{
	size_t	i;

	i = 0;
	while ((*matrix)[i] != NULL)
	{
		ft_free_tab(*matrix + i);
		++i;
	}
	free(*matrix);
	*matrix = NULL;
}

/**
 * @brief Free matrix and its elements.
 * @param matrix Address of the matrix.
 * @param nb_row Number of row in matrix.
 * @param nb_col Number of elements in each row.
 * @param del Function to free each element in the matrix.
 * @warning del function mustn't be null.
 */
void	ft_free_complete_matrix(void ***matrix, size_t nb_row, size_t nb_col,
			void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < nb_row)
	{
		ft_free_complete_tab(*matrix + i, nb_col, del);
		++i;
	}
	free(*matrix);
	*matrix = NULL;
}

/**
 * @brief Free matrix and its elements.
 * @param matrix Address of the matrix.
 * @param nb_col Number of elements in each row.
 * @param del Function to free each element in the matrix.
 * @warning del function mustn't be null and matrix must null terminated.
 */
void	ft_clean_complete_matrix(void ***matrix, size_t nb_col,
			void (*del)(void *))
{
	size_t	i;

	i = 0;
	while ((*matrix)[i] != NULL)
	{
		ft_free_complete_tab(*matrix + i, nb_col, del);
		++i;
	}
	free(*matrix);
	*matrix = NULL;
}
