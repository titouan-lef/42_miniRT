/// @todo header

#include "minirt.h"

void	init_scene(t_scene *scene)
{
	scene->lst_light = NULL;
	scene->lst_obj = NULL;
}

size_t	tab_size(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
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
		return (OBJ_ERR);
	if (!ft_strcmp(str, "A"))
		return (AMBIENT);
	else if (!ft_strcmp(str, "C"))
		return (CAMERA);
	else if (!ft_strcmp(str, "L"))
		return (LIGHT);
	else if (!ft_strcmp(str, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(str, "pl"))
		return (PLAN);
	else if (!ft_strcmp(str, "cy"))
		return (CYLINDER);
	else if (!ft_strcmp(str, "co"))
		return (CONE);
	print_error_message(ERR_ID);
	return (OBJ_ERR);
}
