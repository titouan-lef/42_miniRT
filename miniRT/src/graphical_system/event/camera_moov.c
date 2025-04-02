/// @todo header

#include "minirt.h"

static void	camera_translation(t_scene *scene, int key)
{
	if (key == SDL_SCANCODE_W)
		scene->cam.pos.z += 10;
	if (key == SDL_SCANCODE_S)
		scene->cam.pos.z -= 10;
	if (key == SDL_SCANCODE_A)
		scene->cam.pos.x -= 10;
	if (key == SDL_SCANCODE_D)
		scene->cam.pos.x += 10;
	if (key == SDL_SCANCODE_SPACE)
		scene->cam.pos.y += 10;
	if (key == SDL_SCANCODE_F)
		scene->cam.pos.y -= 10;
}

/**
 * @brief rotation on x and y
 * @details make a ratio of mouse moove for create a director vector
 */
static void	camera_rotation(t_scene *scene, double x, double y)
{
	t_vector3	cam;
	t_vector3	axis;

	cam = scene->cam.dir;
	x = x / WIN_HW - 1;
	y = y / WIN_HH - 1;
	axis = ft_create_vector3(-y, -x, 0);
	scene->cam.dir = ft_rotation_quaternion(cam, M_PI / 22.5, axis);
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
