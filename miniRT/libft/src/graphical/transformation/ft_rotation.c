/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:18 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/03 14:03:27 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_vec3	ft_roll_rotation(const t_vec3 *p, double angle)
{
	t_vec3	new;

	new.x = p->x;
	new.y = p->y * cos(angle) + p->z * sin(angle);
	new.z = -p->y * sin(angle) + p->z * cos(angle);
	return (new);
}

t_vec3	ft_yaw_rotation(const t_vec3 *p, double angle)
{
	t_vec3	new;

	new.x = p->x * cos(angle) + p->y * sin(angle);
	new.y = -p->x * sin(angle) + p->y * cos(angle);
	new.z = p->z;
	return (new);
}

t_vec3	ft_pitch_rotation(const t_vec3 *p, double angle)
{
	t_vec3	new;

	new.x = p->x * cos(angle) - p->z * sin(angle);
	new.y = p->y;
	new.z = p->x * sin(angle) + p->z * cos(angle);
	return (new);
}

t_vec3	ft_rotation(const t_vec3 *p, const t_rotation *rotation)
{
	t_vec3	new;

	new = *p;
	if (fmod(rotation->roll, 2 * M_PI) != 0)
		new = ft_roll_rotation(&new, rotation->roll);
	if (fmod(rotation->pitch, 2 * M_PI) != 0)
		new = ft_pitch_rotation(&new, rotation->pitch);
	if (fmod(rotation->yaw, 2 * M_PI) != 0)
		new = ft_yaw_rotation(&new, rotation->yaw);
	return (new);
}

t_rotation	ft_rotation_create(double roll, double pitch, double yaw)
{
	t_rotation	rotation;

	rotation.roll = roll;
	rotation.pitch = pitch;
	rotation.yaw = yaw;
	return (rotation);
}
