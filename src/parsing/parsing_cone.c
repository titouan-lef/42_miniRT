/// @todo header

#include "minirt.h"

static t_cone	*alloc_new_cone(char **tab)
{
	t_cone	*new_cone;

	new_cone = malloc(sizeof(t_cone));
	if (!new_cone)
		return (NULL);
	if (take_position(&new_cone->position, tab[1])
		|| take_orientation(&new_cone->orientation, tab[2])
		|| take_dimension(&new_cone->diam, tab[3])
		|| take_dimension(&new_cone->height, tab[4])
		|| take_color(&new_cone->color, tab[5]))
	{
		print_error_message(ERR_CONE);
		free (new_cone);
		return (NULL);
	}
	return (new_cone);
}

int	cone_interpreter(t_scene *scene, char **tab)
{
	t_cone	*new_cone;

	if (ft_matrix_get_row((void **)tab) != 6)
		return (1);
	new_cone = alloc_new_cone(tab);
	if (!new_cone)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_cone, CONE))
	{
		free(new_cone);
		return (1);
	}
	return (0);
}
