/// @todo header

#include "minirt.h"

static int	take_fov(int *fov, char *str)
{
	int	error;

	*fov = ft_to_number(str, &error, 180);
	return (error || *fov < 0);
}

int	camera_interpreter(t_scene *scene, char **tab)
{
	t_vec3	up_wish;

	if (ft_matrix_get_row((void **)tab) != 4)
		return (1);
	if (take_pos(&scene->cam.pos, tab[1])
		|| take_dir(&scene->cam.dir, tab[2])
		|| take_fov(&scene->cam.fov, tab[3]))
	{
		print_error_message(ERR_CAMERA);
		return (1);
	}
	up_wish = ft_create_vec3(0, 1, 0);
	if (scene->cam.dir.x == 0 && scene->cam.dir.z == 0)
	{
		if (scene->cam.dir.y == 1)
			up_wish = ft_create_vec3(0, 0, -1);
		else if (scene->cam.dir.y == -1)
			up_wish = ft_create_vec3(0, 0, 1);
	}
	scene->cam.right = ft_cross_vec3(&up_wish, &scene->cam.dir);
	scene->cam.right = ft_normalize_vec3(&scene->cam.right);
	scene->cam.up = ft_cross_vec3(&scene->cam.dir, &scene->cam.right);
	scene->cam.up = ft_normalize_vec3(&scene->cam.up);
	return (0);
}
