/// @todo header

#include "minirt.h"

static void	camera_translation(t_cam *cam, int key)
{
	if (key == SDL_SCANCODE_W)
		cam->pos = ft_translation(&cam->pos, &cam->dir, 10);
	else if (key == SDL_SCANCODE_S)
		cam->pos = ft_translation(&cam->pos, &cam->dir, -10);
	else if (key == SDL_SCANCODE_D)
		cam->pos = ft_translation(&cam->pos, &cam->right, 10);
	else if (key == SDL_SCANCODE_A)
		cam->pos = ft_translation(&cam->pos, &cam->right, -10);
	else if (key == SDL_SCANCODE_SPACE)
		cam->pos = ft_translation(&cam->pos, &cam->up, 10);
	else if (key == SDL_SCANCODE_F)
		cam->pos = ft_translation(&cam->pos, &cam->up, -10);
}

/**
 * @brief rotation on x and y
 * @details make a ratio of mouse moove for create a director vector
 */
static void	camera_rotation(t_cam *cam, double x, double y)
{
	//t_vec3	axis;
	double	angle;

	x = (x - WIN_HW) / WIN_HW;
	y = (y - WIN_HH) / WIN_HH;
	if (x == 0 && y == 0)
		return ;
	angle = M_PI / 90.0 * (-x);
	cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->up);
	cam->right = ft_rotation_quat(&cam->right, angle, &cam->up);
	angle = M_PI / 90.0 * (-y);
	cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->right);
	cam->up = ft_rotation_quat(&cam->up, angle, &cam->right);




	/*if (cam->dir.z > 0)
		axis = ft_create_vec3(-y, x, 0);
	else
		axis = ft_create_vec3(y, x, 0);
	angle = M_PI / 135.0 * 0.1;
	angle *= ft_norm_vec3(&axis);
	cam->dir = ft_rotation_quat(&cam->dir, angle, &axis);
	cam->right = ft_rotation_quat(&cam->right, angle, &axis);
	cam->up = ft_rotation_quat(&cam->up, angle, &axis);*/



	//cam->dir = ft_normalize_vec3(&cam->dir);
	//cam->right = ft_normalize_vec3(&cam->right);
	//cam->up = ft_normalize_vec3(&cam->up);
	//printf("dir(%f, %f, %f) right(%f, %f, %f) up(%f, %f, %f)\n",
	//	cam->dir.x, cam->dir.y, cam->dir.z, cam->right.x, cam->right.y, cam->right.z, cam->up.x, cam->up.y, cam->up.z);
	//cam->up = ft_cross_vec3(&cam->right, &cam->dir);
}

/*static void	camera_rotation(t_cam *cam, double x, double y)
{
	t_vec3	axis;
	t_vec3	new_dir;
	double	angle;

	x = x - WIN_HW;
	y = y - WIN_HH;
	if (x == 0 && y == 0)
		return ;
	if (cam->dir.z >= 0)
		new_dir = ft_create_vec3(cam->dir.x + x, cam->dir.y + y, cam->dir.z);
	else
		new_dir = ft_create_vec3(cam->dir.x - x, cam->dir.y - y, cam->dir.z);
	new_dir = ft_normalize_vec3(&new_dir);
	axis = ft_cross_vec3(&cam->dir, &new_dir);
	angle = ft_dot_vec3(&cam->dir, &new_dir);
	angle = acos(angle) * 0.01;
	cam->dir = ft_rotation_quat(&cam->dir, angle, &axis);
	cam->right = ft_rotation_quat(&cam->right, angle, &axis);
	cam->up = ft_rotation_quat(&cam->up, angle, &axis);
}*/

/**
 * @brief handle a mouse mmove
 * @details when you moove the mouse the camera rotate
 */
void	mouse_event(t_scene *scene, t_graph_sys *g_sys)
{
	int	mv_mouse_x;
	int	mv_mouse_y;

	mlx_mouse_get_pos(scene->g_sys.mlx, &mv_mouse_x, &mv_mouse_y);
	if ((mv_mouse_x - WIN_HW) / 100 != 0 || (mv_mouse_y - WIN_HH) / 100 != 0)
		camera_rotation(&scene->cam, mv_mouse_x, mv_mouse_y);
	mlx_mouse_move(g_sys->mlx, g_sys->win, WIN_HW, WIN_HH);
}

void	key_hook_cam(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	camera_translation(&scene->cam, key);
}
