/// @todo header

#include "minirt.h"

static char	*get_vector_value(double *value, char *str, int *error)
{
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*value = ft_todouble(str, error);
		end++;
	}
	else
		*value = ft_todouble(str, error);
	str += end;
	return (str);
}

static char	*complete_orientation(double *orientation, char *str)
{
	int		error;

	str = get_vector_value(orientation, str, &error);
	if (error != 0 || *orientation < -1 || *orientation > 1)
		return (NULL);
	return (str);
}

static char	*complete_position(double *position, char *str)
{
	int		error;

	str = get_vector_value(position, str, &error);
	if (error != 0)
		return (NULL);
	return (str);
}

int	take_orientation(t_vector3 *orientation, char *str)
{
	str = complete_orientation(&orientation->x, str);
	if (!str || !*str)
		return (1);
	str = complete_orientation(&orientation->y, str);
	if (!str || !*str)
		return (1);
	str = complete_orientation(&orientation->z, str);
	if (!str || *str)
		return (1);
	return (0);
}

int	take_position(t_vector3 *position, char *str)
{
	str = complete_position(&position->x, str);
	if (!str || !*str)
		return (1);
	str = complete_position(&position->y, str);
	if (!str || !*str)
		return (1);
	str = complete_position(&position->z, str);
	if (!str || *str)
		return (1);
	return (0);
}
