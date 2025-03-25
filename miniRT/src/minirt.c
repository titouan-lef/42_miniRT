/// @todo header

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;

	if (parsing(ac, av, &scene))
	{
		exit_error_parsing(&scene);
		return (1);
	}
	if (manage_graphical_system(&scene))
	{
		exit_error_parsing(&scene);
		return (1);
	}
	exit_error_parsing(&scene);
	return (0);
}
