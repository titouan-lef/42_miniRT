/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:32 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/13 16:39:56 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*get_vector_value(double *value, char *str, int *error)
{
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*value = ft_todouble(str, error);
		end++;
	}
	else
		*value = ft_todouble(str, error);
	str += end;
	return (str);
}

static char	*complete_dir(double *dir, char *str)
{
	int		error;

	str = get_vector_value(dir, str, &error);
	if (error != 0 || *dir < -1 || *dir > 1)
		return (NULL);
	return (str);
}

static char	*complete_pos(double *pos, char *str)
{
	int		error;

	str = get_vector_value(pos, str, &error);
	if (error != 0)
		return (NULL);
	return (str);
}

/**
 * @brief Converts a string to a director vector.
 * @return Return 1 if the arg isn't valid or the vector aren't normalize.
 */
int	take_dir(t_vec3 *dir, char *str)
{
	double	norm;

	str = complete_dir(&dir->x, str);
	if (!str || !*str)
		return (1);
	str = complete_dir(&dir->y, str);
	if (!str || !*str)
		return (1);
	str = complete_dir(&dir->z, str);
	if (!str || *str)
		return (1);
	norm = ft_norm_vec3(dir);
	if (norm == 0)
		return (1);
	*dir = ft_scalmult_vec3(dir, 1.0 / norm);
	return (0);
}

/**
 * @brief Convert a string to a position.
 * @return Return 1 if the argument isn't valid.
 */
int	take_pos(t_vec3 *pos, char *str)
{
	str = complete_pos(&pos->x, str);
	if (!str || !*str)
		return (1);
	str = complete_pos(&pos->y, str);
	if (!str || !*str)
		return (1);
	str = complete_pos(&pos->z, str);
	if (!str || *str)
		return (1);
	return (0);
}
