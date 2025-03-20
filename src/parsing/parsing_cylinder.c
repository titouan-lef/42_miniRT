/// @todo header

#include "minirt.h"

static t_cylinder	*alloc_new_cylinder(char **tab)
{
	t_cylinder	*new_cylinder;

	new_cylinder = malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (NULL);
	if (take_position(&new_cylinder->position, tab[1])
		|| take_orientation(&new_cylinder->orientation, tab[2])
		|| take_dimension(&new_cylinder->diam, tab[3])
		|| take_dimension(&new_cylinder->height, tab[4])
		|| take_color(&new_cylinder->color, tab[5]))
	{
		print_error_message(ERR_CYLINDER);
		free(new_cylinder);
		return (NULL);
	}
	return (new_cylinder);
}

int	cylinder_interpreter(t_scene *scene, char **tab)
{
	t_cylinder	*new_cylinder;

	if (ft_matrix_get_row((void **)tab) != 6)
		return (1);
	new_cylinder = alloc_new_cylinder(tab);
	if (!new_cylinder)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_cylinder, CYLINDER))
	{
		free(new_cylinder);
		return (1);
	}
	return (0);
}
