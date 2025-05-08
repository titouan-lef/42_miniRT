/// @todo header

#include "minirt.h"

/**
 * @brief Frees all nodes in the list after tranformation to array.
 */
void	clear_lst_parse(t_lst_parse **lst_parse, void (*del)(void *))
{
	if (del != NULL)
		ft_lstclear(&(*lst_parse)->lst_obj, clear_obj);
	else
		ft_lstclear(&(*lst_parse)->lst_obj, del);
	(*lst_parse)->lst_obj = NULL;
	ft_lstclear(&(*lst_parse)->lst_l, del);
	(*lst_parse)->lst_l = NULL;
	*lst_parse = NULL;
}

/**
 * @brief Convert a linked list to an array.
 */
static void	fill_tab(void **tab, t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		tab[i] = lst->content;
		lst = lst->next;
		++i;
	}
	tab[i] = NULL;
}

/**
 * @brief Convert lst_obj and lst_l to table.
 * @return Return 1 if an allocation have failed.
 */
int	lst_parse_to_tab(t_scene *scene, t_lst_parse *lst_parse)
{
	size_t	nb_obj;
	size_t	nb_l;

	nb_obj = ft_lstsize(lst_parse->lst_obj);
	scene->tab_obj = (t_obj **)malloc(sizeof(t_obj *) * (nb_obj + 1));
	if (!scene->tab_obj)
	{
		clear_lst_parse(&lst_parse, free);
		print_error_message(ERR_MALLOC);
		return (1);
	}
	nb_l = ft_lstsize(lst_parse->lst_l);
	scene->tab_l = (t_light **)malloc(sizeof(t_light *) * (nb_l + 1));
	if (!scene->tab_l)
	{
		clear_lst_parse(&lst_parse, free);
		free(scene->tab_obj);
		scene->tab_obj = NULL;
		print_error_message(ERR_MALLOC);
		return (1);
	}
	fill_tab((void **)scene->tab_obj, lst_parse->lst_obj);
	fill_tab((void **)scene->tab_l, lst_parse->lst_l);
	clear_lst_parse(&lst_parse, NULL);
	return (0);
}
