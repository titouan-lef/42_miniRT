/// @todo header

#include "minirt.h"

static int	alloc_new_obj(t_list **head, t_sphere *new_sphere)
{
	t_list	*new_obj;
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
	{
		free (new_sphere);
		return (1);
	}
	obj->data = new_sphere;
	obj->type = SPHERE;
	new_obj = ft_lstnew(obj);
	if (!new_obj)
	{
		free (new_sphere);
		free (obj);
		return (1);
	}
	ft_lstadd_back(head, new_obj);
	return (0);
}

static t_sphere	*alloc_new_sphere(char **tab)
{
	t_sphere	*new_sphere;
	int			error;

	error = 0;
	new_sphere = malloc(sizeof(t_light));
	if (!new_sphere)
		return (NULL);
	if (error == 0)
		error = take_position(&new_sphere->position, tab[1]);
	if (error == 0)
		new_sphere->diam = ft_todouble(tab[2], &error);
	if (error == 0)
		error = take_color(&new_sphere->color, tab[3]);
	if (error != 0)
	{
		free (new_sphere);
		return (NULL);
	}
	return (new_sphere);
}

int	sphere_interpreter(t_scene *scene, char **tab)
{
	t_sphere	*new_sphere;

	if (tab_size(tab) != 4)
		return (1);
	new_sphere = alloc_new_sphere(tab);
	if (!new_sphere)
		return (1);
	if (alloc_new_obj(&scene->lst_obj, new_sphere))
		return (1);
	return (0);
}
