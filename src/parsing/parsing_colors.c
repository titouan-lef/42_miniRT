/// @todo header

#include "minirt.h"

static char	*complete_colors(int *color, char *str)
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
		*color = (int)ft_to_number(str, &error, 255);
		i++;
	}
	else
		*color = (int)ft_to_number(str, &error, 255);
	if (error != 0 || *color < 0)
		return (NULL);
	str += i;
	return (str);
}

int take_color(t_color *colors, char *str)
{
	char *tmp;

	tmp = str;
	tmp = complete_colors(&colors->r, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_colors(&colors->g, tmp);
	if (!tmp || !*tmp)
		return (1);
	tmp = complete_colors(&colors->b, tmp);
	if (!tmp || *tmp)
		return (1);
	return (0);	
}