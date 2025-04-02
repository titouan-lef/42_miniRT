/// @todo header

#include "minirt.h"

static t_sphere_obj	*alloc_new_sphere(char **tab)
{
	t_sphere_obj	*new_sp;

	new_sp = malloc(sizeof(t_sphere_obj));
	if (!new_sp)
		return (NULL);
	if (take_pos(&new_sp->sp.pos, tab[1])
		|| take_dimension(&new_sp->sp.r, tab[2])
		|| take_color(&new_sp->color, tab[3]))
	{
		print_error_message(ERR_SPHERE);
		free(new_sp);
		return (NULL);
	}
	new_sp->sp.r *= 0.5;
	return (new_sp);
}

int	sphere_interpreter(t_scene *scene, char **tab)
{
	t_sphere_obj	*new_sp;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	new_sp = alloc_new_sphere(tab);
	if (!new_sp)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_sp, SPHERE))
	{
		free(new_sp);
		return (1);
	}
	return (0);
}
