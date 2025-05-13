/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:20 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/13 12:23:01 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*complete_colors(double *color, char *str)
{
	int		error;
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*color = ft_to_number(str, &error, 255);
		end++;
	}
	else
		*color = ft_to_number(str, &error, 255);
	if (error != 0 || *color < 0)
		return (NULL);
	*color /= 255.0;
	str += end;
	return (str);
}

/**
 * @brief Convert a string to a color RGB.
 * @return Return 1 if the arg isn't valid or value is not between 0 and 255.
 */
int	take_color(t_vec3 *colors, char *str)
{
	str = complete_colors(&colors->x, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->y, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->z, str);
	if (!str || *str)
		return (1);
	return (0);
}

/**
 * @brief Enables the checkerboard option based on the number of separations.
 * @return Return 1 if the arg isn't valid or
 * the split checkerboard are to hight.
 */
static int	active_checkboard(int *status, char *str)
{
	int	error;

	*status = ft_to_number(str, &error, 5);
	if (error != 0 || *status < 0)
	{
		print_error_message(ERR_CHECKERBOARD);
		return (1);
	}
	return (0);
}

/**
 * @brief Enables the  option based on the number of separations.
 * @return Return 1 if the file type are not a .png,
 * the file is missing or does not have permissions,
 * the allocation failed.
 */
static int	take_texture_files(char **name, char *str)
{
	int	fd;

	if (!ft_strcmp(str, "NULL"))
		return (0);
	if (check_files_type(str, ".png"))
	{
		print_error_message(ERR_TYPE_FILE);
		return (1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		print_error_message(ERR_OPEN);
		return (1);
	}
	close (fd);
	*name = ft_strdup(str);
	if (!name)
	{
		print_error_message(ERR_MALLOC);
		return (1);
	}
	return (0);
}

/**
 * @brief Allows you to initialize the entire pattern of the object.
 * (color, texture, bump map and checkerboard).
 * @return Return 1 if an argument was wrong or an allocation failed.
 */
int	take_pattern(t_pattern *pattern, char **tab)
{
	if (take_color(&pattern->color, tab[0]))
	{
		print_error_message(ERR_COLOR);
		return (1);
	}
	if (PATTERN_ENABLE == 1)
	{
		if (active_checkboard(&pattern->checkerboard, tab[1])
			|| take_texture_files(&pattern->texture.name, tab[2])
			|| take_texture_files(&pattern->bump.name, tab[3]))
		{
			return (1);
		}
	}
	return (0);
}
