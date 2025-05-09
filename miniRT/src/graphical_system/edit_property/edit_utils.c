/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:20 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:45:22 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
