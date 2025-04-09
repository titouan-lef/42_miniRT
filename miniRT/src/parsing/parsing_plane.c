/// @todo header

#include "minirt.h"

static t_plane_obj	*alloc_new_plan(char **tab)
{
	t_plane_obj	*new_pl;
	t_vec3		n;
	t_vec3		p;

	new_pl = malloc(sizeof(t_plane_obj));
	if (!new_pl)
		return (NULL);
	if (take_pos(&p, tab[1])
		|| take_dir(&n, tab[2])
		|| take_color(&new_pl->color, tab[3]))
	{
		print_error_message(ERR_PLANE);
		free (new_pl);
		return (NULL);
	}
	new_pl->pl = ft_create_plane(&n, &p);
	return (new_pl);
}

int	plan_interpreter(t_scene *scene, char **tab)
{
	t_plane_obj	*new_pl;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	new_pl = alloc_new_plan(tab);
	if (!new_pl)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_pl, PLANE))
	{
		free(new_pl);
		return (1);
	}
	return (0);
}
