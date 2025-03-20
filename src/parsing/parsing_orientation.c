/// @todo header

#include "minirt.h"

static char	*complete_orientation(double *orientation, char *str)
{
	int		error;
	size_t	i;

	i = 0;
	error = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] == ',')
	{
		str[i] = '\0';
		*orientation = ft_todouble(str, &error);
		i++;
	}
	else
		*orientation = ft_todouble(str, &error);
	if (error != 0 || *orientation < -1 || *orientation > 1)
		return (NULL);
	str += i;
	return (str);
}

int	take_orientation(t_vector3 *orientation, char *str)
{
	char	*tmp;

	tmp = str;
	tmp = complete_orientation(&orientation->x, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_orientation(&orientation->y, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_orientation(&orientation->z, tmp);
	if (!tmp || *tmp)
		return (1);
	return (0);
}
