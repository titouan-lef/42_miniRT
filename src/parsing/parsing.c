/// @todo header

#include "minirt.h"

int	check_scene_composition(t_scene *scene, int nb_ambient, int nb_camera)
{
	if (nb_camera != 1)
	{
		print_error_message(ERR_NB_CAM);
		return (1);
	}
	if (nb_ambient != 1)
	{
		print_error_message(ERR_NB_AMB);
		return (1);
	}
	if (scene->lst_light == NULL)
	{
		print_error_message(ERR_NO_LIGHT);
		return (1);
	}
	if (scene->lst_obj == NULL)
	{
		print_error_message(ERR_NO_OBJ);
		return (1);
	}
	return (0);
}

static int	data_interpreter(t_scene *scene, char **tab, int id)
{
	int	error;

	if (id == AMBIENT)
		error = ambient_interpreter(scene, tab);
	else if (id == CAMERA)
		error = camera_interpreter(scene, tab);
	else if (id == LIGHT)
		error = light_interpreter(scene, tab);
	else if (id == SPHERE)
		error = sphere_interpreter(scene, tab);
	else if (id == PLAN)
		error = plan_interpreter(scene, tab);
	else if (id == CYLINDER)
		error = cylinder_interpreter(scene, tab);
	else if (id == CONE)
		error = cone_interpreter(scene, tab);
	else
		error = 1;
	return (error);
}

static int	extrac_data(char *line, t_scene *scene, int *ambient, int *camera)
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
	id = check_valid_id(tab[0], ambient, camera);
	if (id == OBJ_ERR || data_interpreter(scene, tab, id))
	{
		ft_clean_matrix((void *)&tab);
		return (1);
	}
	ft_clean_matrix((void *)&tab);
	return (0);
}

static int	read_scene(int fd, t_scene *scene)
{
	char	*str;
	int		nb_ambient;
	int		nb_camera;

	nb_ambient = 0;
	nb_camera = 0;
	str = get_next_line_one_file(fd);
	while (str)
	{
		if (extrac_data(str, scene, &nb_ambient, &nb_camera))
		{
			free (str);
			return (1);
		}
		free(str);
		str = get_next_line_one_file(fd);
	}
	if (check_scene_composition(scene, nb_ambient, nb_camera))
		return (1);
	return (0);
}

int	parsing(int argc, char **argv, t_scene *scene)
{
	int	fd;

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
	init_scene(scene);
	if (read_scene(fd, scene))
	{
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}
