/// @todo header

#include "minirt.h"

static t_sphere	*alloc_new_sphere(char **tab)
{
	t_sphere	*new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (NULL);
	if (take_position(&new_sphere->position, tab[1])
		|| take_dimension(&new_sphere->diam, tab[2])
		|| take_color(&new_sphere->color, tab[3]))
	{
		print_error_message(ERR_SPHERE);
		free(new_sphere);
		return (NULL);
	}
	return (new_sphere);
}

int	sphere_interpreter(t_scene *scene, char **tab)
{
	t_sphere	*new_sphere;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	new_sphere = alloc_new_sphere(tab);
	if (!new_sphere)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_sphere, SPHERE))
	{
		free(new_sphere);
		return (1);
	}
	return (0);
}
