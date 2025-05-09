/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:09 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:46:10 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Checks the presence of all the elements needed
 * to create a valid scene.
 * @return 1 if one of the elements is missing or
 * there is more than one ambient or camera.
 */
static int	check_scene_composition(t_lst_parse *lst_parse,
	int single_entity[2])
{
	if (single_entity[0] != 1)
	{
		print_error_message(ERR_NB_CAM);
		return (1);
	}
	if (single_entity[1] != 1)
	{
		print_error_message(ERR_NB_AMB);
		return (1);
	}
	if (lst_parse->lst_l == NULL || ft_lstsize(lst_parse->lst_l) > MAX_LIGHT)
	{
		print_error_message(ERR_NO_LIGHT);
		return (1);
	}
	if (lst_parse->lst_obj == NULL)
	{
		print_error_message(ERR_NO_OBJ);
		return (1);
	}
	return (0);
}

/**
 * @brief Selects the right interpreter based on id.
 * @return 1 if the ID isn't valid or the data arn't valid.
 */
static int	data_interpreter(t_scene *scene, t_lst_parse *lst_parse,
	char **tab, int id)
{
	int	error;

	if (id == AMBIENT)
		error = ambient_interpreter(scene, tab);
	else if (id == CAMERA)
		error = camera_interpreter(scene, tab);
	else if (id == LIGHT)
		error = light_interpreter(&lst_parse->lst_l, tab);
	else if (id == SPHERE)
		error = sphere_interpreter(&lst_parse->lst_obj, tab);
	else if (id == PLANE)
		error = plan_interpreter(&lst_parse->lst_obj, tab);
	else if (id == CYLINDER)
		error = cylinder_interpreter(&lst_parse->lst_obj, tab);
	else if (id == CONE)
		error = cone_interpreter(&lst_parse->lst_obj, tab);
	else
		error = 1;
	return (error);
}

/**
 * @brief Split the line on the white space and interprets the tab.
 * @return 1 if we have a probleme with allocation or file or data are invalid.
 */
static int	extrac_data(char *line, t_scene *scene, t_lst_parse *lst_parse,
	int single_entity[2])
{
	char	**tab;
	int		id;

	tab = ft_split_charset(line, "\t\n\v\f\r ");
	if (!tab)
		return (1);
	if (tab[0] == NULL)
	{
		ft_clean_matrix((void *)&tab);
		return (0);
	}
	id = check_valid_id(tab[0], single_entity);
	if (id == OBJ_ERR || data_interpreter(scene, lst_parse, tab, id))
	{
		clear_lst_parse(&lst_parse, free);
		ft_clean_matrix((void *)&tab);
		return (1);
	}
	ft_clean_matrix((void *)&tab);
	return (0);
}

/**
 * @brief Reads the file line by line, passing it as an argument.
 * @return 1 if we have a probleme with allocation or file
 * or data are invalid. And write the error massage depending on the error.
 */
static int	read_scene(int fd, t_scene *scene, t_lst_parse *lst_parse)
{
	char	*str;
	int		single_entity[2];

	single_entity[0] = 0;
	single_entity[1] = 0;
	str = get_next_line_one_file(fd);
	while (str)
	{
		if (extrac_data(str, scene, lst_parse, single_entity))
		{
			free(str);
			return (1);
		}
		free(str);
		str = get_next_line_one_file(fd);
	}
	if (check_scene_composition(lst_parse, single_entity))
	{
		clear_lst_parse(&lst_parse, free);
		return (1);
	}
	if (lst_parse_to_tab(scene, lst_parse))
		return (1);
	return (0);
}

/**
 * @brief Init, interprets and check all data in the scene.
 * the file scene was pass in argument.
 * @param argv Absolute path for the file.rt .
 * @param argc	Number of argument.
 * @param scene	Struct contain all data for execution.
 * @return 1 if we have a probleme with allocation or file
 * or data are invalid. And write the error massage depending on the error.
 */
int	parsing(int argc, char **argv, t_scene *scene)
{
	t_lst_parse	lst_parse;
	int			fd;

	init_scene(scene, &lst_parse);
	if (argc != 2 || check_files_type(argv[1], ".rt"))
	{
		print_error_message(ERR_ARG);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error_message(ERR_OPEN);
		return (1);
	}
	if (read_scene(fd, scene, &lst_parse))
	{
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}
