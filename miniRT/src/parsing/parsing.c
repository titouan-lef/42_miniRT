/// @todo header

#include "minirt.h"

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
	if (lst_parse->lst_l == NULL)
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
		ft_clean_matrix((void *)&tab);
		return (1);
	}
	ft_clean_matrix((void *)&tab);
	return (0);
}

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
			free (str);
			return (1);
		}
		free(str);
		str = get_next_line_one_file(fd);
	}
	if (check_scene_composition(lst_parse, single_entity))
		return (1);
	lst_parse_to_tab(scene, lst_parse);
	return (0);
}

int	parsing(int argc, char **argv, t_scene *scene)
{
	t_lst_parse	lst_parse;
	int			fd;

	init_scene(scene, &lst_parse);
	if (argc != 2 || check_files_type(argv[1]))
	{
		print_error_message(ERR_ARG);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error_message(ERR_OPEN_FAILED);
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
