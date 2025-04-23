/// @todo header

#include "minirt.h"

static void	camera_translation(t_cam *cam, int key)
{
	if (key == SDL_SCANCODE_W)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->dir, 10);
	else if (key == SDL_SCANCODE_S)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->dir, -10);
	else if (key == SDL_SCANCODE_D)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->right, 10);
	else if (key == SDL_SCANCODE_A)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->right, -10);
	else if (key == SDL_SCANCODE_SPACE)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->up, -10);
	else if (key == SDL_SCANCODE_F)
		cam->pos = ft_translation_vec3(&cam->pos, &cam->up, 10);
}

/**
 * @brief rotation on x and y
 * @details make a ratio of mouse moove for create a director vector
 */
static void	camera_rotation(t_cam *cam, double x, double y)
{
	double	angle;

	x = x / WIN_HW;
	if (x > 0.05)
	{
		angle = M_PI * (x - 1) * SENSITIVITY;
		cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->up);
		cam->right = ft_cross_vec3(&cam->up, &cam->dir);
	}
	y = y / WIN_HW;
	if (y > 0.05)
	{
		angle = -M_PI * (y - WIN_HH / WIN_HW) * SENSITIVITY;
		cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->right);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
}

/**
 * @brief handle a mouse mmove
 * @details when you moove the mouse the camera rotate
 */
void	mouse_event(t_scene *scene, t_graph_sys *g_sys)
{
	int	mv_mouse_x;
	int	mv_mouse_y;

	mlx_mouse_get_pos(scene->g_sys.mlx, &mv_mouse_x, &mv_mouse_y);
	camera_rotation(&scene->cam, mv_mouse_x, mv_mouse_y);
	mlx_mouse_move(g_sys->mlx, g_sys->win, WIN_HW, WIN_HH);
}

void	camera_rotation_key(t_cam *cam, int key)
{
	double	angle;

	if (key == SDL_SCANCODE_Q)
	{
		angle = M_PI * 0.1 * SENSITIVITY;
		cam->right = ft_rotation_quat(&cam->right, angle, &cam->dir);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
	if (key == SDL_SCANCODE_E)
	{
		angle = -M_PI * 0.1 * SENSITIVITY;
		cam->right = ft_rotation_quat(&cam->right, angle, &cam->dir);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
}

void	key_hook_cam(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	camera_rotation_key(&scene->cam, key);
	camera_translation(&scene->cam, key);
}
