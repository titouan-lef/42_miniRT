/// @todo header

#include "minirt.h"

static t_plan	*alloc_new_plan(char **tab)
{
	t_plan	*new_plan;

	new_plan = malloc(sizeof(t_plan));
	if (!new_plan)
		return (NULL);
	if (take_position(&new_plan->position, tab[1])
		|| take_orientation(&new_plan->orientation, tab[2])
		|| take_color(&new_plan->color, tab[3]))
	{
		print_error_message(ERR_PLANE);
		free (new_plan);
		return (NULL);
	}
	return (new_plan);
}

int	plan_interpreter(t_scene *scene, char **tab)
{
	t_plan	*new_plan;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	new_plan = alloc_new_plan(tab);
	if (!new_plan)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_plan, PLAN))
	{
		free(new_plan);
		return (1);
	}
	return (0);
}
