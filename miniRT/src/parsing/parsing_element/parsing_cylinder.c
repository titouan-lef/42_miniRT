/// @todo header

#include "minirt.h"

static t_cylinder_obj	*alloc_new_cylinder(char **tab)
{
	t_cylinder_obj	*new_cy;

	new_cy = malloc(sizeof(t_cylinder_obj));
	if (!new_cy)
		return (NULL);
	if (take_pos(&new_cy->cy.pos, tab[1])
		|| take_dir(&new_cy->cy.dir, tab[2])
		|| take_dimension(&new_cy->cy.r, tab[3])
		|| take_dimension(&new_cy->cy.hh, tab[4]))
	{
		print_error_message(ERR_CYLINDER);
		free(new_cy);
		return (NULL);
	}
	new_cy->cy.r *= 0.5;
	new_cy->cy.hh *= 0.5;
	return (new_cy);
}

/**
 * @brief Init Cylinder_obj data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	cylinder_interpreter(t_list **lst_obj, char **tab)
{
	t_cylinder_obj	*new_cy;

	if (ft_matrix_get_row((void **)tab) != NB_PARAM_CY)
	{
		print_error_message(ERR_CYLINDER);
		return (1);
	}
	new_cy = alloc_new_cylinder(tab);
	if (!new_cy)
		return (1);
	if (alloc_new_obj(lst_obj, new_cy, tab + 5, CYLINDER))
	{
		free(new_cy);
		print_error_message(ERR_CYLINDER);
		return (1);
	}
	init_local_coordinates(&new_cy->cy.dir, &new_cy->cy.right, &new_cy->cy.up);
	return (0);
}
