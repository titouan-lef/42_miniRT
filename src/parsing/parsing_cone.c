/// @todo header

#include "minirt.h"

static int	alloc_new_obj(t_list **head, t_cone *new_cone)
{
	t_list	*new_obj;
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
	{
		free (new_cone);
		return (1);
	}
	obj->data = new_cone;
	obj->type = CONE;
	new_obj = ft_lstnew(obj);
	if (!new_obj)
	{
		free (new_cone);
		free (obj);
		return (1);
	}
	ft_lstadd_back(head, new_obj);
	return (0);
}

static t_cone	*alloc_new_cone(char **tab)
{
	t_cone	*new_cone;
	int		error;

	error = 0;
	new_cone = malloc(sizeof(t_light));
	if (!new_cone)
		return (NULL);
	if (error == 0)
		error = take_position(&new_cone->position, tab[1]);
	if (error == 0)
		error = take_orientation(&new_cone->orientation, tab[2]);
	if (error == 0)
		error = take_color(&new_cone->color, tab[5]);
	if (error == 0)
		new_cone->diam = ft_todouble(tab[3], &error);
	if (error == 0)
		new_cone->height = ft_todouble(tab[4], &error);
	if (error != 0)
	{
		free (new_cone);
		return (NULL);
	}
	return (new_cone);
}

int	cone_interpreter(t_scene *scene, char **tab)
{
	t_cone	*new_cone;

	if (tab_size(tab) != 6)
		return (1);
	new_cone = alloc_new_cone(tab);
	if (!new_cone)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_cone))
		return (1);
	return (0);
}
