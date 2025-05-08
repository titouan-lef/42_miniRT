/// @todo header

#include "minirt.h"

/**
 * @brief Alloc t_sphere_obj and initialise pos, rayon.
 * @return Return NULL if a data are false or an allocation have failed.
 */
static t_sphere_obj	*alloc_new_sphere(char **tab)
{
	t_sphere_obj	*new_sp;

	new_sp = malloc(sizeof(t_sphere_obj));
	if (!new_sp)
	{
		print_error_message(ERR_MALLOC);
		return (NULL);
	}
	if (take_pos(&new_sp->sp.pos, tab[1])
		|| take_dimension(&new_sp->sp.r, tab[2]))
	{
		print_error_message(ERR_SPHERE);
		free(new_sp);
		return (NULL);
	}
	new_sp->sp.r *= 0.5;
	return (new_sp);
}

/**
 * @brief Init Sphere_obj data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	sphere_interpreter(t_list **lst_obj, char **tab)
{
	t_sphere_obj	*new_sp;

	if (ft_matrix_get_row((void **)tab) != NB_PARAM_SP)
	{
		print_error_message(ERR_SPHERE);
		return (1);
	}
	new_sp = alloc_new_sphere(tab);
	if (!new_sp)
		return (1);
	if (alloc_new_obj(lst_obj, new_sp, tab + 3, SPHERE))
	{
		free(new_sp);
		ft_putendl_error(ERR_OBJ_SPHERE);
		return (1);
	}
	return (0);
}
