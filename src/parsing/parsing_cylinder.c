/// @todo header

#include "minirt.h"

static int	alloc_new_obj(t_list **head, t_cylinder *new_cylinder)
{
	t_list	*new_obj;
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
	{
		free (new_cylinder);
		return (1);
	}
	obj->data = new_cylinder;
	obj->type = CYLINDER;
	new_obj = ft_lstnew(obj);
	if (!new_obj)
	{
		free (new_cylinder);
		free (obj);
		return (1);
	}
	ft_lstadd_back(head, new_obj);
	return (0);
}

static t_cylinder	*alloc_new_cylinder(char **tab)
{
	t_cylinder	*new_cylinder;
	int			error;

	new_cylinder = malloc(sizeof(t_light));
	error = 0;
	if (!new_cylinder)
		return (NULL);
	if (take_position(&new_cylinder->position, tab[1]))
	{
		free(new_cylinder);
		return (NULL);
	}
	if (take_orientation(&new_cylinder->orientation, tab[2]))
	{
		free (new_cylinder);
		return (NULL);
	}
	new_cylinder->diam = ft_todouble(tab[3], &error);
	if (error != 0)
	{
		free (new_cylinder);
		return (NULL);
	}
	new_cylinder->height = ft_todouble(tab[4], &error);
	if (error != 0)
	{
		free (new_cylinder);
		return (NULL);
	}
	if (take_color(&new_cylinder->color, tab[5]))
	{
		free (new_cylinder);
		return (NULL);
	}
	return (new_cylinder);
}

int	cylinder_interpreter(t_scene *scene, char **tab)
{
	t_cylinder	*new_cylinder;

	if (tab_size(tab) != 6)
		return (1);
	new_cylinder = alloc_new_cylinder(tab);
	if (!new_cylinder)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_cylinder))
		return (1);
	return (0);
}
