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
	if (error != 0 || *color < 0)
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

static int	active_checkboard(int *status, char *str)
{
	if (!ft_strcmp(str, "ON"))
		*status = 1;
	else if (!ft_strcmp(str, "OFF"))
		*status = 0;
	else
		return (1);
	return (0);
}

static int	take_texture_files(char **name, char *str)
{
	int	fd;

	if (!ft_strcmp(str, "NULL"))
		return (0);
	if (check_files_type(str, ".png"))
		return (1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	*name = ft_strdup(str);
	if (!name)
		return (1);
	return (0);
}

int	take_pattern(t_pattern *pattern, char **tab)
{
	if (take_color(&pattern->colors, tab[0])
		|| active_checkboard(&pattern->checkerboard, tab[1])
		|| take_texture_files(&pattern->texture.name, tab[2])
		|| take_texture_files(&pattern->bump.name, tab[3]))
	{
		return (1);
	}
	return (0);
}
