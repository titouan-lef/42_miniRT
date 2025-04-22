/// @todo header

#include "minirt.h"

static char	*complete_colors(uint8_t *color, char *str)
{
	int		error;
	double	clr;
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		clr = ft_to_number(str, &error, 255);
		end++;
	}
	else
		clr = ft_to_number(str, &error, 255);
	if (error != 0 || clr < 0)
		return (NULL);
	*color = (uint8_t)clr;
	str += end;
	return (str);
}

/**
 * @brief Convert a string to a color.
 * @return Return 1 if the arg isn't valid or value is not between 0 and 255.
 */
int	take_color(t_color *colors, char *str)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	str = complete_colors(&r, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&g, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&b, str);
	if (!str || *str)
		return (1);
	*colors = ft_color_create(r, g, b, 255);
	return (0);
}
