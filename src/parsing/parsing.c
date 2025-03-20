/// @todo header

#include "minirt.h"

void	init_scene(t_scene *scene)
{
	scene->lst_light = NULL;
	scene->lst_obj = NULL;
}

int	data_interpreter(t_scene *scene, char **tab, int id)
{
	int	error;

	error = 0;
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
	return (error);
}

int	extrac_data(char *str, t_scene *scene, int *nb_ambient, int *nb_camera)
{
	char	**tab;
	int		id;

	tab = ft_split_charset(str, "\t\n\v\f\r ");
	if (!tab)
		return (1);
	id = check_valid_id(tab[0]);
	if (id == AMBIENT)
		*nb_ambient += 1;
	if (id == CAMERA)
		;
	if (*nb_ambient > 1 || *nb_camera > 1)
		;
	if (*nb_ambient > 1 || *nb_camera > 1 || id == OBJ_ERR || data_interpreter(scene, tab, id))
	{
		ft_clean_matrix((void *)&tab);
		return (1);
	}
	ft_clean_matrix((void *)&tab);
	return (0);
}

int	read_scene(int fd, t_scene *scene)
{
	char	*str;
	int		nb_ambient;
	int		nb_camera;

	nb_ambient = 0;
	nb_camera = 0;
	str = get_next_line_one_file(fd);
	if (!str)
		return (1);
	while (str)
	{
		if (extrac_data(str, scene, &nb_ambient, &nb_camera))
		{
			free (str);
			return (1);
		}
		free(str);
		str = get_next_line_one_file(fd);
		if (!str)
			return (1);
	}
	return (0);
}

void	parsing(int argc, char **argv, t_scene *scene)
{
	int	fd;

	init_scene(scene);
	if (argc != 2 || check_files_type(argv[1]))
		exit_error_before_alloc(BAD_ARG);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error_before_alloc(OPEN_FAILED);
	if (read_scene(fd, scene))
	{
		
		close (fd);
	}
	close (fd);
}
