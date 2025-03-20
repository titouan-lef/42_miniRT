/// @todo header

#include "minirt.h"

int	camera_interpreter(t_scene *scene, char **tab)
{
	int	error;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	scene->camera.fov = ft_to_number(tab[3], &error, 180);
	if (error != 0 || scene->camera.fov < 0)
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	if (take_position(&scene->camera.position, tab[1]))
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	if (take_orientation(&scene->camera.orientation, tab[2]))
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	return (0);
}
