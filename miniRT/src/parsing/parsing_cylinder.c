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
		|| take_dimension(&new_cy->cy.hh, tab[4])
		|| take_color(&new_cy->color, tab[5]))
	{
		print_error_message(ERR_CYLINDER);
		free(new_cy);
		return (NULL);
	}
	new_cy->cy.r *= 0.5;
	new_cy->cy.hh *= 0.5;
	return (new_cy);
}

int	cylinder_interpreter(t_list **lst_obj, char **tab)
{
	t_cylinder_obj	*new_cy;
	t_vec3			up_wish;

	if (ft_matrix_get_row((void **)tab) != 6)
		return (1);
	new_cy = alloc_new_cylinder(tab);
	if (!new_cy)
		return (1);
	if (alloc_new_obj(lst_obj, new_cy, CYLINDER))
	{
		free(new_cy);
		return (1);
	}
	up_wish = ft_create_vec3(0, 1, 0);
	if (new_cy->cy.dir.x == 0 && new_cy->cy.dir.z == 0)
	{
		if (new_cy->cy.dir.y == 1)
			up_wish = ft_create_vec3(0, 0, -1);
		else if (new_cy->cy.dir.y == -1)
			up_wish = ft_create_vec3(0, 0, 1);
	}
	new_cy->cy.right = ft_cross_vec3(&up_wish, &new_cy->cy.dir);
	new_cy->cy.up = ft_cross_vec3(&new_cy->cy.dir, &new_cy->cy.right);
	return (0);
}
