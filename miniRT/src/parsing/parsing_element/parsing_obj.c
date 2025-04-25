/// @todo header

#include "minirt.h"

void	clear_obj(void *data)
{
	t_obj	*obj;

	if (data == NULL)
		return ;
	obj = (t_obj *)data;
	if (obj->pattern.bump.name)
	{
		free(obj->pattern.bump.name);
		obj->pattern.bump.name = NULL;
	}
	if (obj->pattern.texture.name)
	{
		free(obj->pattern.texture.name);
		obj->pattern.texture.name = NULL;
	}
	free(obj->data);
	obj->data = NULL;
}

t_obj	*init_obj(void)
{
	t_obj	*obj;

	obj = malloc (sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->pattern.bump.name = NULL;
	obj->pattern.texture.name = NULL;
	return (obj);
}

/**
 * @brief Alloc a new node for obj list.
 * @return 1 if an alloc failled.
 */
int	alloc_new_obj(t_list **head, void *new_obj, char **tab, t_obj_type type)
{
	t_list	*new_node;
	t_obj	*obj;

	obj = init_obj();
	if (!obj)
		return (1);
	if (take_pattern(&obj->pattern, tab))
	{
		clear_obj(obj);
		free(obj);
		return (1);
	}
	obj->data = new_obj;
	obj->type = type;
	new_node = ft_lstnew(obj);
	if (!new_node)
	{
		clear_obj(obj);
		free(obj);
		return (1);
	}
	ft_lstadd_front(head, new_node);
	return (0);
}
