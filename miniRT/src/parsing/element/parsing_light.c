/// @todo header

#include "minirt.h"

/**
 * @brief Convert a string in intensity in double.
 * @return 1 if the value is negativ or superior at 1.
 */
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
	{
		print_error_message(ERR_MALLOC);
		return (1);
	}
	ft_lstadd_front(head, new_node);
	return (0);
}

/**
 * @brief Alloc Light difuse data and check valid argument and value.
 * @return Return NULL if a data are false or allocation failed.
 */
static t_light	*alloc_new_light(char **tab)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	if (!new_light)
	{
		print_error_message(ERR_MALLOC);
		return (NULL);
	}
	if (take_pos(&new_light->pos, tab[1])
		|| take_light_intensity(&new_light->lbr, tab[2])
		|| take_color(&new_light->color, tab[3]))
	{
		print_error_message(ERR_LIGHT);
		free(new_light);
		return (NULL);
	}
	if (COLOR_LIGHT_ACTIVE == 0)
		new_light->color = ft_create_vec3(1.0, 1.0, 1.0);
	return (new_light);
}

/**
 * @brief Init Light difuse data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	light_interpreter(t_list **lst_l, char **tab)
{
	t_light	*new_l;

	if (ft_matrix_get_row((void **)tab) != 4)
	{
		print_error_message(ERR_LIGHT);
		return (1);
	}
	new_l = alloc_new_light(tab);
	if (!new_l)
		return (1);
	if (alloc_new_node(lst_l, new_l))
	{
		free(new_l);
		return (1);
	}
	return (0);
}

/**
 * @brief Init Ambient light data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	ambient_interpreter(t_scene *scene, char **tab)
{
	if (ft_matrix_get_row((void **)tab) != 3
		|| take_light_intensity(&scene->amb.lr, tab[1])
		|| take_color(&scene->amb.color, tab[2]))
	{
		print_error_message(ERR_AMBIENT);
		return (1);
	}
	return (0);
}
