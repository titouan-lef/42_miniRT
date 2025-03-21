/// @todo header

#include "minirt.h"

static char	*complete_colors(int *color, char *str)
{
	int		error;
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*color = (int)ft_to_number(str, &error, 255);
		end++;
	}
	else
		*color = (int)ft_to_number(str, &error, 255);
	if (error != 0 || *color < 0)
		return (NULL);
	str += end;
	return (str);
}

int	take_color(t_color *colors, char *str)
{
	str = complete_colors(&colors->r, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->g, str);
	if (!str || !*str)
		return (1);
	str = complete_colors(&colors->b, str);
	if (!str || *str)
		return (1);
	return (0);
}
