/// @todo header

#include "minirt.h"

int	ambient_interpreter(t_scene *scene, char **tab)
{
	int	error;

	error = 0;
	if (tab_size(tab) != 3)
		return (1);
	scene->ambient.lr = atob(tab[1]);
	if (scene->ambient.lr < 1 || scene->ambient.lr > 0)
		return (1);
	if (error != 0)
		return (1);
	if (take_color(&scene->ambient.color, tab[2]))
		return (1);
	return (0);
}
