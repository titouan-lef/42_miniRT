/// @todo header

#include "minirt.h"

static int	take_fov(int *fov, char *str)
{
	int	error;

	*fov = ft_to_number(str, &error, 180);
	return (error || fov < 0);
}

int	camera_interpreter(t_scene *scene, char **tab)
{
	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	if (take_pos(&scene->cam.pos, tab[1])
		|| take_dir(&scene->cam.dir, tab[2])
		|| take_fov(&scene->cam.fov, tab[3]))
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	return (0);
}
