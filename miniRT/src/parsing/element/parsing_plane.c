/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:14 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:47:30 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Alloc t_plane_obj and initialise pos, dir.
 * @return Return NULL if a data are false or an allocation have failed.
 */
static t_plane_obj	*alloc_new_plan(char **tab)
{
	t_plane_obj	*new_pl;
	t_vec3		n;
	t_vec3		p;

	new_pl = malloc(sizeof(t_plane_obj));
	if (!new_pl)
	{
		print_error_message(ERR_MALLOC);
		return (NULL);
	}
	if (take_pos(&p, tab[1]) || take_dir(&n, tab[2]))
	{
		print_error_message(ERR_PLANE);
		free(new_pl);
		return (NULL);
	}
	new_pl->pl = ft_create_plane(&n, &p);
	return (new_pl);
}

/**
 * @brief Init Plane_obj data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	plan_interpreter(t_list **lst_obj, char **tab)
{
	t_plane_obj	*new_pl;

	if (ft_matrix_get_row((void **)tab) != NB_PARAM_PL)
	{
		print_error_message(ERR_PLANE);
		return (1);
	}
	new_pl = alloc_new_plan(tab);
	if (!new_pl)
		return (1);
	if (alloc_new_obj(lst_obj, new_pl, tab + 3, PLANE))
	{
		free(new_pl);
		ft_putendl_error(ERR_OBJ_PLANE);
		return (1);
	}
	init_local_coordinates(&new_pl->pl.n, &new_pl->right, &new_pl->up);
	return (0);
}
