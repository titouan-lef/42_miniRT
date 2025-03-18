#include "minirt.h"

int	check_files_type(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (1);
	if (str[size - 1] != 't')
		return (1);
	if (str[size - 2] != 'r')
		return (1);
	if (str[size - 3] != '.')
		return (1);
	return (0);
}