/// @todo header

#include "minirt.h"

static int	take_light_intensity(double *intensity, char *str)
{
	int	error;

	*intensity = ft_todouble(str, &error);
	return (error || *intensity < 0 || *intensity > 1);
}

static int	alloc_new_node(t_list **head, t_light *new_light)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_light);
	if (!new_node)
		return (1);
	ft_lstadd_front(head, new_node);
	return (0);
}

static t_light	*alloc_new_light(char **tab)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	if (!new_light)
		return (NULL);
	if (take_position(&new_light->position, tab[1])
		|| take_light_intensity(&new_light->lbr, tab[2])
		|| take_color(&new_light->color, tab[3]))
	{
		print_error_message(ERR_LIGHT);
		free(new_light);
		return (NULL);
	}
	return (new_light);
}

int	light_interpreter(t_scene *scene, char **tab)
{
	t_light	*new_light;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	new_light = alloc_new_light(tab);
	if (!new_light)
		return (1);
	if (alloc_new_node(&scene->lst_light, new_light))
	{
		free (new_light);
		return (1);
	}
	return (0);
}

int	ambient_interpreter(t_scene *scene, char **tab)
{
	if (ft_matrix_get_row((void **)tab) != 3
		|| take_light_intensity(&scene->ambient.lr, tab[1])
		|| take_color(&scene->ambient.color, tab[2]))
	{
		print_error_message(ERR_AMBIENT);
		return (1);
	}
	return (0);
}
