/// @todo header

#include "minirt.h"

int	main(int ac, char **av)
{
	int	result;
	t_scene	scene;

	//manage_graphical_system();
	result = parsing(ac, av, &scene);
	exit_error_parsing(&scene);
	return (result);
}
