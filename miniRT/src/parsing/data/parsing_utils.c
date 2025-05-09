/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:25 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:46:26 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Init all pointeur of the struct at NULL.
 */
void	init_scene(t_scene *scene, t_lst_parse *lst_parse)
{
	scene->tab_obj = NULL;
	scene->tab_l = NULL;
	lst_parse->lst_obj = NULL;
	lst_parse->lst_l = NULL;
}

/**
 * @brief Convert a string in dimension in double.
 * @return 1 if the value is negativ or egal 0.
 */
int	take_dimension(double *dimension, char *str)
{
	int	error;

	*dimension = ft_todouble(str, &error);
	return (error || *dimension <= 0);
}

/**
 * @brief Check if the files types is valid.
 * @return 1 if the files types is invalid, 0 else.
 */
int	check_files_type(char *str, char *type)
{
	size_t	size;
	size_t	size_type;
	size_t	i;

	size = ft_strlen(str);
	size_type = ft_strlen(type);
	if (size <= size_type)
		return (1);
	i = 1;
	while (i < size_type)
	{
		if (str[size - i] != type[size_type - i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Check the first line of tab for look identifer
 * @param str Id of string.
 * @return Nb in fonction of id detected.
 * @warning 7 is for a cone for bonus.
 */
int	check_valid_id(char *str, int single_entity[2])
{
	if (!ft_strcmp(str, "C"))
	{
		single_entity[0] += 1;
		return (CAMERA);
	}
	if (!ft_strcmp(str, "A"))
	{
		single_entity[1] += 1;
		return (AMBIENT);
	}
	if (!ft_strcmp(str, "L"))
		return (LIGHT);
	if (!ft_strcmp(str, "sp"))
		return (SPHERE);
	if (!ft_strcmp(str, "pl"))
		return (PLANE);
	if (!ft_strcmp(str, "cy"))
		return (CYLINDER);
	if (CONE_ACTIVE == 1 && !ft_strcmp(str, "co"))
		return (CONE);
	print_error_message(ERR_ID);
	return (OBJ_ERR);
}

/**
 * @brief Init local coordinates for translation and rotation of entities.
 * @param dir Forward direction.
 * @param right Right direction.
 * @param up Up direction.
 */
void	init_local_coordinates(const t_vec3 *dir, t_vec3 *right, t_vec3 *up)
{
	t_vec3	up_wish;

	up_wish = ft_create_vec3(0, 1, 0);
	if (dir->x == 0 && dir->z == 0)
	{
		if (dir->y == 1)
			up_wish = ft_create_vec3(0, 0, -1);
		else if (dir->y == -1)
			up_wish = ft_create_vec3(0, 0, 1);
	}
	*right = ft_cross_vec3(&up_wish, dir);
	*up = ft_cross_vec3(dir, right);
}
