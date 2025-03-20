/// @todo header

#include "minirt.h"

int	alloc_new_obj(t_list **head, void *new_obj, t_obj_type type)
{
	t_list	*new_node;
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
		return (1);
	obj->data = new_obj;
	obj->type = type;
	new_node = ft_lstnew(obj);
	if (!new_node)
	{
		free(obj);
		return (1);
	}
	ft_lstadd_front(head, new_node);
	return (0);
}

void	init_scene(t_scene *scene)
{
	scene->lst_light = NULL;
	scene->lst_obj = NULL;
}

int	take_dimension(double *dimension, char *str)
{
	int	error;

	*dimension = ft_todouble(str, &error);
	return (error || *dimension <= 0);
}

int	check_files_type(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (size < 4)
		return (1);
	if (str[size - 1] != 't')
		return (1);
	if (str[size - 2] != 'r')
		return (1);
	if (str[size - 3] != '.')
		return (1);
	return (0);
}

/**
 * @brief Check the first line of tab for look identifer
 * @param str id of string.
 * @return nb in fonction of id detected.
 * @warning 7 is for a cone for bonus.
 */
int	check_valid_id(char *str)
{
	if (!str)
	{
		print_error_message(ERR_ID);
		return (OBJ_ERR);
	}
	if (!ft_strcmp(str, "A"))
		return (AMBIENT);
	if (!ft_strcmp(str, "C"))
		return (CAMERA);
	if (!ft_strcmp(str, "L"))
		return (LIGHT);
	if (!ft_strcmp(str, "sp"))
		return (SPHERE);
	if (!ft_strcmp(str, "pl"))
		return (PLAN);
	if (!ft_strcmp(str, "cy"))
		return (CYLINDER);
	if (!ft_strcmp(str, "co"))
		return (CONE);
	print_error_message(ERR_ID);
	return (OBJ_ERR);
}
