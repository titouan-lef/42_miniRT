/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:46 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:46:51 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Alloc t_cone_obj and initialise pos, dir,
 * rayon and dimension height.
 * @return Return NULL if a data are false or an allocation have failed.
 */
static t_cone_obj	*alloc_new_cone(char **tab)
{
	t_cone_obj	*new_co;

	new_co = malloc(sizeof(t_cone_obj));
	if (!new_co)
	{
		print_error_message(ERR_MALLOC);
		return (NULL);
	}
	if (take_pos(&new_co->co.pos, tab[1])
		|| take_dir(&new_co->co.dir, tab[2])
		|| take_dimension(&new_co->co.r, tab[3])
		|| take_dimension(&new_co->co.h, tab[4]))
	{
		print_error_message(ERR_CONE);
		free(new_co);
		return (NULL);
	}
	new_co->co.r *= 0.5;
	return (new_co);
}

/**
 * @brief Init Cone_obj data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	cone_interpreter(t_list **lst_obj, char **tab)
{
	t_cone_obj	*new_co;

	if (ft_matrix_get_row((void **)tab) != NB_PARAM_CO)
	{
		print_error_message(ERR_CONE);
		return (1);
	}
	new_co = alloc_new_cone(tab);
	if (!new_co)
		return (1);
	if (alloc_new_obj(lst_obj, new_co, tab + 5, CONE))
	{
		free(new_co);
		ft_putendl_error(ERR_OBJ_CONE);
		return (1);
	}
	init_local_coordinates(&new_co->co.dir, &new_co->co.right, &new_co->co.up);
	return (0);
}
