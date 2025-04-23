/// @todo header

#include "minirt.h"

static char	*complete_colors(double *color, char *str)
{
	int		error;
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*color = ft_to_number(str, &error, 255);
		end++;
	}
	else
		*color = ft_to_number(str, &error, 255);
	if (error != 0 || color < 0)
		return (NULL);
	*color /= 255.0;
	str += end;
	return (str);
}

/**
 * @brief Convert a string to a color.
 * @return Return 1 if the arg isn't valid or value is not between 0 and 255.
 */
int	take_color(t_vec3 *colors, char *str)
{
	str = complete_colors(&colors->x, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->y, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->z, str);
	if (!str || *str)
		return (1);
	return (0);
}
