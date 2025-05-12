/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:44:53 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/12 17:10:22 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Rotation on x and y (axe right and up).
 * @details Make a ratio of mouse move for create a director vector.
 */
static void	camera_rotation(t_cam *cam, double x, double y)
{
	double	angle;

	x = x / WIN_HW;
	if (x < 1 - EPSILON || x > 1 + EPSILON)
	{
		angle = M_PI * (x - 1) * SENSITIVITY;
		cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->up);
		cam->right = ft_cross_vec3(&cam->up, &cam->dir);
	}
	y = y / WIN_HW;
	if (y < 1 - EPSILON || y > 1 + EPSILON)
	{
		angle = -M_PI * (y - WIN_HH / WIN_HW) * SENSITIVITY;
		cam->dir = ft_rotation_quat(&cam->dir, angle, &cam->right);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
}

/**
 * @brief Rotation on axe dir (forward).
 */
static void	camera_rotation_key(t_cam *cam, int key)
{
	double	angle;

	if (key == SDL_SCANCODE_E)
	{
		angle = M_PI * 0.1 * SENSITIVITY;
		cam->right = ft_rotation_quat(&cam->right, angle, &cam->dir);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
	else if (key == SDL_SCANCODE_Q)
	{
		angle = -M_PI * 0.1 * SENSITIVITY;
		cam->right = ft_rotation_quat(&cam->right, angle, &cam->dir);
		cam->up = ft_cross_vec3(&cam->dir, &cam->right);
	}
}

/**
 * @brief Manages camera translation according to keyboard key.
 * @details W and S move to forward.
 * A and D move to left and right.
 * SPACE and F move toup and down.
 */
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
 * @brief Handle a mouse move.
 * @details When you move the mouse the camera rotate.
 */
void	mouse_event(t_scene *scene, t_graph_sys *g_sys)
{
	int	mv_mouse_x;
	int	mv_mouse_y;

	mlx_mouse_get_pos(scene->g_sys.mlx, &mv_mouse_x, &mv_mouse_y);
	camera_rotation(&scene->cam, mv_mouse_x, mv_mouse_y);
	mlx_mouse_move(g_sys->mlx, g_sys->win, WIN_HW, WIN_HH);
}

/**
 * @brief Manages camera movement.
 */
void	key_hook_cam(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	camera_rotation_key(&scene->cam, key);
	camera_translation(&scene->cam, key);
}
