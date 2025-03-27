/// @todo header

#include "minirt.h"

void	camera_translation(t_scene *scene, int key)
{
	if (key == SDL_SCANCODE_W)
		scene->camera.position.z += 10;
	if (key == SDL_SCANCODE_S)
		scene->camera.position.z -= 10;
	if (key == SDL_SCANCODE_A)
		scene->camera.position.x -= 10;
	if (key == SDL_SCANCODE_D)
		scene->camera.position.x += 10;
	if (key == SDL_SCANCODE_SPACE)
		scene->camera.position.y -= 10;
	if (key == SDL_SCANCODE_F)
		scene->camera.position.y += 10;
}

/**
 * @brief rotation on x and y
 * @details make a ratio of mouse moove for create a director vector
 */
void	camera_rotation(t_scene *scene, double x, double y)
{
	t_vector3	camera;
	t_vector3	axis;

	camera = scene->camera.orientation;
	x = x / WIN_HW - 1;
	y = y / WIN_HH - 1;
	axis = ft_create_vector3(y, -x, 0);
	scene->camera.orientation = ft_rotation_quaternion(camera,
			M_PI / 90, axis);
}

/**
 * @brief handle a mouse mmove
 * @details when you moove the mouse the camera rotate
 */
void	mouse_event(t_scene *scene, t_graph_sys *graph_sys)
{
	int			mv_mouse_x;
	int			mv_mouse_y;

	mlx_mouse_get_pos(scene->graph_sys.mlx, &mv_mouse_x, &mv_mouse_y);
	if ((mv_mouse_x - WIN_HW) / 100 != 0 || (mv_mouse_y - WIN_HH) / 100 != 0)
		camera_rotation(scene, mv_mouse_x, mv_mouse_y);
	mlx_mouse_move(graph_sys->mlx, graph_sys->win, WIN_HW, WIN_HH);
}

void	key_hook_cam(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	camera_translation(scene, key);
}
