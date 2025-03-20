/// @todo header

#include "minirt.h"

int	main(int ac, char ** av)
{
	t_scene scene;

	/*char *str = "     					";
	char **tmp;
	printf("%s\n", str);
	tmp = ft_split_charset(str, "\t\n\v\f\r ");
	int i = 0;
	while (tmp[i])
	{
		printf("%s\n", tmp[i++]);
	}*/
	parsing(ac, av, &scene);
	return (0);
}
