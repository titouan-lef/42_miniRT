/// @todo header

#include "minirt.h"

static int	alloc_new_node(t_list **head, t_light *new_light)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_light);
	if (!new_node)
	{
		free (new_light);
		return (1);
	}
	ft_lstadd_back(head, new_node);
	return (0);
}

static t_light	*alloc_new_light(char **tab)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	if (!new_light)
		return (NULL);
	if (take_position(&new_light->position, tab[1]))
}

int	light_interpreter(t_scene *scene, char **tab)
{
	t_light	*new_light;
	int		error;

	error = 0;
	if (tab_size(tab) != 4)
		return (1);
	new_light = alloc_new_light(tab);
	if (!new_light)
		return (1);
	if (alloc_new_node(&scene->lst_light, new_light))
		return (1);
	return (0);
}