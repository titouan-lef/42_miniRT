/// @todo header

#include "minirt.h"

static int	alloc_new_obj(t_list **head, t_plan *new_plan)
{
	t_list	*new_obj;
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
	{
		free (new_plan);
		return (1);
	}
	obj->data = new_plan;
	obj->type = PLAN;
	new_obj = ft_lstnew(obj);
	if (!new_obj)
	{
		free (new_plan);
		free (obj);
		return (1);
	}
	ft_lstadd_back(head, new_obj);
	return (0);
}

static t_plan	*alloc_new_plan(char **tab)
{
	t_plan	*new_plan;
	int		error;

	error = 0;
	new_plan = malloc(sizeof(t_light));
	if (!new_plan)
		return (NULL);
	if (error == 0)
		error = take_position(&new_plan->position, tab[1]);
	if (error == 0)
		error = take_orientation(&new_plan->orientation, tab[2]);
	if (error == 0)
		error = take_color(&new_plan->color, tab[3]);
	if (error != 0)
	{
		free (new_plan);
		return (NULL);
	}
	return (new_plan);
}

int	plan_interpreter(t_scene *scene, char **tab)
{
	t_plan	*new_plan;

	if (tab_size(tab) != 4)
		return (1);
	new_plan = alloc_new_plan(tab);
	if (!new_plan)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_plan))
		return (1);
	return (0);
}
