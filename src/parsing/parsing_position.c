/// @todo header

#include "minirt.h"

static char	*complete_position(int *position, char *str)
{
	int	error;
	size_t	i;

	i = 0;
	error = 0;
	while(str[i] && str[i] != ',')
		i++;
	if (str[i] == ',')
	{
		str[i] = '\0';
		*position = ft_to_number(str, &error, 255);
		i++;
	}
	else
		*position = ft_to_number(str, &error, 255);
	if (error != 0)
		return (NULL);
	str += i;
	return (str);
}

int take_position(t_vector3 *position, char *str)
{
	char *tmp;

	tmp = str;
	tmp = complete_position(&position->x, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_position(&position->y, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_position(&position->z, tmp);
	if (!tmp || *tmp)
		return (1);
	return (0);	
}
