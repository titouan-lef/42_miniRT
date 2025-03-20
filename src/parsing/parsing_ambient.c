/// @todo header

#include "minirt.h"

int	ambient_interpreter(t_scene *scene, char **tab)
{
	int	error;

	error = 0;
	if (tab_size(tab) != 3)
		return (1);
	scene->ambient.lr = ft_todouble(tab[1], &error);
	if (error != 0 || scene->ambient.lr < 1 || scene->ambient.lr > 0)
	{
		print_error_message(ERR_AMBIENT);
		return (1);
	}
	if (take_color(&scene->ambient.color, tab[2]))
	{
		print_error_message(ERR_AMBIENT);
		return (1);
	}
	return (0);
}
