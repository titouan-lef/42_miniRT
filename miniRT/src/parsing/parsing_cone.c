/// @todo header

#include "minirt.h"

static t_cone_obj	*alloc_new_cone(char **tab)
{
	t_cone_obj	*new_co;

	new_co = malloc(sizeof(t_cone_obj));
	if (!new_co)
		return (NULL);
	if (take_pos(&new_co->co.pos, tab[1])
		|| take_dir(&new_co->co.dir, tab[2])
		|| take_dimension(&new_co->co.r, tab[3])
		|| take_dimension(&new_co->co.h, tab[4])
		|| take_color(&new_co->color, tab[5]))
	{
		print_error_message(ERR_CONE);
		free (new_co);
		return (NULL);
	}
	new_co->co.r *= 0.5;
	return (new_co);
}

int	cone_interpreter(t_scene *scene, char **tab)
{
	t_cone_obj	*new_co;

	if (ft_matrix_get_row((void **)tab) != 6)
		return (1);
	new_co = alloc_new_cone(tab);
	if (!new_co)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_co, CONE))
	{
		free(new_co);
		return (1);
	}
	return (0);
}
