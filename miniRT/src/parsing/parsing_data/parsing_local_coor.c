/// @todo header

#include "minirt.h"

/**
 * @brief Init local coordinates for translation and rotation of entities.
 * @param dir Forward direction.
 * @param right Right direction.
 * @param up Up direction.
 */
void	init_local_coordinates(t_vec3 *dir, t_vec3 *right, t_vec3 *up)
{
	t_vec3	up_wish;

	up_wish = ft_create_vec3(0, 1, 0);
	if (dir->x == 0 && dir->z == 0)
	{
		if (dir->y == 1)
			up_wish = ft_create_vec3(0, 0, -1);
		else if (dir->y == -1)
			up_wish = ft_create_vec3(0, 0, 1);
	}
	*right = ft_cross_vec3(&up_wish, dir);
	*up = ft_cross_vec3(dir, right);
}

/**
 * @brief Use for rotate on right.
 * @param dir Forward direction.
 * @param right Right direction.
 * @param up Up direction.
 * @param sign Positiv or negativ.
 */
void	rotation_on_right(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign)
{
	double	angle;

	angle = M_PI * ANGLE_ROTATION * sign;
	*dir = ft_rotation_quat(dir, angle, up);
	*right = ft_cross_vec3(up, dir);
}

/**
 * @brief Use for rotate on up.
 * @param dir Forward direction.
 * @param right Right direction.
 * @param up Up direction.
 * @param sign Positiv or negativ.
 */
void	rotation_on_up(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign)
{
	double	angle;

	angle = M_PI * ANGLE_ROTATION * sign;
	*dir = ft_rotation_quat(dir, angle, right);
	*up = ft_cross_vec3(dir, right);
}

/**
 * @brief Use for rotate on forward.
 * @param dir Forward direction.
 * @param right Right direction.
 * @param up Up direction.
 * @param sign Positiv or negativ.
 */
void	rotation_on_forward(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign)
{
	double	angle;

	angle = M_PI * ANGLE_ROTATION * sign;
	*right = ft_rotation_quat(right, angle, dir);
	*up = ft_cross_vec3(dir, right);
}
