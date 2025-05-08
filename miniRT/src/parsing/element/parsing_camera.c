/// @todo header

#include "minirt.h"

/**
 * @brief Convert a string in FOV value.
 * @return Return 1 if is superior at 180 and inferior at 0 are false.
 */
static int	take_fov(int *fov, char *str)
{
	int	error;

	*fov = ft_to_number(str, &error, 180);
	return (error || *fov < 0);
}

/**
 * @brief Init camera data and check valid argument and value.
 * @return Return 1 if a data are false.
 */
int	camera_interpreter(t_scene *scene, char **tab)
{
	if (ft_matrix_get_row((void **)tab) != 4)
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	if (take_pos(&scene->cam.pos, tab[1])
		|| take_dir(&scene->cam.dir, tab[2])
		|| take_fov(&scene->cam.fov, tab[3]))
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	init_local_coordinates(&scene->cam.dir, &scene->cam.right, &scene->cam.up);
	return (0);
}
