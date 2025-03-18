#include "minirt.h"

void	init_scene(t_scene *scene)
{
	scene->lst_light = NULL;
	scene->lst_object = NULL;
}
int	check_valid_id(char *str)
{
	if (!ft_strcmp(str, "L"))
		return (1);
	else if (!ft_strcmp(str, "A"))
		return (2);
	else if (!ft_strcmp(str, "C"))
		return (3);
	else if (!ft_strcmp(str, "sp"))
		return (4);
	else if (!ft_strcmp(str, "pl"))
		return (5);
	else if (!ft_strcmp(str, "cy"))
		return (6);
	else if (!ft_strcmp(str, "co"))
		return (7);
	return (0);
}

int	extrac_data(char *str, int fd, t_scene *scene)
{
	char	**tab;
	int		id;

	tab = ft_split_charset(str, "\t\n\v\f\r ");
	if (!tab)
		return (1);
	id = check_valid_id(tab[0]);
	if (id == 0)
	{
		free_tab(tab);
		return (1);
	}
	if (data_fill(scene, tab))
		return (1);
	free_tab(tab);
	return (0);
}

int	read_scene(int fd, t_scene *scene)
{
	char *str;

	str = get_next_line_one_file(fd);
	if (!str)
		return (1);
	while (str)
	{
		if (extrac_data(str, fd, scene))
			return (1);
		free(str);
		str = get_next_line_one_file(fd);
		if (!str)
			return (1);
	}
	return (0);
}

void	parsing(int argc, char ** argv, t_scene *scene)
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