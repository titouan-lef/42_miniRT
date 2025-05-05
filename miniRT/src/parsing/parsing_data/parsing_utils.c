/// @todo header

#include "minirt.h"

/**
 * @brief Init all pointeur of the struct at NULL.
 */
void	init_scene(t_scene *scene, t_lst_parse *lst_parse)
{
	scene->tab_obj = NULL;
	scene->tab_l = NULL;
	lst_parse->lst_obj = NULL;
	lst_parse->lst_l = NULL;
}

/**
 * @brief Convert a string in dimension in double.
 * @return 1 if the value is negativ or egal 0.
 */
int	take_dimension(double *dimension, char *str)
{
	int	error;

	*dimension = ft_todouble(str, &error);
	return (error || *dimension <= 0);
}

/**
 * @brief Check the files types is valid is .rt.
 * @return 1 if the files types is invalid
 */
int	check_files_type(char *str, char *type)
{
	size_t	size;
	size_t	size_type;
	size_t	i;

	size = ft_strlen(str);
	size_type = ft_strlen(type);
	i = 1;
	if (size <= size_type)
		return (1);
	while (i < size_type)
	{
		if (str[size - i] != type[size_type - i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Check the first line of tab for look identifer
 * @param str Id of string.
 * @return Nb in fonction of id detected.
 * @warning 7 is for a cone for bonus.
 */
int	check_valid_id(char *str, int single_entity[2])
{
	if (!ft_strcmp(str, "C"))
	{
		single_entity[0] += 1;
		return (CAMERA);
	}
	if (!ft_strcmp(str, "A"))
	{
		single_entity[1] += 1;
		return (AMBIENT);
	}
	if (!ft_strcmp(str, "L"))
		return (LIGHT);
	if (!ft_strcmp(str, "sp"))
		return (SPHERE);
	if (!ft_strcmp(str, "pl"))
		return (PLANE);
	if (!ft_strcmp(str, "cy"))
		return (CYLINDER);
	if (!ft_strcmp(str, "co") && CONE_ACTIVE == 1)
		return (CONE);
	print_error_message(ERR_ID);
	return (OBJ_ERR);
}
