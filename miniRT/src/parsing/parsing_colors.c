/// @todo header

#include "minirt.h"

static char	*complete_colors(uint8_t *color, char *str)
{
	int		error;
	size_t	end;

	end = 0;
	while (str[end] && str[end] != ',')
		end++;
	if (str[end] == ',')
	{
		str[end] = '\0';
		*color = (uint8_t)ft_to_number(str, &error, 255);
		end++;
	}
	else
		*color = (uint8_t)ft_to_number(str, &error, 255);
	if (error != 0 || *color < 0) //probleme under flow
		return (NULL);
	str += end;
	return (str);
}

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
